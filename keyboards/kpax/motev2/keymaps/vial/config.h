// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// 基础点设置针脚配置
#define POINTING_DEVICE_CS_PIN GP21
#define POINTING_DEVICE_SCLK_PIN GP22
#define POINTING_DEVICE_SDIO_PIN GP20

#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// adns5050配置选项
// #define ADNS5050_CS_PIN   POINTING_DEVICE_CS_PIN
// #define ADNS5050_SCLK_PIN POINTING_DEVICE_SCLK_PIN
// #define ADNS5050_SDIO_PIN POINTING_DEVICE_SDIO_PIN

// pmw3360配置选项
#define PMW33XX_CS_PIN POINTING_DEVICE_CS_PIN
#define PMW33XX_CPI 400
#define POINTING_DEVICE_INVERT_Y
#define PMW33XX_LIFTOFF_DISTANCE 0x01
#define ROTATIONAL_TRANSFORM_ANGLE 0
// 自动切层停留时间
// #define AUTO_MOUSE_TIME 1000
// 移动多少开始切层
// #define AUTO_MOUSE_THRESHOLD 10



// azoteq触控板设置
// #define AZOTEQ_IQS5XX_TPS65
// #define AZOTEQ_IQS5XX_TIMEOUT_MS 10

// #define AZOTEQ_IQS5XX_TAP_ENABLE true
// #define AZOTEQ_IQS5XX_TWO_FINGER_TAP_ENABLE true
// #define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
// #define AZOTEQ_IQS5XX_SWIPE_X_ENABLE true
// #define AZOTEQ_IQS5XX_SWIPE_Y_ENABLE true
// #define AZOTEQ_IQS5XX_ZOOM_ENABLE true
// #define AZOTEQ_IQS5XX_SCROLL_ENABLE true
// #define AZOTEQ_IQS5XX_TAP_TIME 150
// #define AZOTEQ_IQS5XX_TAP_DISTANCE 25
// #define AZOTEQ_IQS5XX_HOLD_TIME 300
// #define AZOTEQ_IQS5XX_SWIPE_INITIAL_TIME 150
// #define AZOTEQ_IQS5XX_SWIPE_INITIAL_DISTANCE 300
// #define AZOTEQ_IQS5XX_SWIPE_CONSECUTIVE_TIME 0
// #define AZOTEQ_IQS5XX_SWIPE_CONSECUTIVE_DISTANCE 2000
// #define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 50
// #define AZOTEQ_IQS5XX_ZOOM_INITIAL_DISTANCE 50
// #define AZOTEQ_IQS5XX_ZOOM_CONSECUTIVE_DISTANC 25
// #define AZOTEQ_IQS5XX_ROTATION_180
// 触控板配置选项
// #define CIRQUE_PINNACLE_DIAMETER_MM 35
// #define CIRQUE_PINNACLE_CURVED_OVERLAY
// #define POINTING_DEVICE_GESTURES_SCROLL_ENABLE // Circular scroll.
// #define CIRQUE_PINNACLE_SPI_CS_PIN GP21
// #define POINTING_DEVICE_ROTATION_90


// vial配置
#define VIAL_KEYBOARD_UID {0x2B, 0x3C, 0x7E, 0x52, 0x60, 0x3E, 0xFE, 0x52}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 6 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

#define VIAL_COMBO_ENTRIES 20
#define DYNAMIC_KEYMAP_MACRO_COUNT 50

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_HID_SYNC, RPC_ID_USER_CAPS_WORD_SYNC, RPC_ID_USER_LAYER_SYNC

#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_TIMEOUT 300000
#    define RGB_TRIGGER_ON_KEYDOWN
#endif

#define CAPS_WORD_IDLE_TIMEOUT 2500
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define TAPPING_TERM 150
// #define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM 0

// #define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define MOUSE_EXTENDED_REPORT



