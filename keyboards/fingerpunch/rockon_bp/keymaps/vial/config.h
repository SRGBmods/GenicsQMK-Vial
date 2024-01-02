/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0x07, 0x74, 0x87, 0xC6, 0x10, 0xE3, 0xBD, 0xCB}

#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define TAP_CODE_DELAY 25

#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING

#define TAPPING_FORCE_HOLD
