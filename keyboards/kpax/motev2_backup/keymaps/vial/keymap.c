// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H
#include "zzeneg_display.h"
#include "transactions.h"
#include "raw_hid.h"
#include "qp.h"
#include "user_song_list.h"

// #include "pic/animation.qgf.h"

// enum layer_number {
//     // clang-format off
//     _QWERTY = 0,
//     _POINT,
//     _EU,
//     _NAV,
//     _NUMBER,
//     _SYMBOL,
//     _FUNC,
//     _SYS
//     // clang-format on
// };

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LCTL_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_P RGUI_T(KC_P)

// bottom mods
#define SYS_GUI LT(_SYS, KC_LGUI)
#define NUM_TAB LT(_NUMBER, KC_TAB)
#define FUNC_ESC LT(_FUNC, KC_ESC)
#define FUNC_ENT LT(_FUNC, KC_ENT)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define SYMBOL_DEL LT(_SYMBOL, KC_DEL)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_QUOT LGUI_T(KC_QUOT)
// 自定义建码
enum custom_keycodes {
    M_EMAIL = SAFE_RANGE,
    M_CBR,
    M_PRN,
    M_BRC,
    M_ARROW,
};

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
  [_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      FUNC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_EQUAL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_QUOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  SYS_GUI, KC_BSPC,      KC_MUTE, SYS_GUI,  FUNC_ENT, SYMBOL_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
               MO(1),   MO(3),   MO(2),    MO(4),   MO(5),      KC_ENT,  KC_RGHT,  KC_DOWN, KC_LEFT, KC_UP

  ),

  [_POINT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      _______,   _______,    _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______,    _______,    _______,    _______,    _______,    _______,       _______,    _______,    _______,    _______,    _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______	, _______, _______, _______, _______,    _______,   _______,   _______,   _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      _______, _______, _______, _______, _______, _______,    _______,   _______,   _______,   _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  KC_BTN1, KC_BSPC,      KC_MUTE, KC_BTN2,  FUNC_ENT, SYMBOL_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    KC_BTN1,                 KC_BTN2,  _______,    _______,    _______,   _______

  ),

 [_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      FUNC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  SYS_GUI, KC_BSPC,      KC_MUTE, SYS_GUI,  FUNC_ENT, SYMBOL_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

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
                         _______, _______, _______, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

  ),

  [_NUMBER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
        KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MNXT, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, _______,    _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,    _______, _______, _______, _______, _______, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

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
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

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
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

  ),
  [_SYS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       QK_BOOT, EE_CLR, _______, _______,  _______, _______,    RGB_M_P, _______, _______, _______, EE_CLR, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_SPI, HF_PREV, HF_CONU, _______, _______, _______,    RGB_M_B,   _______,   _______,   _______, KC_RBRC, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_TOG, HF_TOGG, _______, CK_TOGG, AU_TOGG, _______,    RGB_M_R,   _______,   _______,   _______, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       RGB_SPD, HF_NEXT, HF_COND, _______, _______, _______,    RGB_M_SW,   _______,   _______,   _______, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,     _______,   _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    _______,  _______,    _______,    _______,    _______,                 _______,  _______,    _______,    _______,   _______

  ),
    // clang-format on
};
// 编码器各层的按键
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    // clang-format off
    [_QWERTY] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_POINT]  = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAME]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUMBER] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYMBOL] = { ENCODER_CCW_CW(HF_PREV, HF_NEXT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FUNC]   = { ENCODER_CCW_CW(CK_UP, CK_DOWN), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYS]    = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    // clang-format on
};
#endif

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

// 鼠标自动切层
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_POINT); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);  // always required before the auto mouse feature will work
}
// 鼠标滚动模式
#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLEE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     dprintf("process_record_user %u %s %s %d\n", keycode, record->event.pressed ? "pressed" : "depressed", record->tap.interrupted ? "interrupted" : "not interrupted", record->tap.count);

//     if (record->event.pressed) {
//         uint8_t data[32];
//         data[0] = 0;

//         switch (keycode) {
//             // send hid commands
//             case KC_VOLU:
//             case KC_VOLD:
//                 data[0] = _VOLUME;
//                 break;

//             // handle macros
//             case M_EMAIL:
//                 SEND_STRING("07genics@gmail.com");
//                 break;
//             case M_CBR:
//                 SEND_STRING("{}" SS_TAP(X_LEFT));
//                 break;
//             case M_PRN:
//                 SEND_STRING("()" SS_TAP(X_LEFT));
//                 break;
//             case M_BRC:
//                 SEND_STRING("[]" SS_TAP(X_LEFT));
//                 break;
//             case M_ARROW:
//                 SEND_STRING("=>");
//                 break;

//             // custom increased tapping term for home row CTRL + other keys
//             case HOME_D:
//                 // save time when CTRL from D key is pressed
//                 if (!record->tap.count) {
//                     HOME_CTRL_pressed_time = record->event.time;
//                 }
//                 break;
//             case HOME_S:
//                 // if S is pressed and CTRL is active, and < 150 passed since CTRL was pressed, cancel CTRL and send D instead
//                 custom_home_row_ctrl(record, 150);
//                 break;
//             case HOME_A:
//                 // if A is pressed and CTRL is active, and < 180 passed since CTRL was pressed, cancel CTRL and send D instead
//                 custom_home_row_ctrl(record, 180);

//                 break;
//         }

//         if (data[0]) {
//             dprintf("raw_hid_send %u\n", data[0]);
//             raw_hid_send(data, sizeof(data));
//         }
//     }

//     return true;
// }
// 加入切层音效
float gitar_song[][2] = SONG(GUITAR_SOUND);
float qwert_song[][2] = SONG(QWERTY_SOUND);
float game_song[][2]  = SONG(TETRIS_SONG);

// /* Active Layer processing */
layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_display_enabled()) {
        display_process_layer_state(get_highest_layer(state));
    } else if (is_keyboard_master() && !is_keyboard_left()) {
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

    return state;
}

/* Caps Word processing */
// void caps_word_set_user(bool active) {
//     if (is_display_enabled()) {
//         display_process_caps_word(active);
//     } else if (is_keyboard_master() && !is_keyboard_left()) {
//         dprintf("RPC_ID_USER_CAPS_WORD_SYNC: %s\n", active ? "active" : "inactive");
//         transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
//     }
// }

/* default caps word logic that allows KC_MINS. Underscore can be typed with KC_RSFT + KC_MINS */
// bool caps_word_press_user(uint16_t keycode) {
//     switch (keycode) {
//         // Keycodes that continue Caps Word, with shift applied.
//         case KC_A ... KC_Z:
//             add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
//             return true;

//         // Keycodes that continue Caps Word, without shifting.
//         case KC_1 ... KC_0:
//         case KC_BSPC:
//         case KC_DEL:
//         case KC_MINS:
//         case KC_RSFT:
//             return true;

//         default:
//             return false; // Deactivate Caps Word.
//     }
// }

/* Raw HID processing*/
// void raw_hid_receive(uint8_t *data, uint8_t length) {
//     dprintf("raw_hid_receive - received %u bytes \n", length);

//     if (is_display_enabled()) {
//         display_process_raw_hid_data(data, length);
//     } else if (is_keyboard_master() && !is_keyboard_left()) {
//         dprint("RPC_ID_USER_HID_SYNC \n");
//         transaction_rpc_send(RPC_ID_USER_HID_SYNC, length, data);
//     }
// }

// void hid_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
//     if (is_display_enabled()) {

//         display_process_raw_hid_data((uint8_t *)initiator2target_buffer, initiator2target_buffer_size);
//     }
// }

// 层同步函数
void layer_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
    if (is_display_enabled()) {
        display_process_layer_state(*(uint8_t *)initiator2target_buffer);
    }
}
// caps同步函数
// void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
//     if (is_display_enabled()) {
//         display_process_caps_word(*(bool *)initiator2target_buffer);
//     }
// }

// 键盘后处理任务
void keyboard_post_init_user() {
    //同步收到的 hid 数据
    //     transaction_register_rpc(RPC_ID_USER_HID_SYNC, hid_sync);
    //同步层状态 (a bit more performant than standard SPLIT_LAYER_STATE_ENABLE)
    transaction_register_rpc(RPC_ID_USER_LAYER_SYNC, layer_sync);
    //同步 caps word 状态
    // transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);
    //   debug_enable=true;
    //   debug_matrix=true;
    //   debug_keyboard=true;
    //   debug_mouse=true;
}

// Forward declare RP2040 SDK declaration.
void gpio_init(uint gpio);

void keyboard_pre_init_kb(void) {
    // Ensures that GP26 through GP29 are initialized as digital inputs (as
    // opposed to analog inputs).  These GPIOs are shared with A0 through A3,
    // respectively.  On RP2040-B2 and later, the digital inputs are disabled by
    // default (see RP2040-E6).
    gpio_init(GP26);
    gpio_init(GP27);
    gpio_init(GP28);
    gpio_init(GP29);

    keyboard_pre_init_user();
}
