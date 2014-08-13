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
  
  Address      : Eurecom, Compus SophiaTech 450, route des chappes, 06451 Biot, France.

 *******************************************************************************/
/* Automatically generated based on softconfig.h from Grlib . Don't edit. */
/* Tue Mar 11 18:31:32 CET 2008 */

#ifndef FROM_GRLIB_SOFT_CONFIG_H
#define SOFT_CONFIG_H

/* Sparc features */
#define FROM_GRLIB_CFG_NWIN 8

/* Clock */
#define FROM_GRLIB_CFG_INCLK_FREQ_HZ        26000000
#define FROM_GRLIB_CFG_CLKMUL               2
#define FROM_GRLIB_CFG_CLKDIV               1
#define FROM_GRLIB_CFG_MAINCLK_FREQ_HZ      52000000
#define FROM_GRLIB_CFG_MAINCLK_PERIOD_PS    19230

/* AMBA config */
#define FROM_GRLIB_CFG_AHBIO          0xFFF00000
#define FROM_GRLIB_CFG_AHBRODDR       0x00000000
#define FROM_GRLIB_CFG_AHBROM_MAXSZ   1
#define FROM_GRLIB_CFG_APBADDR        0x80000000
#define FROM_GRLIB_CFG_ACTUAL_HIGHEST_HINDEX 9

/* General Purpose I/O */
#define FROM_GRLIB_CFG_GRGPIO_PADDR            0x80000b00
#define FROM_GRLIB_CFG_GRGPIO_OUTPUT           0x80000b04
#define FROM_GRLIB_CFG_GRGPIO_DIRECTION        0x80000b08
#define FROM_GRLIB_CFG_GRGPIO_IRQ_MASK         0x80000b0c
#define FROM_GRLIB_CFG_GRGPIO_IRQ_POLARITY     0x80000b10
#define FROM_GRLIB_CFG_GRGPIO_IRQ_EDGE         0x80000b14

/* Instruction cache local RAM */
#define FROM_GRLIB_CFG_ILRAMEN
#define FROM_GRLIB_CFG_ILRAMADDR     0x8e000000
#define FROM_GRLIB_CFG_ILRAMADDR_TOP 0x8e008000
#define FROM_GRLIB_CFG_ILRAMSZ       32

/* Data cache local RAM */
#define FROM_GRLIB_CFG_DLRAMEN
#define FROM_GRLIB_CFG_DLRAMADDR     0x8f000000
#define FROM_GRLIB_CFG_DLRAMADDR_TOP 0x8f008000
#define FROM_GRLIB_CFG_DLRAMSZ       32

/* AHB RAM */
#define FROM_GRLIB_CFG_AHBRAMEN
#define FROM_GRLIB_CFG_AHBRADDR     0x00000000
#define FROM_GRLIB_CFG_AHBRADDR_TOP 0x00001000
#define FROM_GRLIB_CFG_AHBRSZ       4

/* SDRAM */
#define FROM_GRLIB_CFG_SDCTRL
#define FROM_GRLIB_CFG_SDRAM_ADDR   0x60000000
#define FROM_GRLIB_CFG_SDRAM_TOP    0x62000000
#define FROM_GRLIB_CFG_SDRAMSZ      32
#define FROM_GRLIB_CFG_SDRAM_IO     0xFFF00100

/* Scaler and timers */
#define FROM_GRLIB_CFG_SCALER_VALUE     0x80000300
#define FROM_GRLIB_CFG_SCALER_RELOAD    0x80000304
#define FROM_GRLIB_CFG_SCALER_CONFIG    0x80000308
#define FROM_GRLIB_CFG_TIMER1_COUNTER   0x80000310
#define FROM_GRLIB_CFG_TIMER1_RELOAD    0x80000314
#define FROM_GRLIB_CFG_TIMER1_CONTROL   0x80000318
#define FROM_GRLIB_CFG_GPT_IRQ          8
#define ONE_TICK_PER_MICROS  51

/* Interrupt Requests */
#define FROM_GRLIB_CFG_IRQ_LEVEL      0x80000200
#define FROM_GRLIB_CFG_IRQ_PENDING    0x80000204
#define FROM_GRLIB_CFG_IRQ_CLEAR      0x8000020c
#define FROM_GRLIB_CFG_IRQ_CPU0_MASK  0x80000240
#define FROM_GRLIB_CFG_IRQ_CPU0_FORCE 0x80000208

/* PCI interface */
#define FROM_GRLIB_CFG_PCI                     3
#define FROM_GRLIB_CFG_PCIVID                  0x16E3
#define FROM_GRLIB_CFG_PCIDID                  0x0210
#define FROM_GRLIB_CFG_PCI_HADDR               0xE0000000
#define FROM_GRLIB_CFG_GRPCI_CONFIG_STATUS     0x80000400
#define FROM_GRLIB_CFG_GRPCI_BAR0              0x80000404
#define FROM_GRLIB_CFG_GRPCI_PAGE0             0x80000408
#define FROM_GRLIB_CFG_GRPCI_BAR1              0x8000040c
#define FROM_GRLIB_CFG_GRPCI_PAGE1             0x80000410
#define FROM_GRLIB_CFG_GRPCI_IOMAP             0x80000414
#define FROM_GRLIB_CFG_GRPCI_STATUS_COMMAND    0x80000418
/* added by Eurecom */
  /* These definitions are for Leon3 firmware */
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL          0x80000420
#define FROM_GRLIB_CFG_GRPCI_EUR_EXPPAGE0      0x80000428
#define FROM_GRLIB_CFG_GRPCI_EUR_SHARED0OFF    0x80000430
#define FROM_GRLIB_CFG_GRPCI_EUR_SHARED0SIZE   0x80000434
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL0         0x80000440
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL1         0x80000444
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL2         0x80000448
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL3         0x8000044c
  /* These ones are for Host PC software */
#define FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE   0x40
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL0_OFFSET  (FROM_GRLIB_CFG_GRPCI_EUR_CTRL0 - FROM_GRLIB_CFG_GRPCI_EUR_CTRL + FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE)
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL1_OFFSET  (FROM_GRLIB_CFG_GRPCI_EUR_CTRL1 - FROM_GRLIB_CFG_GRPCI_EUR_CTRL + FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE)
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL2_OFFSET  (FROM_GRLIB_CFG_GRPCI_EUR_CTRL2 - FROM_GRLIB_CFG_GRPCI_EUR_CTRL + FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE)
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL3_OFFSET  (FROM_GRLIB_CFG_GRPCI_EUR_CTRL3 - FROM_GRLIB_CFG_GRPCI_EUR_CTRL + FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE)
#define FROM_GRLIB_CFG_GRPCI_EUR_CTRL_OFFSET   (FROM_GRLIB_CFG_GRPCI_EUR_CTRL  - FROM_GRLIB_CFG_GRPCI_EUR_CTRL + FROM_GRLIB_CFG_GRPCI_PCI_CONFIG_FREE)
#define FROM_GRLIB_CFG_PCI_IRQ                 5
/* PCI DMA controller */
#define FROM_GRLIB_CFG_PCIDMA_CTRL             0x80000500
#define FROM_GRLIB_CFG_PCIDMA_AHB_ADDR         0x80000504
#define FROM_GRLIB_CFG_PCIDMA_PCI_ADDR         0x80000508
#define FROM_GRLIB_CFG_PCIDMA_NB_WORDS         0x8000050c
#define FROM_GRLIB_CFG_PCIDMA_IRQ              4

/* Cardbus MIMO 1 Features */
#define FROM_GRLIB_CFG_CMIMO1_ENABLE
/* Address mapping of RF chain control Register file */
#define FROM_GRLIB_CFG_CMIMO1_WDNS_RFCTL0      0xFFF20000
#define FROM_GRLIB_CFG_CMIMO1_WDNS_RFCTL1      0xFFF20004
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_RFCTL    0xFFF20008
/* Address mapping of ADAC control Register file */
#define FROM_GRLIB_CFG_CMIMO1_ADAC_CONFIG        0xFFF20020
#define FROM_GRLIB_CFG_CMIMO1_FRAME_LENGTH       0xFFF20024
#define FROM_GRLIB_CFG_CMIMO1_FRAME_START        0xFFF20028
#define FROM_GRLIB_CFG_CMIMO1_SWITCH_OFFSET      0xFFF2002c
#define FROM_GRLIB_CFG_CMIMO1_ADAC_INTR_COUNTER  0xFFF20030
/* Address mapping of Widens SPI control/config Register file */
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA0   0xFFF20040
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA1   0xFFF20044
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA2   0xFFF20048
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA3   0xFFF2004c
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA4   0xFFF20050
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA5   0xFFF20054
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA6   0xFFF20058
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_DATA7   0xFFF2005c
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_ENABLES 0xFFF20060
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_SIZES   0xFFF20064
#define FROM_GRLIB_CFG_CMIMO1_WDNS_SPI_ACTIVE  0xFFF20068
/* Address mapping of Idromel SPI control/config Register file */
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_ADF14108_FUNC  0xFFF20080
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_ADF14108_NCNT  0xFFF20084
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_ADF14108_RCNT  0xFFF20088
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_LFSW_CMD       0xFFF20090
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_LFSW_KHZ_0     0xFFF20094
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_LFSW_KHZ_1     0xFFF20098
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_SETTX          0xFFF200A0
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_SETRX          0xFFF200A4
#define FROM_GRLIB_CFG_CMIMO1_IDROMEL_SPI_CTRL           0xFFF200B0
/* Address mapping of ADAC ram banks */
#define FROM_GRLIB_CFG_CMIMO1_ADC0             0xC0000000
#define FROM_GRLIB_CFG_CMIMO1_ADC0_TOP         0xC0000FFF
#define FROM_GRLIB_CFG_CMIMO1_ADC0_SZKB        4
#define FROM_GRLIB_CFG_CMIMO1_ADC1             0xC0010000
#define FROM_GRLIB_CFG_CMIMO1_ADC1_TOP         0xC0010FFF
#define FROM_GRLIB_CFG_CMIMO1_ADC1_SZKB        4
#define FROM_GRLIB_CFG_CMIMO1_DAC0             0xC0020000
#define FROM_GRLIB_CFG_CMIMO1_DAC0_TOP         0xC00207FF
#define FROM_GRLIB_CFG_CMIMO1_DAC0_SZKB        2
#define FROM_GRLIB_CFG_CMIMO1_DAC1             0xC0030000
#define FROM_GRLIB_CFG_CMIMO1_DAC1_TOP         0xC00307FF
#define FROM_GRLIB_CFG_CMIMO1_DAC1_SZKB        2
#define FROM_GRLIB_CFG_CMIMO1_IRQ              6

#endif /* FROM_GRLIB_SOFT_CONFIG_H */
