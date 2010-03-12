/* file: pss.c
   purpose: generate the primary synchronization signals of LTE
   author: florian.kaltenberger@eurecom.fr, oscar.tonelli@yahoo.it
   date: 21.10.2009 
*/

//#include "defs.h"
#include "PHY/defs.h"
#include "PHY/extern.h"

/*
typedef struct {
  unsigned char N_RB_DL;
  unsigned char Nid_cell;
  unsigned char Ncp;
  unsigned char nushift;
  unsigned short ofdm_symbol_size;
  unsigned char log2_symbol_size;
  unsigned short nb_prefix_samples;
  unsigned short first_carrier_offset;
  unsigned int samples_per_tti;
  unsigned char nb_antennas_tx;
  unsigned char nb_antennas_rx;
  unsigned char first_dlsch_symbol;
  short *twiddle_fft;
  unsigned short *rev;
} LTE_DL_FRAME_PARMS;
*/

int generate_pss(mod_sym_t **txdataF,
		 short amp,
		 LTE_DL_FRAME_PARMS *frame_parms,
		 unsigned short eNb_id,
		 unsigned short symbol,
		 unsigned short slot_offset) {

  unsigned int Nsymb;
  unsigned short k,m;
#ifdef IFFT_FPGA
  unsigned char *primary_sync_tab;
#else
  short *primary_sync;
#endif

  //msg("[PSS] Using sequence %d\n",eNb_id);


  switch (eNb_id) {
  case 0:
#ifdef IFFT_FPGA
    primary_sync_tab = primary_synch0_tab;
#else
    primary_sync = primary_synch0;
#endif
    break;
  case 1:
#ifdef IFFT_FPGA
    primary_sync_tab = primary_synch1_tab;
#else
    primary_sync = primary_synch1;
#endif
    break;
  case 2:
#ifdef IFFT_FPGA
    primary_sync_tab = primary_synch2_tab;
#else
    primary_sync = primary_synch2;
#endif
    break;
  default:
    msg("[PSS] eNb_id has to be 0,1,2\n");
    return(-1);
  }

  //a = (amp*ONE_OVER_SQRT2_Q15)>>15;
  //printf("[PSS] amp=%d, a=%d\n",amp,a);

  Nsymb = (frame_parms->Ncp==0)?14:12;

  // The PSS occupies the inner 6 RBs, which start at
#ifdef IFFT_FPGA
  k = (frame_parms->N_RB_DL-3)*12+5;
#else
  k = frame_parms->ofdm_symbol_size-3*12+5;
#endif
  //printf("[PSS] k = %d\n",k);
  for (m=5;m<67;m++) {
#ifdef IFFT_FPGA
    txdataF[0][slot_offset*Nsymb/2*frame_parms->N_RB_DL*12 + symbol*frame_parms->N_RB_DL*12 + k] = primary_sync_tab[m];
#else
    ((short*)txdataF[0])[2*(slot_offset*Nsymb/2*frame_parms->ofdm_symbol_size +
			    symbol*frame_parms->ofdm_symbol_size + k)] = 
      (amp * primary_sync[2*m]) >> 15; 
    ((short*)txdataF[0])[2*(slot_offset*Nsymb/2*frame_parms->ofdm_symbol_size +
			    symbol*frame_parms->ofdm_symbol_size + k) + 1] = 
      (amp * primary_sync[2*m+1]) >> 15;
#endif	
    k+=1;
#ifdef IFFT_FPGA
    if (k >= frame_parms->N_RB_DL*12) 
      k-=frame_parms->N_RB_DL*12;
#else
    if (k >= frame_parms->ofdm_symbol_size) {
      k++; //skip DC
      k-=frame_parms->ofdm_symbol_size;
    }
#endif
  }
  return(0);
}
