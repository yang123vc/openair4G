/*******************************************************************************

  Eurecom OpenAirInterface
  Copyright(c) 1999 - 2013 Eurecom

  This program is free software; you can redistribute it and/or modify it
  under the terms and conditions of the GNU General Public License,
  version 2, as published by the Free Software Foundation.

  This program is distributed in the hope it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
  more details.

  You should have received a copy of the GNU General Public License along with
  this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.

  The full GNU General Public License is included in this distribution in
  the file called "COPYING".

  Contact Information
  Openair Admin: openair_admin@eurecom.fr
  Openair Tech : openair_tech@eurecom.fr
  Forums       : http://forums.eurecom.fr/openairinterface
  Address      : EURECOM, Campus SophiaTech, 450 Route des Chappes
                 06410 Biot FRANCE

*******************************************************************************/

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <signal.h>
#include <time.h>
#include <errno.h>

#include "intertask_interface.h"
#include "assertions.h"
#include "timer.h"
#include "backtrace.h"

#include "signals.h"

sigset_t set;

int signal_init(void)
{
    /* We set the signal mask to avoid threads other than the main thread
     * to receive the timer signal. Note that threads created will inherit this
     * configuration.
     */
    sigemptyset(&set);

    sigaddset (&set, SIGTIMER);
    sigaddset (&set, SIGABRT);
    sigaddset (&set, SIGSEGV);
    sigaddset (&set, SIGINT);

    if (sigprocmask(SIG_BLOCK, &set, NULL) < 0) {
        perror ("sigprocmask");
        return -1;
    }

    return 0;
}

extern int timer_handle_signal(siginfo_t *info);

int signal_handle(void)
{
    int ret;
    siginfo_t info;

    sigemptyset(&set);

    sigaddset (&set, SIGTIMER);
    sigaddset (&set, SIGABRT);
    sigaddset (&set, SIGSEGV);
    sigaddset (&set, SIGINT);

    if (sigprocmask(SIG_BLOCK, &set, NULL) < 0) {
        perror ("sigprocmask");
        return -1;
    }

    /* Block till a signal is received.
     * NOTE: The signals defined by set are required to be blocked at the time
     * of the call to sigwait() otherwise sigwait() is not successful.
     */
    if ((ret = sigwaitinfo(&set, &info)) == -1) {
        perror ("sigwait");
        return ret;
    }

//     printf("Received signal %d\n", info.si_signo);

    /* Real-time signals are non constant and are therefore not suitable for
     * use in switch.
     */
    if (info.si_signo == SIGTIMER) {
        timer_handle_signal(&info);
    } else {
        /* Dispatch the signal to sub-handlers */
        switch(info.si_signo) {
            case SIGSEGV:   /* Fall through */
            case SIGABRT:
                printf("Received SIGABORT\n");
                backtrace_handle_signal(&info);
                break;
            case SIGQUIT:
            case SIGINT:
                printf("Received SIGINT\n");
                intertask_interface_send_quit_signal();
                printf("All tasks terminated -> exiting '"PACKAGE_NAME"'\n");
                exit(0);
                break;
            default:
                printf("Received unknown signal %d\n", info.si_signo);
                break;
        }
    }

    return 0;
}