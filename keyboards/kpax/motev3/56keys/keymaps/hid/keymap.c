// Copyright 2022 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include QMK_KEYBOARD_H

#include "hid_display.h"
#include "display.h"
#include "raw_hid.h"
#include "transactions.h"
#include "user_song_list.h"

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

// bottom mods
#define SYM_SPC LT(_SYMBOL, KC_SPC)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define SYS_ESC LT(_SYS, KC_ESC)
#define SYM_ENT LT(_SYMBOL, KC_ENT)
#define SYS_BSPC LT(_SYS, KC_BSPC)
#define RALT_DEL LALT_T(KC_DEL)
#define SYS_WIN LT(_SYS, KC_LGUI)

// game layer mods
#define LALT_EQL LALT_T(KC_EQL)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_GRV LGUI_T(KC_GRV)

enum custom_keycodes {
    DRAG_SCROLL = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     *        .----------------------------------.                    .----------------------------------.
     *        |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |
     * .------+------+------+------+------+------|                    |------+------+------+------+------+------.
     * |  =   |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |  -   |   Z  |   X  |   C  |   V  |   B  |--------.  .--------|   N  |   M  |   ,  |   .  |   /  |  `   |
     * '-----------------------------------------/       /    \       \-----------------------------------------'
     *                         | Esc  | Tab  |  / Space /      \ Enter \  | Bsps | Del  |
     *                         |_FUNC | _NUM | /_SYMBOL/        \ _FUNC \ | _NAV | RAlt |
     *                         `-------------''-------'          '-------''-------------'
     */
    // clang-format off
    [_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      SYS_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, SYS_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_EQUAL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPACE, KC_LGUI, KC_MUTE,      KC_MUTE,MO(6),  SYM_ENT, RALT_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
               MO(2),   MO(3),   MO(1),    MO(4),   MO(5),      KC_ENT,  KC_RGHT,  KC_DOWN, KC_LEFT, KC_UP,
                                 KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1
    ),

    [_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      LCTL_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      LSFT_MINS,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_EQUAL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      LALT_EQL,  KC_SPC, LGUI_GRV, KC_BSPC,      KC_MUTE,KC_LALT,  SYM_ENT, KC_LALT,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
               MO(1),   MO(3),   MO(2),    MO(4),   MO(5),      KC_ENT,  KC_RGHT,  KC_DOWN, KC_LEFT, KC_UP,
                                                KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1

    ),

    [_NAV] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, _______, _______, KC_UP, _______, _______,    _______, _______, _______, _______, _______, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, _______,   KC_LEFT, KC_DOWN, KC_RGHT, _______,    _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,    _______, _______, _______, _______, _______, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         DRAG_SCROLL, KC_BTN1, KC_BTN2, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______,
                                     KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1

    ),

    [_NUMBER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_EQUAL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC, KC_LALT, KC_BSPC,      KC_MUTE,KC_LALT,  SYM_ENT, KC_LALT,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
               MO(1),   MO(3),   MO(2),    MO(4),   MO(5),      KC_ENT,  KC_RGHT,  KC_DOWN, KC_LEFT, KC_UP,
                                                KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1

    ),

    [_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_CAPS_LOCK, _______, _______, _______, _______, _______,    _______, _______, KC_LCBR, KC_RCBR, _______, KC_PLUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        _______, _______, _______,   _______, _______,  _______,    _______, _______, KC_LPRN, KC_RPRN, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______,  _______, _______,   KC_PLUS, KC_UNDS, KC_LBRC, KC_RBRC, KC_PIPE, KC_PIPE,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______,
                                     KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1

    ),

    [_FUNC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_VOLD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,    _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,    _______, _______, _______, _______, _______, KC_MUTE,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______,
                                     KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1


    ),

    [_SYS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, QK_BOOT, EE_CLR, _______,  _______, _______,    RGB_M_P, _______, _______, EE_CLR, QK_BOOT, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_SPI, HF_PREV, HF_CONU, _______, _______, _______,    RGB_M_B,   _______,   _______,   _______, KC_RBRC, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, HF_TOGG, _______, CK_TOGG, AU_TOGG, _______,    RGB_M_R,   _______,   _______,   _______, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_SPD, HF_NEXT, HF_COND, _______, _______, _______,    RGB_M_SW,   _______,   _______,   _______, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,     _______,   _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______,
                                     KC_1, KC_1, KC_1,              KC_1, KC_1, KC_1

    )
    // clang-format on
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_QWERTY] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAME]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUMBER] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYMBOL] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FUNC]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYS]    = { ENCODER_CCW_CW(BL_DOWN, BL_UP),   ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
    // clang-format on
};
#endif // ENCODER_MAP_ENABLE

/* Caps Word processing */
#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    if (is_display_enabled()) {
        display_process_caps(active);
    } else if (is_keyboard_master() && !is_display_side()) {
        dprintf("RPC_ID_USER_CAPS_WORD_SYNC: %s\n", active ? "active" : "inactive");
        transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
    }
}
#endif

// 加入切层音效
float gitar_song[][2] = SONG(GUITAR_SOUND);
float qwert_song[][2] = SONG(QWERTY_SOUND);
float game_song[][2]  = SONG(TETRIS_SONG);
// 鼠标拖拽滚动
bool set_scrolling = false;

// Modify these values to adjust the scrolling speed
#define SCROLL_DIVISOR_H 8.0
#define SCROLL_DIVISOR_V 8.0

// Variables to store accumulated scroll values
float scroll_accumulated_h = 0;
float scroll_accumulated_v = 0;

// Function to handle mouse reports and perform drag scrolling
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Check if drag scrolling is active
    if (set_scrolling) {
        // Calculate and accumulate scroll values based on mouse movement and divisors
        scroll_accumulated_h += (float)mouse_report.x / SCROLL_DIVISOR_H;
        scroll_accumulated_v += (float)mouse_report.y / SCROLL_DIVISOR_V;

        // Assign integer parts of accumulated scroll values to the mouse report
        mouse_report.h = (int8_t)scroll_accumulated_h;
        mouse_report.v = (int8_t)scroll_accumulated_v;

        // Update accumulated scroll values by subtracting the integer parts
        scroll_accumulated_h -= (int8_t)scroll_accumulated_h;
        scroll_accumulated_v -= (int8_t)scroll_accumulated_v;

        // Clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}

// Function to handle key events and enable/disable drag scrolling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DRAG_SCROLL:
            // Toggle set_scrolling when DRAG_SCROLL key is pressed or released
            set_scrolling = record->event.pressed;
            break;
        default:
            break;
    }
    return true;
}

/* Active Layer processing */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    } else if (is_keyboard_master() && !is_display_side()) {
        uint8_t layer = get_highest_layer(state);
        dprintf("RPC_ID_USER_LAYER_SYNC: %u\n", layer);
        transaction_rpc_send(RPC_ID_USER_LAYER_SYNC, 1, &layer);
    }
    // 切层音效
    static bool is_sys_enabled = false, is_game_enabled = false, is_symbol_enabled = false;
    if (layer_state_cmp(state, _SYS) != is_sys_enabled || layer_state_cmp(state, _GAME) != is_game_enabled || layer_state_cmp(state, _SYMBOL) != is_symbol_enabled) {
        is_sys_enabled    = layer_state_cmp(state, _SYS);
        is_game_enabled   = layer_state_cmp(state, _GAME);
        is_symbol_enabled = layer_state_cmp(state, _SYMBOL);

        if (is_sys_enabled) {
            PLAY_SONG(gitar_song);
        } else if (is_symbol_enabled) {
            PLAY_SONG(qwert_song);
        } else if (is_game_enabled) {
            PLAY_SONG(game_song);
        }
    }
    // Disable set_scrolling if the current layer is not the AUTO_MOUSE_DEFAULT_LAYER
    if (get_highest_layer(state) != AUTO_MOUSE_DEFAULT_LAYER) {
        set_scrolling = false;
    }

    return state;
}

/* Raw HID processing*/
void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    dprintf("raw_hid_receive - received %u bytes \n", length);

    if (is_display_enabled()) {
        display_process_raw_hid_data(data, length);
    } else if (is_keyboard_master() && !is_display_side()) {
        dprint("RPC_ID_USER_HID_SYNC \n");
        transaction_rpc_send(RPC_ID_USER_HID_SYNC, length, data);
    }
}

void hid_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_raw_hid_data((uint8_t *)initiator2target_buffer, initiator2target_buffer_size);
    }
}

void layer_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_layer_state(*(uint8_t *)initiator2target_buffer);
    }
}

void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_caps(*(bool *)initiator2target_buffer);
    }
}

void keyboard_post_init_user() {
    // sync received hid data
    transaction_register_rpc(RPC_ID_USER_HID_SYNC, hid_sync);
    // sync highest layer (a bit more performant than standard SPLIT_LAYER_STATE_ENABLE)
    transaction_register_rpc(RPC_ID_USER_LAYER_SYNC, layer_sync);
    // sync caps word state
    transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);
}

// 鼠标自动切层
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_NAV);  // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}

// 切层底光换色
#ifdef RGB_MATRIX_ENABLE
// Layer state indicator
bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    if (host_keyboard_led_state().caps_lock) {
        for (int i = led_min; i <= led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_INDICATOR)) {
                rgb_matrix_set_color(i, 15, 255, 247);
            }
        }
    }

    uint8_t layer = get_highest_layer(layer_state);
    if (layer > 0) {
        HSV hsv = rgb_matrix_get_hsv();
        switch (get_highest_layer(layer_state)) {
            case 1:
                hsv = (HSV){HSV_BLUE};
                break;
            case 2:
                hsv = (HSV){HSV_AZURE};
                break;
            case 3:
                hsv = (HSV){HSV_ORANGE};
                break;
            case 4:
                hsv = (HSV){HSV_GREEN};
                break;
            case 5:
                hsv = (HSV){HSV_TEAL};
                break;
            case 6:
                hsv = (HSV){HSV_PURPLE};
                break;
            case 7:
            default:
                hsv = (HSV){HSV_RED};
                break;
        };

        if (hsv.v > rgb_matrix_get_val()) {
            hsv.v = MIN(rgb_matrix_get_val() + 22, 255);
        }
        RGB rgb = hsv_to_rgb(hsv);

        for (uint8_t i = led_min; i < led_max; i++) {
            if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
                rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
            }
        }
    }
    return false;
};
#endif // RGB_MATRIX_ENABLE
