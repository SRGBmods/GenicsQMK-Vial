// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define VIAL_KEYBOARD_UID \
    { 0x2B, 0x3C, 0x7E, 0x52, 0x60, 0x3E, 0xFE, 0x52 }

/* VIAL secure unlock keystroke - currently both inner thumb keys (typ. SPACE/ENTER) */
#define VIAL_UNLOCK_COMBO_ROWS \
    { 0, 6 }
#define VIAL_UNLOCK_COMBO_COLS \
    { 0, 0 }

#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define VIAL_COMBO_ENTRIES 20
#define DYNAMIC_KEYMAP_MACRO_COUNT 50


#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_HID_SYNC, RPC_ID_USER_CAPS_WORD_SYNC, RPC_ID_USER_LAYER_SYNC
