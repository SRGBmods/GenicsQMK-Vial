/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once
#define VIAL_KEYBOARD_UID {0xA4, 0xED, 0xA4, 0xB8, 0xC4, 0x0C, 0x69, 0x6C}

#ifndef VIAL_INSECURE
#define VIAL_UNLOCK_COMBO_ROWS { 1, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 7, 6 }
#endif

#if defined(ENCODER_ENABLE) && defined(VIAL_ENCODERS_ENABLE)
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, C(KC_LEFT), C(KC_RIGHT), \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, \
                               KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS }
#endif

#define DYNAMIC_KEYMAP_LAYER_COUNT 4

#define TAP_CODE_DELAY 25

#define TAPPING_FORCE_HOLD

