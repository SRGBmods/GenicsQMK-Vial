// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "dust.h"
#include "qp.h"
#include "qp_comms.h"

#ifdef GC_9A01
#    include "qp_gc9a01_opcodes.h"
#    include "gfx/cat240x240.qgf.h"
#else
#    include "qp_st77xx_opcodes.h"
// #include "gfx/cat320x240.qgf.h"
#    include "gfx/design.qgf.h"
#    include "gfx/design2.qgf.h"
#    include "gfx/animation.qgf.h"
#endif

#include "color.h"
#include "config.h"

painter_device_t lcd;

void keyboard_post_init_kb(void) {
    // Display timeout
    wait_ms(LCD_WAIT_TIME);

#ifdef GC_9A01
    lcd = qp_gc9a01_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
#else
    lcd = qp_st7789_make_spi_device(LCD_HEIGHT, LCD_WIDTH, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, LCD_SPI_DIVISOR, SPI_MODE);
#endif
    qp_init(lcd, LCD_ROTATION);

// Some screens have inverted colors
#ifdef LCD_INVERT_COLOR
    qp_comms_start(lcd);
    qp_comms_command(lcd, ST77XX_CMD_INVERT_ON);
    qp_comms_stop(lcd);
#endif

    // Display offset
    qp_set_viewport_offsets(lcd, LCD_OFFSET_X, LCD_OFFSET_Y);

    // Power on display, fill with white
    qp_power(lcd, 1);
    qp_rect(lcd, 0, 0, LCD_HEIGHT, LCD_WIDTH, HSV_WHITE, 1);

    // Paint catpaste/Katten Paste
    painter_image_handle_t logo_image = qp_load_image_mem(gfx_design);
    painter_image_handle_t ani_image  = qp_load_image_mem(gfx_animation);

    qp_drawimage(lcd, 0, 0, logo_image);
    qp_animate(lcd, 80, 0, ani_image);

    keyboard_post_init_user();
}

/* default encoder keys */
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        return false;
    }
    if (index == 0) {
        if (clockwise) {
            tap_code_delay(KC_VOLU, 10);
        } else {
            tap_code_delay(KC_VOLD, 10);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code_delay(KC_RIGHT, 10);
        } else {
            tap_code_delay(KC_LEFT, 10);
        }
    }
    return true;
}
