// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
// #include "zzeneg_display.h"
// #include "transactions.h"
// #include "raw_hid.h"
// #include "qp.h"
// #include "pic/animation.qgf.h"

enum layer_number {
    _QWERTY = 0,
    _POINT,
    _EU,
    _NAV,
    _NUMBER,
    _SYMBOL,
    _FUNC,
    _SYS,
};



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
#define EU_DEL LT(_EU, KC_DEL)

// game layer mods
#define LALT_Q LALT_T(KC_Q)
#define LSFT_MINS LSFT_T(KC_MINS)
#define LCTL_ESC LCTL_T(KC_ESC)
#define LGUI_QUOT LGUI_T(KC_QUOT)

// enum custom_keycodes {
//     M_EMAIL = SAFE_RANGE,
//     M_CBR,
//     M_PRN,
//     M_BRC,
//     M_ARROW,
// };

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      FUNC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  SYS_GUI, KC_BSPC,      KC_MUTE, SYS_GUI,  FUNC_ENT, EU_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
               MO(1),   MO(3),   MO(2),    MO(4),   MO(5),      KC_ENT,  KC_RGHT,  KC_DOWN, KC_LEFT, KC_UP

  ),

  [_POINT] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      FUNC_ESC,   DPI_MOD,    S_D_MOD,    DRGSCRL,    SNIPING,   KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  SYS_GUI, KC_BSPC,      KC_MUTE, SYS_GUI,  FUNC_ENT, EU_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

  ),

 [_EU] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
      FUNC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINUS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
      KC_LCTL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RCTL,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                      KC_LALT,  KC_SPC,  SYS_GUI, KC_BSPC,      KC_MUTE, SYS_GUI,  FUNC_ENT, EU_DEL,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
       _FUNC,   KC_LEFT,    _NAV,        KC_RGHT,  KC_ENT,       KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

  ),


  [_NAV] = LAYOUT(
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
    KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

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
    KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

  ),
    [_SYMBOL] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, KC_LBRC, KC_RBRC, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
        KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       _______, _______, _______, _______,  _______, _______,   XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                         _______, _______, _______, _______,    _______, _______, _______, _______,
  //                    ╰───────────────────────────────────╯ ╰───────────────────────────────────╯
    KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

  ),
  [_FUNC] = LAYOUT(
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
    KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

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
        KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,     KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP

  ),
// clang-format on
};
// 编码器各层的按键
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [_QWERTY] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_POINT]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_EU]     = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV]    = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUMBER] = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYMBOL] = { ENCODER_CCW_CW(HF_PREV, HF_NEXT), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FUNC]   = { ENCODER_CCW_CW(CK_UP, CK_DOWN), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_SYS]    = { ENCODER_CCW_CW(RGB_MOD, RGB_RMOD), ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    // clang-format on
};


// 切层底光换色
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 7:
                rgb_matrix_set_color(i, RGB_TEAL);
                break;
            case 6:
                rgb_matrix_set_color(i, RGB_YELLOW);
                break;
            case 5:
                rgb_matrix_set_color(i, RGB_PINK);
                break;
            case 4:
                rgb_matrix_set_color(i, RGB_CORAL);
                break;
            case 3:
                rgb_matrix_set_color(i, RGB_MAGENTA);
                break;
            case 2:
                rgb_matrix_set_color(i, RGB_BLUE);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            default:
                break;
        }
    };
// 大写锁定灯光
        if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_INDICATOR) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    return false;
};
// 鼠标自动切层
extern bool is_drag_scroll;
uint16_t overall_scroll_distance = 0;
void pointing_device_init_user(void) {
    set_auto_mouse_layer(1); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
};
// // 鼠标滚动模式
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

// /* Active Layer processing */
// layer_state_t layer_state_set_user(layer_state_t state) {
//     if (is_display_enabled()) {
//         display_process_layer_state(get_highest_layer(state));
//     } else if (is_keyboard_master() && !is_keyboard_left()) {
//         uint8_t layer = get_highest_layer(state);
//         dprintf("RPC_ID_USER_LAYER_SYNC: %u\n", layer);
//         transaction_rpc_send(RPC_ID_USER_LAYER_SYNC, 1, &layer);
//     }

//     return state;
// }

// /* Caps Word processing */
// void caps_word_set_user(bool active) {
//     if (is_display_enabled()) {
//         display_process_caps_word(active);
//     } else if (is_keyboard_master() && !is_keyboard_left()) {
//         dprintf("RPC_ID_USER_CAPS_WORD_SYNC: %s\n", active ? "active" : "inactive");
//         transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
//     }
// }

// /* default caps word logic that allows KC_MINS. Underscore can be typed with KC_RSFT + KC_MINS */
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

// void layer_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
//     if (is_display_enabled()) {
//         display_process_layer_state(*(uint8_t *)initiator2target_buffer);
//     }
// }

// void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
//     if (is_display_enabled()) {
//         display_process_caps_word(*(bool *)initiator2target_buffer);
//     }
// }

// void keyboard_post_init_user() {
//     // sync received hid data
//     transaction_register_rpc(RPC_ID_USER_HID_SYNC, hid_sync);
//     // sync highest layer (a bit more performant than standard SPLIT_LAYER_STATE_ENABLE)
//     transaction_register_rpc(RPC_ID_USER_LAYER_SYNC, layer_sync);
//     // sync caps word state
//     transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);
// }
// void keyboard_post_init_user(void) {
//  debug_enable=true;
// //   debug_matrix=true;
//   debug_keyboard=true;
//   debug_mouse=true;
// }
