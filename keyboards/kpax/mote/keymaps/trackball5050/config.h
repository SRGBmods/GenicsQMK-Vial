// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
/* touchpad config */
#define POINTING_DEVICE_RIGHT
#define POINTING_DEVICE_CS_PIN GP9
#define POINTING_DEVICE_SCLK_PIN GP10
#define POINTING_DEVICE_SDIO_PIN GP11
#define POINTING_DEVICE_TASK_THROTTLE_MS 10
// #define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE

// #define PMW33XX_LIFTOFF_DISTANCE 0b1111

// 触控板设置
// #define CIRQUE_PINNACLE_DIAMETER_MM 40
// #define CIRQUE_PINNACLE_CURVED_OVERLAY
// #define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_3X
// #define CIRQUE_PINNACLE_TAP_ENABLE
// #define CIRQUE_PINNACLE_SECONDARY_TAP_ENABLE

// 打开触控板自动切层
// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER 1

#define ADNS5050_SCLK_PIN POINTING_DEVICE_SCLK_PIN
#define ADNS5050_SDIO_PIN POINTING_DEVICE_SDIO_PIN
#define ADNS5050_CS_PIN POINTING_DEVICE_CS_PIN

#define EE_HANDS

