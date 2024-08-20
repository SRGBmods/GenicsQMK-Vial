// Copyright 2023 FxStudio <FXS@fx-studio.cn>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #define DYNAMIC_KEYMAP_LAYER_COUNT 3

#define MATRIX_ROWS 10
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { C8, C7, C6, B15, B14 }
#define MATRIX_COL_PINS { C10, C11, C12, A15, B6, D2, B3, B4, B5, B7, A0, A1, A2, A3 }

#define MATRIX_ROW_PINS_RIGHT { A7, C4, C5, A4, A5 }
#define MATRIX_COL_PINS_RIGHT { A6, B0, B1, B4, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }


#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 5000
#define SPLIT_USB_TIMEOUT_POLL 20     //检测轮询
#define SPLIT_WATCHDOG_ENABLE           //监视程序
#define SPLIT_MAX_CONNECTION_ERRORS 5
#define NO_USB_STARTUP_CHECK //
#define SPLIT_TRANSPORT_MIRROR      //主侧矩阵镜像到从侧
#define SPLIT_ACTIVITY_ENABLE

#define FORCED_SYNC_THROTTLE_MS 100
#define SPLIT_HAND_PIN C13
#define SOFT_SERIAL_PIN A9
#define SERIAL_USART_SPEED 137000
#define SELECT_SOFT_SERIAL_SPEED 1
#define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_TX_PAL_MODE 7

#define RGBLED_NUM 81
#define DRIVER_LED_TOTAL 81
#define RGB_MATRIX_LED_COUNT 81

#define WS2812_PWM_COMPLEMENTARY_OUTPUT
#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 1
#define WS2812_PWM_PAL_MODE 1
#define WS2812_DMA_STREAM STM32_DMA2_STREAM5
#define WS2812_DMA_CHANNEL 6

// #define RGB_MATRIX_STARTUP_VAL 60
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 180
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_MATRIX_SLEEP  // turn off effects when suspended
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
