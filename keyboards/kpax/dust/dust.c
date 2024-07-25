// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "dust.h"
#include "display.h"

static bool display_enabled;

/* public function to be used in keymaps */
bool is_display_side(void) {
#ifdef STRONT_DISPLAY_RIGHT
    return !is_keyboard_left();
#endif
#ifdef STRONT_DISPLAY_LEFT
    return is_keyboard_left();
#endif
    return false;
}

/* public function to be used in keymaps */
bool is_display_enabled(void) {
    return display_enabled;
}

/* default encoder keys */
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code_delay(KC_RIGHT, 10);
        } else {
            tap_code_delay(KC_LEFT, 10);
        }
    }
    return true;
}
