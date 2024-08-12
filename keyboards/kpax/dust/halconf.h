// Copyright 2022 Stefan Kerkmann
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
// 打开各种功能
#define HAL_USE_I2C TRUE
#define HAL_USE_PWM TRUE
#define HAL_USE_SPI TRUE
// #define HAL_USE_ADC TRUE
#define SPI_USE_WAIT TRUE

#include_next <halconf.h>
