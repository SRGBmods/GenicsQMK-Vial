// Copyright 2022 Jose Pablo Ramirez (@jpe230)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once


// #define POINTING_DEVICE_SCLK_PIN GP22
// #define POINTING_DEVICE_SDIO_PIN GP20
#define POINTING_DEVICE_CS_PIN GP21

// #define ADNS5050_SCLK_PIN POINTING_DEVICE_SCLK_PIN
// #define ADNS5050_SDIO_PIN POINTING_DEVICE_SDIO_PIN
// #define ADNS5050_CS_PIN   POINTING_DEVICE_CS_PIN






// Enable use of pointing device on slave split.
#define SPLIT_POINTING_ENABLE


// Pointing device is on the right split.
#define POINTING_DEVICE_RIGHT

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 10

// Adjust trackpad rotation.
#define POINTING_DEVICE_ROTATION_90

// Configure for the Cirque model used on the Dilemma.
#define CIRQUE_PINNACLE_DIAMETER_MM 35
#define CIRQUE_PINNACLE_CURVED_OVERLAY
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE // Circular scroll.
#define CIRQUE_PINNACLE_SPI_CS_PIN GP21


// vial配置
#define VIAL_KEYBOARD_UID {0x2B, 0x3C, 0x7E, 0x52, 0x60, 0x3E, 0xFE, 0x52}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 1 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define VIAL_COMBO_ENTRIES 20
#define DYNAMIC_KEYMAP_MACRO_COUNT 50

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

