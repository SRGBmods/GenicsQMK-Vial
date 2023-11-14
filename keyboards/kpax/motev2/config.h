// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once



// 重启功能配置
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U






/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define PERMISSIVE_HOLD

// 旋钮配置
#define ENCODERS_PAD_A { GP3 }
#define ENCODERS_PAD_B { GP5 }
#define ENCODER_RESOLUTION 4
/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
// 震动配置
#define SOLENOID_PIN GP25
#define HAPTIC_OFF_IN_LOW_POWER 1


// 灯光配置
#ifdef RGB_MATRIX_ENABLE
#    define WS2812_DI_PIN GP4
#    define WS2812_PIO_USE_PIO1
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_LED_COUNT 100
#    define RGB_MATRIX_SPLIT { 50, 50 }
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120
#    define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#endif





// 音频配置
#define AUDIO_PIN GP2
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_CLICKY


// vial配置
#define VIAL_KEYBOARD_UID {0x0F, 0xB0, 0xD3, 0xDF, 0x7B, 0x86, 0xA6, 0x00}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }


