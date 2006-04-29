/*
 * $Id$
 *  
 * Copyright (C) 2003 Pascal Brisset, Antoine Drouin
 *
 * This file is part of paparazzi.
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, write to
 * the Free Software Foundation, 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA. 
 *
 */

#ifndef LINK_MCU_H
#define LINK_MCU_H

#include <inttypes.h>
#include "link_mcu_hw.h"
#include "inter_mcu.h"

struct link_mcu_msg {
  union  { 
    struct fbw_state from_fbw; 
    struct ap_state  from_ap;
  } payload;
  uint16_t checksum;
};

extern struct link_mcu_msg link_mcu_from_ap_msg;
extern struct link_mcu_msg link_mcu_from_fbw_msg;

extern volatile uint8_t link_mcu_tx_idx;
extern volatile uint8_t link_mcu_rx_idx;

#ifdef FBW

extern volatile bool_t link_mcu_is_busy;
extern volatile bool_t link_mcu_was_busy;

extern void link_mcu_restart(void);

#endif /* FBW */

#ifdef AP

extern volatile uint8_t link_fbw_nb_err;
extern uint8_t link_fbw_fbw_nb_err;

extern void link_fbw_init(void);
extern void link_fbw_send(void);

#endif /* AP */

#endif
