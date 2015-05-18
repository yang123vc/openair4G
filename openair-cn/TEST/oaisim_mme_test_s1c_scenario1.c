/*******************************************************************************
    OpenAirInterface
    Copyright(c) 1999 - 2014 Eurecom

    OpenAirInterface is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.


    OpenAirInterface is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenAirInterface.The full GNU General Public License is
    included in this distribution in the file called "COPYING". If not,
    see <http://www.gnu.org/licenses/>.

   Contact Information
   OpenAirInterface Admin: openair_admin@eurecom.fr
   OpenAirInterface Tech : openair_tech@eurecom.fr
   OpenAirInterface Dev  : openair4g-devel@eurecom.fr

   Address      : Eurecom, Campus SophiaTech, 450 Route des Chappes, CS 50193 - 06904 Biot Sophia Antipolis cedex, FRANCE

*******************************************************************************/
#include "oaisim_mme_test_s1c_scenario.h"


// Description succesfull attach of UE, release UE.

s1ap_test_t s1ap_scenario1[] = {
  {
    .procedure_name = "id-initialUEMessage",
    .buffer = {
    		0x00, 0x0C,
    		0x00, 0x5C, 0x00, 0x00, 0x05, 0x00, 0x08, 0x00, 0x04, 0x80, 0x06, 0x69, 0x2D, 0x00, 0x1A, 0x00,
    		0x32, 0x31, 0x07, 0x41, 0x71, 0x08, 0x29, 0x80, 0x39, 0x00, 0x00, 0x00, 0x00, 0x10, 0x02, 0xE0,
    		0xE0, 0x00, 0x20, 0x02, 0x01, 0xD0, 0x11, 0x27, 0x1A, 0x80, 0x80, 0x21, 0x10, 0x01, 0x00, 0x00,
    		0x10, 0x81, 0x06, 0x00, 0x00, 0x00, 0x00, 0x83, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x00,
    		0x00, 0x0A, 0x00, 0x00, 0x43, 0x00, 0x06, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x01, 0x00, 0x64, 0x40,
    		0x08, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x86, 0x40, 0x01, 0x30
    },
    .dont_check = {
    		-1
    },
    .buf_len = 96,
    .originating = ENB,
  },
  {
    .procedure_name = "id-downlinkNASTransport, Authentication request",
    .buffer = {
    		0x00, 0x0B,
    		0x00, 0x3D, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0xC0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x00, 0x04, 0x80, 0x06, 0x69, 0x2D, 0x00, 0x1A, 0x00, 0x25, 0x24, 0x07, 0x52, 0x00, 0xD3, 0xB5,
    		0xF0, 0x89, 0x68, 0x02, 0x66, 0x5A, 0x08, 0xE6, 0x51, 0xC7, 0x29, 0x6B, 0x4D, 0xA0, 0x10, 0xDD,
    		0x04, 0x53, 0xC8, 0x3F, 0x94, 0x80, 0x00, 0x03, 0xAF, 0x2F, 0x49, 0xF3, 0xC8, 0x38, 0x90, 0x00,
    		0x00, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 65,
    .originating = MME,
  },
  {
    .procedure_name = "id-uplinkNASTransport, 0xAuthentication response",
    .buffer = {
    		0x00, 0x0d,
    		0x40, 0x3a, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x00, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x1a, 0x00, 0x0C, 0x0b, 0x07, 0x53, 0x08, 0x11, 0x82,
    		0x98, 0x98, 0x3b, 0xca, 0xF2, 0x97, 0x00, 0x64, 0x40, 0x08, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x00,
    		0xe0, 0x00, 0x00, 0x43, 0x40, 0x06, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x01, 0x00, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 62,
    .originating = ENB,
  },
  {
    .procedure_name = "id-downlinkNASTransport, Security mode command",
    .buffer = {
    		0x00, 0x0b,
    		0x00, 0x26, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x00, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x1a, 0x00, 0x0e, 0x0d, 0x37, 0xFC, 0xc1, 0xda, 0xd9,
    		0x00, 0x07, 0x5d, 0x02, 0x00, 0x02, 0xe0, 0xe0, 0x00, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 42,
    .originating = MME,
  },
  {
    .procedure_name = "id-uplinkNASTransport, Security mode complete",
    .buffer = {
    		0x00, 0x0d,
    		0x40, 0x37, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x00, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x1a, 0x00, 0x09, 0x08, 0x47, 0x1d, 0xd0, 0xbb, 0xad,
    		0x00, 0x07, 0x5e, 0x00, 0x64, 0x40, 0x08, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x00, 0xe0, 0x00, 0x00,
    		0x43, 0x40, 0x06, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x01, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 59,
    .originating = ENB,
  },
  {
    .procedure_name = "id-InitialContextSetup, InitialContextSetupRequest , Attach accept, Activate default EPS bearer context request",
    .buffer = {
    		0x00, 0x09,
    		0x00, 0x80, 0xba, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00,
    		0x08, 0x00, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x42, 0x00, 0x0a, 0x18, 0x05, 0xF5, 0xe1, 0x00,
    		0x60, 0x02, 0xFa, 0xF0, 0x80, 0x00, 0x18, 0x00, 0x67, 0x00, 0x00, 0x34, 0x00, 0x62, 0x45, 0x00,
    		0x09, 0x04, 0x0f, 0x80, 0x7f, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x53, 0x27, 0x8b, 0xe6,
    		0x60, 0xb5, 0x01, 0x07, 0x42, 0x01, 0x4a, 0x06, 0x20, 0x02, 0xF8, 0x39, 0x00, 0x01, 0x00, 0x31,
    		0x52, 0x01, 0xc1, 0x01, 0x09, 0x09, 0x03, 0x6f, 0x61, 0x69, 0x04, 0x69, 0x70, 0x76, 0x34, 0x05,
    		0x01, 0xc0, 0xbb, 0x00, 0x02, 0x5e, 0x04, 0xFe, 0xFe, 0xde, 0x9e, 0x27, 0x14, 0x80, 0x80, 0x21,
    		0x10, 0x03, 0x00, 0x00, 0x10, 0x81, 0x06, 0xc0, 0xa8, 0x0C, 0x64, 0x83, 0x06, 0xc0, 0xa8, 0x6a,
    		0x0C, 0x50, 0x0b, 0xF6, 0x02, 0xF8, 0x39, 0x80, 0x00, 0x01, 0x78, 0x00, 0x0C, 0x20, 0x17, 0x2C,
    		0x00, 0x6b, 0x00, 0x05, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x49, 0x00, 0x20, 0xFa, 0x59, 0x15,
    		0x4e, 0x32, 0x95, 0x04, 0x2d, 0x35, 0xa4, 0x47, 0xc3, 0x80, 0xab, 0x63, 0xd8, 0xe6, 0x91, 0x83,
    		0x6C, 0x9a, 0xF0, 0xed, 0x85, 0x38, 0xa8, 0x27, 0x41, 0x6b, 0x2b, 0x64, 0x86, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 191,
    .originating = MME,
  },
  {
    .procedure_name = "id-UECapabilityInfoIndication",
    .buffer = {
    		0x00, 0x16,
    		0x40, 0x2C, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x00, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x4a, 0x40, 0x14, 0x13, 0x81, 0x20, 0x00, 0x03, 0x00,
    		0x10, 0x60, 0xe0, 0xc1, 0xF8, 0x3f, 0x07, 0xe0 ,0xfd, 0x78, 0x37, 0x62, 0x00, 0x00
    },
    .dont_check = {
    		-1
    },
    .buf_len = 48,
    .originating = ENB,
  },
  {
    .procedure_name = "id-InitialContextSetup, InitialContextSetupResponse ",
    .buffer = {
    		0x20, 0x09,
    		0x00, 0x27, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08,
    		0x40, 0x04, 0x80, 0x06, 0x69, 0x2d, 0x00, 0x33, 0x40, 0x0f, 0x00, 0x00, 0x32, 0x40, 0x0a, 0x0a,
    		0x1f, 0x7f, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01
    },
    .dont_check = {
    		-1
    },
    .buf_len = 64,
    .originating = ENB,
  },
  {
    .procedure_name = "id-uplinkNASTransport, Attach complete, Activate default EPS bearer context accept",
    .buffer = {

    		0x00, 0x0d,
    		0x05, 0x00, 0x00, 0x00, 0x05, 0xc0, 0x80, 0x00, 0x15, 0x20, 0x00, 0x08, 0x00, 0x04, 0x80, 0x06,
    		0x69, 0x2d, 0x00, 0x1a, 0x00, 0x0e, 0x0d, 0x27, 0xc7, 0x8f, 0x5a, 0xd2, 0x01, 0x07, 0x43, 0x00,
    		0x03, 0x52, 0x00, 0xc2, 0x00, 0x64, 0x40, 0x08, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x00, 0xe0, 0x00,
    		0x00, 0x43, 0x40, 0x06, 0x00, 0x02, 0xF8, 0x39, 0x00, 0x01
    },
    .dont_check = {
    		-1
    },
    .buf_len = 64,
    .originating = ENB,
  }
};
