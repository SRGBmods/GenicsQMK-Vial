/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0x75, 0xE7, 0x1E, 0x9C, 0x46, 0x62, 0xFA, 0xA0}

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
