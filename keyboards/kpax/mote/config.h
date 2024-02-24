// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
// 左右通信
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USE_PIO0
// 强制全键无冲
#define FORCE_NKRO
// 双击重启
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Specify a optional status led by GPIO number which blinks when
// 定义震动马达针脚
#define SOLENOID_PIN GP25
#define HAPTIC_OFF_IN_LOW_POWER 1
#define SOLENOID_RANDOM_FIRE
#define SOLENOID_DEFAULT_BUZZ 1
#define SOLENOID_DEFAULT_DWELL 90
#define SOLENOID_MIN_DWELL 4
#define SOLENOID_MAX_DWELL 100
#define SOLENOID_DWELL_STEP_SIZE 10
#define SOLENOID_BUZZ_ACTUATED SOLENOID_MIN_DWELL
#define SOLENOID_BUZZ_NONACTUATED SOLENOID_MIN_DWELL
#define NO_HAPTIC_ALPHA
#define NO_HAPTIC_NUMERIC
#define NO_HAPTIC_NAV


// DRV2605L 普通马达设置 ERM
// #define FB_ERM_LRA 0
// #define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
// #define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */
// /* Please refer to your datasheet for the optimal setting for your specific motor. */
// #define RATED_VOLTAGE 3
// #define V_PEAK 5

// #define I2C_DRIVER I2CD1
// #define I2C1_SDA_PIN GP10
// #define I2C1_SCL_PIN GP11



// // DRV2605L 线性马达设置 LRA
// #define FB_ERM_LRA 1
// #define FB_BRAKEFACTOR 3 /* For 1x:0, 2x:1, 3x:2, 4x:3, 6x:4, 8x:5, 16x:6, Disable Braking:7 */
// #define FB_LOOPGAIN 1 /* For  Low:0, Medium:1, High:2, Very High:3 */
// /* Please refer to your datasheet for the optimal setting for your specific motor. */
// #define RATED_VOLTAGE 3
// // #define V_PEAK 2.8
// // #define V_RMS 2.0
// // #define V_PEAK 2.1
// #define F_LRA 160 /* resonance freq */


// 定义蜂鸣器针脚
#ifdef AUDIO_ENABLE
#define AUDIO_PIN GP2
#define AUDIO_PWM_DRIVER PWMD1
#define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define AUDIO_CLICKY
#define AUDIO_CLICKY_FREQ_DEFAULT 200.0f
#define AUDIO_CLICKY_FREQ_MIN 61.0f
#define AUDIO_CLICKY_FREQ_MAX 1500.0f
#define AUDIO_CLICKY_FREQ_FACTOR 1.18921f
#define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
#define AUDIO_CLICKY_DELAY_DURATION 6
#define AUDIO_INIT_DELAY 2
#define STARTUP_SONG SONG(ROCK_A_BYE_BABY)
#define GOODBYE_SONG SONG(CAMPANELLA)
#define MUSIC_ON_SONG SONG(ZELDA_PUZZLE)
#endif

// 定义zhaqian摇杆
// #ifdef JOYSTICK_TRIGGER_ENABLE
// #define ADC_RESOLUTION ADC_CFGR1_RES_12BIT
// #define JOYSTICK_ADC_RESOLUTION 12
// // #define JOYSTICK_USE_LPF
// // #define JOYSTICK_LPF_PROPORTION (0.2)
// #define JOYSTICK_AXES_X_PIN { GP26 }
// #define JOYSTICK_AXES_Y_PIN { GP27 }
// #define JOYSTICK_AXES_PX_KEY_POS {3, 5}
// #define JOYSTICK_AXES_NX_KEY_POS {2, 5}
// #define JOYSTICK_AXES_PY_KEY_POS {4, 5}
// #define JOYSTICK_AXES_NY_KEY_POS {5, 5}
// #endif


// 分离键盘参数
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_MODS_ENABLE
#define SPLIT_POINTING_ENABLE
#define SPLIT_HAPTIC_ENABLE
#define SPLIT_TRANSPORT_MIRROR
#define SPLIT_LAYER_STATE_ENABLE
#define RGBLIGHT_SPLIT


// 定义左右手针脚
#define SPLIT_HAND_PIN GP29

// 设置vbus检测
// #define SPLIT_USB_TIMEOUT 5000
// #define SPLIT_USB_TIMEOUT_POLL 25
#define USB_VBUS_PIN GP19


// // 定义官方摇杆功能
// // Min 0, max 32
// #define JOYSTICK_BUTTON_COUNT 0
// // Min 0, max 6: X, Y, Z, Rx, Ry, Rz
// #define JOYSTICK_AXIS_COUNT 2
// // Min 8, max 16
// #define JOYSTICK_AXIS_RESOLUTION 12
// #define ANALOG_JOYSTICK_X_AXIS_PIN GP27
// #define ANALOG_JOYSTICK_Y_AXIS_PIN GP26

// 显示屏和触控板的spi设置
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN GP10
#define SPI_MOSI_PIN GP11
#define SPI_MISO_PIN GP12



// LCD设置
#define LCD_DC_PIN GP12
#define LCD_CS_PIN GP9
#define LCD_RST_PIN GP13
#define BACKLIGHT_PWM_DRIVER PWMD7
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0
#define QUANTUM_PAINTER_LVGL_USE_CUSTOM_CONF
// 定义刷机按钮位置
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0
#define BOOTMAGIC_LITE_ROW_RIGHT 6
#define BOOTMAGIC_LITE_COLUMN_RIGHT 0

// 加入zhaqian的设置
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE


#ifdef RGB_MATRIX_ENABLE
#define RGB_MATRIX_LED_COUNT 76
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150
#define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#define RGB_MATRIX_ANIMATION
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define ENABLE_RGB_MATRIX_ALPHAS_MODS
#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
#define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_PENDULUM
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH


#ifdef RGB_MATRIX_CUSTOM_KB
#define RGB_MATRIX_CUSTOM_ANIMATION
#endif
#endif

#ifdef UNDERGLOW_RGB_MATRIX_ENABLE
#define UG_RGB_MATRIX_ANIMATIONS
#endif

#ifdef DYNAMIC_RGB_INDICATORS_ENABLE
#define ENABLE_RGB_INDICATORS_ANIMATIONS
#endif

#ifdef VIA_ENABLE
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#endif
// vial配置
#define VIAL_KEYBOARD_UID {0x2B, 0x3C, 0x7E, 0x52, 0x60, 0x3E, 0xFE, 0x52}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 6 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 0 }

#define VIAL_COMBO_ENTRIES 20
#define DYNAMIC_KEYMAP_MACRO_COUNT 50


#ifdef DYNAMIC_TAP_DANCE_ENABLE
#define DYNAMIC_TAP_DANCE_ENTRIES 10
#endif

#ifdef DYNAMIC_COMBOS_ENABLE
#define DYNAMIC_COMBOS_ENTRIES 10
#endif

// #ifdef OLED_ENABLE
// #define OLED_DISPLAY_128X32
// #define I2C1_SCL_PIN        GP11
// #define I2C1_SDA_PIN        GP10
// #define I2C_DRIVER I2CD1
// #define OLED_BRIGHTNESS 128
// #endif
