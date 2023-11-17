// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "qp.h"

enum dilemma_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_NUM,
};

#define NAV MO(LAYER_NAV)
#define SYM MO(LAYER_SYM)

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [LAYER_NAV] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [LAYER_SYM] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [LAYER_NUM] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_6x6(
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y, KC_U,    KC_I,    KC_O,    KC_P,   KC_MINS,
         KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H, KC_J,    KC_K,    KC_L, KC_SCLN,   KC_QUOT,
         KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                  KC_LALT,     KC_SPC,  KC_LGUI,    KC_SPC,                  KC_RGUI,  KC_RGUI,    KC_ENT,  KC_BSPC,
         KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_ENT,                 KC_ENT,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP
  ),

    [LAYER_NAV] = LAYOUT_split_6x6(
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               _______, _______, _______, _______, _______, _______,
                  KC_LALT,     KC_SPC,  KC_LGUI,    KC_SPC,                  KC_RGUI,  KC_RGUI,    KC_ENT,  KC_BSPC,
         KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,                XXXXXXX,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP
  ),

  [LAYER_SYM] = LAYOUT_split_6x6(
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y, KC_U,    KC_I,    KC_O,    KC_P,   KC_MINS,
         KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H, KC_J,    KC_K,    KC_L, KC_SCLN,   KC_QUOT,
         KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                  KC_LALT,     KC_SPC,  KC_LGUI,    KC_SPC,                  KC_RGUI,  KC_RGUI,    KC_ENT,  KC_BSPC,
         KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,                XXXXXXX,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP
  ),

  [LAYER_NUM] = LAYOUT_split_6x6(
         KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                  KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
         KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                  KC_Y, KC_U,    KC_I,    KC_O,    KC_P,   KC_MINS,
         KC_LSFT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                 KC_H, KC_J,    KC_K,    KC_L, KC_SCLN,   KC_QUOT,
         KC_LCTL,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                 KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_RCTL,
                  KC_LALT,     KC_SPC,  KC_LGUI,    KC_SPC,                  KC_RGUI,  KC_RGUI,    KC_ENT,  KC_BSPC,
         KC_UP,  KC_LEFT,    KC_DOWN,    KC_RGHT,    XXXXXXX,                XXXXXXX,  KC_RGHT,    KC_DOWN,    KC_LEFT,   KC_UP
  ),


};
// clang-format on
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAV, LAYER_SYM, LAYER_NUM);
};

painter_device_t lcd;

void lv_example_arc_2(void);

void keyboard_post_init_user(void) {
    lcd = qp_gc9a01_make_spi_device(240, 240, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 4, 0);
    qp_init(lcd, QP_ROTATION_0);
    qp_rect(lcd, 0, 0, 239, 319, 0, 255, 255, true);

    if (qp_lvgl_attach(lcd)) {
        lv_example_arc_2();
    }
}

static void set_angle(void* obj, int32_t v) {
    lv_arc_set_value(obj, v);
}

/**
 * Create an arc which acts as a loader.
 */
void lv_example_arc_2(void) {
    /*Create an Arc*/
    lv_obj_t* arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);  /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_center(arc);

    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);
}



