################################################################################
#   OpenAirInterface
#   Copyright(c) 1999 - 2014 Eurecom
#
#    OpenAirInterface is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) anylater version.
#
#
#    OpenAirInterface is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with OpenAirInterface.The full GNU General Public License is
#    included in this distribution in the file called "COPYING". If not,
#    see <http://www.gnu.org/licenses/>.
#
#  Contact Information
#  OpenAirInterface Admin: openair_admin@eurecom.fr
#  OpenAirInterface Tech : openair_tech@eurecom.fr
#  OpenAirInterface Dev  : openair4g-devel@eurecom.fr
#
#  Address      : Eurecom, Campus SophiaTech, 450 Route des Chappes, CS 50193 - 06904 Biot Sophia Antipolis cedex, FRANCE
#
################################################################################
# file build_oai.bash
# brief
# author  Navid Nikaein 
# company Eurecom
# email:  navid.nikaein@eurecom.fr 
#

#!/bin/bash
################################
# include helper functions
################################
THIS_SCRIPT_PATH=$(dirname $(readlink -f $0))
. $THIS_SCRIPT_PATH/build_helper.bash

#####################
# create a bin dir
#####################
echo_warning "1. Creating the bin dir..." 
rm -rf bin
mkdir -m 777 -p bin 

build_date=`date +%Y_%m_%d`
oai_build_date="oai_built_${build_date}"
touch bin/${oai_build_date} 

################################
# cleanup first 
################################
echo_warning "2. Cleaning ..."

output=$($SUDO kill -9 `ps -ef | grep oaisim | awk '{print $2}'` )
$SUDO kill -9 `ps -ef | grep lte-softmodem | awk '{print $2}'`
$SUDO kill -9 `ps -ef | grep dlsim | awk '{print $2}'`
$SUDO kill -9 `ps -ef | grep ulsim | awk '{print $2}'`

#if [ $# -eq 0 ]; then 

if [ -z "$1" ]; then 
    echo "Build OAI"
else 
    if [ $1 = 0 ]; then 
	echo "Check the installation, and build OAI"
	rm -rf ./.lock_oaibuild
    fi 
fi
#######################################
# PARAMETERS
######################################

echo_warning "3. Setup the parameters"

HW="EXMIMO" # EXMIMO, USRP, NONE
TARGET="ALL" # ALL, SOFTMODEM, OAISIM, UNISIM, NONE

ENB_S1=1
REL="REL8" # REL8, REL10
RT="RTAI" # RTAI, RT_PREMPT or RT_DISABLED
DEBUG=0

ENB_CONFIG_FILE=$OPENAIR_TARGETS/"PROJECTS/GENERIC-LTE-EPC/CONF/enb.band7.conf"


OAI_TEST=0

# script is not currently handling these params
EPC=0 # flag to build EPC

XFORMS=0
ITTI_ANALYZER=0
VCD_TIMING=0
WIRESHARK=0
TIME_MEAS=0
DEV=0

EMULATION_DEV_INTERFACE="eth0"
EMULATION_MULTICAST_GROUP=1
EMULATION_DEV_ADDRESS=`ifconfig $EMULATION_DEV_INTERFACE | grep 'inet addr:'| grep -v '127.0.0.1' | cut -d: -f2 | awk '{ print $1}'`

#######################################
# Check the PARAMETERS
######################################

echo_success "Parameters :  HW=$HW, TARGET=$TARGET, ENB_S1=$ENB_S1, REL=$REL, RT=$RT, DEBUG=$DEBUG"
echo_success "ENB_CONFIG_FILE: $ENB_CONFIG_FILE"

echo "Parameters :  HW=$HW, TARGET=$TARGET, ENB_S1=$ENB_S1, REL=$REL, RT=$RT, DEBUG=$DEBUG" >> bin/${oai_build_date}
echo "ENB_CONFIG_FILE: $ENB_CONFIG_FILE" >>  bin/${oai_build_date}
 
############################################
# compilation directives 
############################################

echo_warning "4. building the compilation directives ..."

SOFTMODEM_DIRECTIVES="ENB_S1=$ENB_S1 DEBUG=$DEBUG XFORMS=$XFORMS "
OAISIM_DIRECTIVES="ENB_S1=$ENB_S1 DEBUG=$DEBUG XFORMS=$XFORMS "
if [ $HW = "USRP" ]; then 
    SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES USRP=1 "
fi
if [ $ENB_S1 -eq 0 ]; then 
    SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES NAS=1 "
    OAISIM_DIRECTIVES="$OAISIM_DIRECTIVES NAS=1 "
fi 
if [ $REL = "REL8" ]; then
    SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES Rel8=1 "
    OAISIM_DIRECTIVES="$OAISIM_DIRECTIVES Rel8=1 "
else 
    SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES Rel10=1 "
    OAISIM_DIRECTIVES="$OAISIM_DIRECTIVES Rel10=1 "
fi
if [ $RT = "RTAI" ]; then 
    if [ ! -f /usr/realtime/modules ];   then
	SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES HARD_RT=1 "
    else 
	echo_success "RTAI doesn't seem to be installed"
	RT="RT_PREMPT"
	SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES RTAI=0 "
    fi
fi

output=$(check_for_machine_type 2>&1) 
MACHINE_ARCH=$?
if [ $MACHINE_ARCH -eq 64 ]; then
    SOFTMODEM_DIRECTIVES="$SOFTMODEM_DIRECTIVES LIBCONFIG_LONG=1 "
    OAISIM_DIRECTIVES="$OASIM_DIRECTIVES LIBCONFIG_LONG=1 "
fi

echo_success "SOFTMODEM Compilation directive: $SOFTMODEM_DIRECTIVES"
echo_success "OAISIM Compilation directive:    $OAISIM_DIRECTIVES"

echo "SOFTMODEM Compilation directive: $SOFTMODEM_DIRECTIVES" >>  bin/${oai_build_date}
echo "OAISIM Compilation directive:    $OAISIM_DIRECTIVES" >>  bin/${oai_build_date}

############################################
# Printing OAI envs, we should check here
############################################


echo_warning "5. Checking the OAI PATHS... (TBD)"
cecho "OPENAIR_HOME    = $OPENAIR_HOME" $green
cecho "OPENAIR1_DIR    = $OPENAIR1_DIR" $green
cecho "OPENAIR2_DIR    = $OPENAIR2_DIR" $green
cecho "OPENAIR3_DIR    = $OPENAIR3_DIR" $green
cecho "OPENAIRCN_DIR   = $OPENAIRCN_DIR" $green
cecho "OPENAIR_TARGETS = $OPENAIR_TARGETS" $green


echo "OPENAIR_HOME    = $OPENAIR_HOME" >>  bin/${oai_build_date}
echo "OPENAIR1_DIR    = $OPENAIR1_DIR"  >>  bin/${oai_build_date}
echo "OPENAIR2_DIR    = $OPENAIR2_DIR"  >>  bin/${oai_build_date}
echo "OPENAIR3_DIR    = $OPENAIR3_DIR"  >>  bin/${oai_build_date}
echo "OPENAIRCN_DIR   = $OPENAIRCN_DIR"  >>  bin/${oai_build_date}
echo "OPENAIR_TARGETS = $OPENAIR_TARGETS"  >>  bin/${oai_build_date}

############################################
# check the installation
############################################

echo_warning "6. Checking the installation ..."

output=$(check_install_oai_software >>  $OPENAIR_TARGETS/bin/install_log.txt  2>&1 )


############################################
# compile 
############################################

echo_warning "7. compiling and installing the OAI binaries..."

softmodem_compiled=1
oaisim_compiled=1
unisim_compiled=1

if [ $TARGET = "ALL" ]; then
    output=$(compile_ltesoftmodem >> $OPENAIR_TARGETS/bin/install_log.txt  2>&1 )
    softmodem_compiled=$?
    check_for_ltesoftmodem_executable
    
    output=$(compile_oaisim  >> $OPENAIR_TARGETS/bin/install_log.txt  2>&1 )
    oaisim_compiled=$?
    check_for_oaisim_executable

    output=$(compile_unisim  >> $OPENAIR_TARGETS/bin/install_log.txt  2>&1 )
    unisim_compiled=$?
    check_for_dlsim_executable
    check_for_ulsim_executable
    check_for_pucchsim_executable
    check_for_prachsim_executable
    check_for_pdcchsim_executable
    check_for_pbchsim_executable
    check_for_mbmssim_executable
    
else
    
    if [ $TARGET = "SOFTMODEM" ]; then 
	output=$(compile_ltesoftmodem  >> $OPENAIR_TARGETS/bin/install_log.txt 2>&1 )
	softmodem_compiled=$?
	check_for_ltesoftmodem_executable
    fi
    if [ $TARGET = "OAISIM" ]; then 
	output=$(compile_oaisim  >> $OPENAIR_TARGETS/bin/install_log.txt 2>&1 )
	oaisim_compiled=$?	
	check_for_oaisim_executable
    fi
    if [ $TARGET = "UNISIM" ]; then 
	output=$(compile_unisim  >> $OPENAIR_TARGETS/bin/install_log.txt 2>&1 )
	unisim_compiled=$?
	check_for_dlsim_executable
	check_for_ulsim_executable
	check_for_pucchsim_executable
	check_for_prachsim_executable
	check_for_pdcchsim_executable
	check_for_pbchsim_executable
	check_for_mbmssim_executable
    fi
fi


############################################
# install 
############################################

echo_warning "8. Installing ..."

if [ $softmodem_compiled = 0 ]; then 
    echo "target lte-softmodem built "
    echo "target lte-softmodem built "  >>  bin/${oai_build_date}
    install_ltesoftmodem $RT $ENB_S1
fi
if [ $oaisim_compiled = 0 ]; then 
    echo "target oaisim built "
    echo "target oaisim built "  >>  bin/${oai_build_date}
    install_oaisim $ENB_S1 
fi 
if [ $unisim_compiled =  0 ]; then 
    echo "target unisim built "
    echo "target unisim built "  >>  bin/${oai_build_date}
fi 

echo "build terminated, see logs is $OPENAIR_TARGETS/bin/install_log.txt"


   

############################################
# testing
############################################

if [ $OAI_TEST = 1 ]; then 
    echo_warning "9. Testing ..."
    python $OPENAIR_TARGETS/TEST/OAI/test01.py
else 
    echo_warning "9. Bypassing the Tests ..."
fi 
 




