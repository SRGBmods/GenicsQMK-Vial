/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0xDC, 0xDB, 0x44, 0xE3, 0x5B, 0x15, 0x0E, 0x96}

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, C(KC_RGHT), C(KC_LEFT), \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#endif
           
#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 5
