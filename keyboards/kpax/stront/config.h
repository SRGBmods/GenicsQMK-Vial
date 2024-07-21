// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* stront specific options */
#define STRONT_DISPLAY_LEFT // display is on left by default
#define STRONT_DISPLAY_ROTATION QP_ROTATION_180
#ifdef QUANTUM_PAINTER_ST7789_SPI_ENABLE // default settings for ST7789 1.69" display
#    define STRONT_DISPLAY_WIDTH 240
#    define STRONT_DISPLAY_HEIGHT 280
#    define STRONT_DISPLAY_OFFSET_X 0
#    define STRONT_DISPLAY_OFFSET_Y 20
#endif

/* interconnect config */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_PIN_SWAP
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

/* reset config */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

/* any side can be master by default, enable split sync to support it */
#define EE_HANDS
#define SPLIT_POINTING_ENABLE

/* common SPI/I2C config */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MOSI_PIN GP23
#define SPI_MISO_PIN GP20
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP7
#define I2C1_SCL_PIN GP6

/* common touchpad config */
#define POINTING_DEVICE_RIGHT // touchpad is right by default
#define POINTING_DEVICE_CS_PIN GP21
#ifdef POINTING_DEVICE_DRIVER_azoteq_iqs5xx
#    define AZOTEQ_IQS5XX_TPS43
#    define AZOTEQ_IQS5XX_ROTATION_270
#else
#    define CIRQUE_PINNACLE_DIAMETER_MM 40
// #    define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X // enable for curved overlay
#    ifdef POINTING_DEVICE_RIGHT
// #        define POINTING_DEVICE_ROTATION_180
#    endif
#endif

/* common LCD config */
#define LCD_CS_PIN GP21
#define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_B
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 0

// 音效蜂鸣器配置
#ifdef AUDIO_ENABLE
#    define AUDIO_VOICES
#    define AUDIO_PIN GP2
#    define AUDIO_PWM_DRIVER PWMD1
#    define AUDIO_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#    define AUDIO_CLICKY
#    define AUDIO_CLICKY_FREQ_DEFAULT 61.0f
#    define AUDIO_CLICKY_FREQ_MIN 61.0f
#    define AUDIO_CLICKY_FREQ_MAX 1500.0f
#    define AUDIO_CLICKY_FREQ_FACTOR 1.18921f
#    define AUDIO_CLICKY_FREQ_RANDOMNESS 1.0f
#    define AUDIO_CLICKY_DELAY_DURATION 6
#    define AUDIO_INIT_DELAY 2
#    define STARTUP_SONG SONG(ROCK_A_BYE_BABY)
#    define GOODBYE_SONG SONG(CAMPANELLA)
#    define MUSIC_ON_SONG SONG(ZELDA_PUZZLE)
#    define AUDIO_VOICES
#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100
