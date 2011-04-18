#define RLC_AM_MODULE
#define RLC_AM_INIT_C
//-----------------------------------------------------------------------------
#include <string.h>
//-----------------------------------------------------------------------------
#include "rlc_am.h"
#include "LAYER2/MAC/extern.h"
//-----------------------------------------------------------------------------
void rlc_am_init(rlc_am_entity_t *rlcP)
//-----------------------------------------------------------------------------
{
    memset(rlcP, 0, sizeof(rlc_am_entity_t));

    list2_init(&rlcP->receiver_buffer,      "RX BUFFER");
    list_init(&rlcP->pdus_to_mac_layer,     "PDUS TO MAC");
    list_init(&rlcP->control_pdu_list,      "CONTROL PDU LIST");
    list_init(&rlcP->segmentation_pdu_list, "SEGMENTATION PDU LIST");

    // TX state variables
    rlcP->vt_a    = 0;
    rlcP->vt_ms   = rlcP->vt_a + RLC_AM_WINDOW_SIZE;
    rlcP->vt_s    = 0;
    rlcP->poll_sn = 0;
    // TX counters
    rlcP->c_pdu_without_poll  = 0;
    rlcP->c_byte_without_poll = 0;
    // RX state variables
    rlcP->vr_r    = 0;
    rlcP->vr_mr   = rlcP->vr_r + RLC_AM_WINDOW_SIZE;
    rlcP->vr_x    = 0;
    rlcP->vr_ms   = 0;
    rlcP->vr_h    = 0;

    rlcP->last_frame_status_indication = 123456; // any value > 1
    rlcP->first_retrans_pdu_sn         = -1;
}
//-----------------------------------------------------------------------------
void rlc_am_cleanup(rlc_am_entity_t *rlcP)
//-----------------------------------------------------------------------------
{

    list2_free(&rlcP->receiver_buffer);
    list_free(&rlcP->pdus_to_mac_layer);
    list_free(&rlcP->control_pdu_list);
    list_free(&rlcP->segmentation_pdu_list);


    if (rlcP->output_sdu_in_construction != NULL) {
        free_mem_block(rlcP->output_sdu_in_construction);
        rlcP->output_sdu_in_construction = NULL;
    }
    unsigned int i;
    for (i=0; i < RLC_AM_SDU_CONTROL_BUFFER_SIZE; i++) {
        if (rlcP->input_sdus[i].mem_block != NULL) {
            free_mem_block(rlcP->input_sdus[i].mem_block);
            rlcP->input_sdus[i].mem_block = NULL;
        }
    }
    for (i=0; i < RLC_AM_PDU_RETRANSMISSION_BUFFER_SIZE; i++) {
        if (rlcP->pdu_retrans_buffer[i].mem_block != NULL) {
            free_mem_block(rlcP->pdu_retrans_buffer[i].mem_block);
            rlcP->pdu_retrans_buffer[i].mem_block = NULL;
        }
    }
}
//-----------------------------------------------------------------------------
void rlc_am_configure(rlc_am_entity_t *rlcP,
                      u16_t max_retx_thresholdP,
                      u16_t poll_pduP,
                      u16_t poll_byteP,
                      u32_t t_poll_retransmitP,
                      u32_t t_reorderingP,
                      u32_t t_status_prohibitP)
//-----------------------------------------------------------------------------
{
    msg ("\n\n\n[FRAME %05d][RLC_AM][MOD %02d][RB %02d][CONFIGURE] max_retx_threshold %d poll_pdu %d poll_byte %d t_poll_retransmit %d t_reordering %d t_status_prohibit %d\n", mac_xface->frame, rlcP->module_id, rlcP->rb_id, max_retx_thresholdP, poll_pduP, poll_byteP, t_poll_retransmitP, t_reorderingP, t_status_prohibitP);

    rlcP->max_retx_threshold = max_retx_thresholdP;
    rlcP->poll_pdu           = poll_pduP;
    rlcP->poll_byte          = poll_byteP;
    rlcP->protocol_state     = RLC_DATA_TRANSFER_READY_STATE;

    rlc_am_init_timer_poll_retransmit(rlcP, t_poll_retransmitP);
    rlc_am_init_timer_reordering     (rlcP, t_reorderingP);
    rlc_am_init_timer_status_prohibit(rlcP, t_status_prohibitP);
}
//-----------------------------------------------------------------------------
void rlc_am_set_debug_infos(rlc_am_entity_t *rlcP, module_id_t module_idP, rb_id_t rb_idP, rb_type_t rb_typeP)
//-----------------------------------------------------------------------------
{
    rlcP->module_id = module_idP;
    rlcP->rb_id     = rb_idP;
    if (rb_typeP != SIGNALLING_RADIO_BEARER) {
      rlcP->is_data_plane = 1;
    } else {
      rlcP->is_data_plane = 0;
    }
}
