// Copyright 2023 zzeneg (@zzeneg)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "zzeneg_display.h"
#include "display.h"
#include "raw_hid.h"
#include "lvgl_helpers.h"

uint16_t home_screen_timer = 0;

/* screens */
static lv_obj_t *ui_home;
// static lv_obj_t *screen_volume;
// static lv_obj_t *screen_media;

/* home screen content */
// static lv_obj_t *label_time;
// static lv_obj_t *label_volume_home;
static lv_obj_t *label_shift;
static lv_obj_t *label_ctrl;
static lv_obj_t *label_alt;
static lv_obj_t *label_gui;
static lv_obj_t *label_layer;
static lv_obj_t *label_caps;
static lv_obj_t *label_caps_word;
static lv_obj_t *label_wpm;
// static lv_obj_t *icon_layout;

/* volume screen content */
// static lv_obj_t *arc_volume;
// static lv_obj_t *label_volume_arc;

/* media screen content */
// static lv_obj_t *label_media_artist;
// static lv_obj_t *label_media_title;
// 声明图片资源
LV_IMG_DECLARE(flag_ru);
LV_IMG_DECLARE(flag_uk);
LV_IMG_DECLARE(_my_logoalpha_alpha_150x150);
LV_IMG_DECLARE(_ui_logo_alpha_240x240);
LV_IMG_DECLARE(_ui_pikaqiu_alpha_240x240);
LV_IMG_DECLARE(_ui_twoman_alpha_240x240);
LV_IMG_DECLARE(animation_small);

// LV_IMG_DECLARE(idle_animimg_1animation_small_0);
// LV_IMG_DECLARE(idle_animimg_1animation_small_1);
// LV_IMG_DECLARE(idle_animimg_1animation_small_2);
// LV_IMG_DECLARE(idle_animimg_1animation_small_3);
// LV_IMG_DECLARE(idle_animimg_1animation_small_4);
// LV_IMG_DECLARE(idle_animimg_1animation_small_5);
// LV_IMG_DECLARE(idle_animimg_1animation_small_6);
// LV_IMG_DECLARE(idle_animimg_1animation_small_7);
// LV_IMG_DECLARE(idle_animimg_1animation_small_8);
// LV_IMG_DECLARE(idle_animimg_1animation_small_9);
// LV_IMG_DECLARE(idle_animimg_1animation_small_10);
// LV_IMG_DECLARE(idle_animimg_1animation_small_11);
// LV_IMG_DECLARE(idle_animimg_1animation_small_12);
// LV_IMG_DECLARE(idle_animimg_1animation_small_13);
// LV_IMG_DECLARE(idle_animimg_1animation_small_14);
// LV_IMG_DECLARE(idle_animimg_1animation_small_15);
// LV_IMG_DECLARE(idle_animimg_1animation_small_16);
// LV_IMG_DECLARE(idle_animimg_1animation_small_17);
// LV_IMG_DECLARE(idle_animimg_1animation_small_18);
// LV_IMG_DECLARE(idle_animimg_1animation_small_19);
// LV_IMG_DECLARE(idle_animimg_1animation_small_20);
// LV_IMG_DECLARE(idle_animimg_1animation_small_21);
// LV_IMG_DECLARE(idle_animimg_1animation_small_22);
// LV_IMG_DECLARE(idle_animimg_1animation_small_23);
// LV_IMG_DECLARE(idle_animimg_1animation_small_24);
// LV_IMG_DECLARE(idle_animimg_1animation_small_25);
// LV_IMG_DECLARE(idle_animimg_1animation_small_26);
// LV_IMG_DECLARE(idle_animimg_1animation_small_27);
// LV_IMG_DECLARE(idle_animimg_1animation_small_28);
// LV_IMG_DECLARE(idle_animimg_1animation_small_29);
// LV_IMG_DECLARE(idle_animimg_1animation_small_30);
// LV_IMG_DECLARE(idle_animimg_1animation_small_31);
// LV_IMG_DECLARE(idle_animimg_1animation_small_32);
// LV_IMG_DECLARE(idle_animimg_1animation_small_33);
// LV_IMG_DECLARE(idle_animimg_1animation_small_34);
// LV_IMG_DECLARE(idle_animimg_1animation_small_35);
// LV_IMG_DECLARE(idle_animimg_1animation_small_36);
// LV_IMG_DECLARE(idle_animimg_1animation_small_37);
// LV_IMG_DECLARE(idle_animimg_1animation_small_38);
// LV_IMG_DECLARE(idle_animimg_1animation_small_39);
// LV_IMG_DECLARE(idle_animimg_1animation_small_40);
// LV_IMG_DECLARE(idle_animimg_1animation_small_41);
// LV_IMG_DECLARE(idle_animimg_1animation_small_42);
// LV_IMG_DECLARE(idle_animimg_1animation_small_43);
// LV_IMG_DECLARE(idle_animimg_1animation_small_44);
// LV_IMG_DECLARE(idle_animimg_1animation_small_45);
// LV_IMG_DECLARE(idle_animimg_1animation_small_46);
// LV_IMG_DECLARE(idle_animimg_1animation_small_47);

// static const lv_img_dsc_t * idle_animimg_1_imgs[48] = {
// 	&idle_animimg_1animation_small_0,
// 	&idle_animimg_1animation_small_1,
// 	&idle_animimg_1animation_small_2,
// 	&idle_animimg_1animation_small_3,
// 	&idle_animimg_1animation_small_4,
// 	&idle_animimg_1animation_small_5,
// 	&idle_animimg_1animation_small_6,
// 	&idle_animimg_1animation_small_7,
// 	&idle_animimg_1animation_small_8,
// 	&idle_animimg_1animation_small_9,
// 	&idle_animimg_1animation_small_10,
// 	&idle_animimg_1animation_small_11,
// 	&idle_animimg_1animation_small_12,
// 	&idle_animimg_1animation_small_13,
// 	&idle_animimg_1animation_small_14,
// 	&idle_animimg_1animation_small_15,
// 	&idle_animimg_1animation_small_16,
// 	&idle_animimg_1animation_small_17,
// 	&idle_animimg_1animation_small_18,
// 	&idle_animimg_1animation_small_19,
// 	&idle_animimg_1animation_small_20,
// 	&idle_animimg_1animation_small_21,
// 	&idle_animimg_1animation_small_22,
// 	&idle_animimg_1animation_small_23,
// 	&idle_animimg_1animation_small_24,
// 	&idle_animimg_1animation_small_25,
// 	&idle_animimg_1animation_small_26,
// 	&idle_animimg_1animation_small_27,
// 	&idle_animimg_1animation_small_28,
// 	&idle_animimg_1animation_small_29,
// 	&idle_animimg_1animation_small_30,
// 	&idle_animimg_1animation_small_31,
// 	&idle_animimg_1animation_small_32,
// 	&idle_animimg_1animation_small_33,
// 	&idle_animimg_1animation_small_34,
// 	&idle_animimg_1animation_small_35,
// 	&idle_animimg_1animation_small_36,
// 	&idle_animimg_1animation_small_37,
// 	&idle_animimg_1animation_small_38,
// 	&idle_animimg_1animation_small_39,
// 	&idle_animimg_1animation_small_40,
// 	&idle_animimg_1animation_small_41,
// 	&idle_animimg_1animation_small_42,
// 	&idle_animimg_1animation_small_43,
// 	&idle_animimg_1animation_small_44,
// 	&idle_animimg_1animation_small_45,
// 	&idle_animimg_1animation_small_46,
// 	&idle_animimg_1animation_small_47,
// };
/* can be replaced with PL flag (update rules.mk as well) */
// LV_IMG_DECLARE(flag_pl);

// enum layout { _EN = 0, _RU };
// void set_layout_icon(uint8_t layout) {
//     switch (layout) {
//         case _EN:
//             lv_img_set_src(icon_layout, &flag_uk);
//             break;

//         case _RU:
//             lv_img_set_src(icon_layout, &flag_ru);
//             break;
//     }
// }

// void read_string(uint8_t *data, char *string_data) {
//     uint8_t data_length = data[1];
//     memcpy(string_data, data + 2, data_length);
//     string_data[data_length] = '\0';
// }

// void start_home_screen_timer(void) {
//     dprint("reset home screen\n");
//     home_screen_timer = timer_read();
// }

void init_ui_home_custom(void) {
    ui_home = lv_scr_act();
    lv_obj_add_style(ui_home, &style_screen, 0);
    lv_obj_clear_flag(ui_home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // use_flex_column(ui_home);

    // label_volume_home = lv_label_create(ui_home);
    // lv_label_set_text(label_volume_home, "");
// 增加图片
    lv_obj_t *img = lv_img_create(ui_home);
    lv_img_set_src(img, &_ui_logo_alpha_240x240);
    lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_center(img);



// 增加c播放动画
	// lv_obj_t *ani2 = lv_animimg_create(ui_home);
    // lv_animimg_set_src(ani2, (lv_img_dsc_t**)idle_animimg_1_imgs, 48);
	// lv_animimg_set_duration(ani2, 90*48);
	// lv_animimg_set_repeat_count(ani2, LV_ANIM_REPEAT_INFINITE);
	// lv_animimg_start(ani2);
	// lv_obj_set_pos(ani2, 88, 88);
	// lv_obj_set_size(ani2, 64, 64);
// 增加普通gif动画
    // lv_obj_t *ani = lv_gif_create(ui_home);
    // lv_gif_set_src(ani, &animation_small);
    // lv_obj_clear_flag(ani, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_center(ani);
    // lv_obj_align(ani, LV_ALIGN_LEFT_MID, 20, 0);


//增加圆圈动画
	lv_obj_t *ring = lv_spinner_create(ui_home,6000,120);
	lv_obj_set_size(ring, 240, 240);
	lv_obj_center(ring);
    lv_obj_set_align(ring, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ring, LV_OBJ_FLAG_CLICKABLE);      /// Flags
    lv_obj_set_style_arc_color(ring, lv_color_hex(0x00FF03), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ring, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ring, 4, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ring, lv_color_hex(0x0077FF), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ring, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ring, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);

// 分割
    // lv_spinner_set_anim_params(ring, 10000, 200);

    // lv_obj_t *mods = lv_obj_create(ui_home);
    // lv_obj_add_style(mods, &style_container, 0);
    // lv_obj_center(mods);
    // lv_obj_set_width(mods, 100);
    // lv_obj_set_height(mods, 50);
    // lv_obj_set_x(mods, 0);
    // lv_obj_set_y(mods, 76);
    // lv_obj_clear_flag(mods, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // use_flex_row(mods);

    lv_obj_t *ui_mods = lv_obj_create(ui_home);
	lv_obj_set_pos(ui_mods, 45, 180);
	lv_obj_set_size(ui_mods, 150, 20);
	lv_obj_set_scrollbar_mode(ui_mods, LV_SCROLLBAR_MODE_OFF);
    use_flex_row(ui_mods);

	//Write style for home_ui_mods, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui_mods, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui_mods, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui_mods, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui_mods, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui_mods, 0, LV_PART_MAIN|LV_STATE_DEFAULT);


    label_ctrl  = create_button(ui_mods, "CTL", &style_button, &style_button_active);
    label_alt   = create_button(ui_mods, "ALT", &style_button, &style_button_active);
    label_shift = create_button(ui_mods, "SFT", &style_button, &style_button_active);
    label_gui   = create_button(ui_mods, "GUI", &style_button, &style_button_active);



    // label_time = lv_label_create(ui_home);
    // lv_label_set_text(label_time, "00:00");
    // lv_obj_set_style_text_font(label_time, &montserrat_48_digits, LV_PART_MAIN);

    // lv_obj_t *caps = lv_obj_create(ui_home);
    // lv_obj_add_style(caps, &style_container, 0);
    // use_flex_row(caps);

    // label_caps      = create_button(caps, "CAPS", &style_button, &style_button_active);
    // label_caps_word = create_button(caps, "CAPS WORD", &style_button, &style_button_active);

    // lv_obj_t *bottom_row = lv_obj_create(ui_home);
    // lv_obj_add_style(bottom_row, &style_container, 0);
// 创建层名称物体
    label_layer = lv_label_create(ui_home);
    lv_label_set_text(label_layer, "");
    lv_label_set_long_mode(label_layer, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(label_layer, 71, 201);
	lv_obj_set_size(label_layer, 98, 18);
//Write style for home_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(label_layer, lv_color_hex(0xd4d7ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(label_layer, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(label_layer, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(label_layer, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(label_layer, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    display_process_layer_state(0);
// 增加wpm显示
    label_wpm = lv_label_create(ui_home);
    lv_label_set_text(label_wpm, "");
    lv_label_set_long_mode(label_wpm, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(label_wpm, 25, 142);
	lv_obj_set_size(label_wpm, 98, 18);
    lv_obj_set_style_border_width(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(label_wpm, lv_color_hex(0xd4d7ff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(label_wpm, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(label_wpm, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(label_wpm, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(label_wpm, 0, LV_PART_MAIN|LV_STATE_DEFAULT);



    // icon_layout = lv_img_create(bottom_row);
    // lv_obj_set_style_radius(icon_layout, 4, 0);
    // lv_obj_set_style_clip_corner(icon_layout, true, 0);
    // lv_obj_align(icon_layout, LV_ALIGN_RIGHT_MID, -10, 0);

    // 增加图片两个人
    // lv_obj_t *img = lv_img_create(ui_home);
    // lv_img_set_src(img, &_ui_twoman_alpha_240x240);
    // lv_obj_clear_flag(img, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_obj_center(img);

}

// void init_screen_volume(void) {
//     screen_volume = lv_obj_create(NULL);
//     lv_obj_add_style(screen_volume, &style_screen, 0);

//     arc_volume = lv_arc_create(screen_volume);
//     lv_obj_set_size(arc_volume, 200, 200);
//     lv_obj_center(arc_volume);

//     label_volume_arc = lv_label_create(screen_volume);
//     lv_label_set_text(label_volume_arc, "00");
//     lv_obj_set_style_text_font(label_volume_arc, &montserrat_48_digits, LV_PART_MAIN);
//     lv_obj_center(label_volume_arc);

//     lv_obj_t *volume_text_label = lv_label_create(screen_volume);
//     lv_label_set_text(volume_text_label, "Volume");
//     lv_obj_align(volume_text_label, LV_ALIGN_BOTTOM_MID, 0, -10);
// }

// void init_screen_media(void) {
//     screen_media = lv_obj_create(NULL);
//     lv_obj_add_style(screen_media, &style_screen, 0);
//     use_flex_column(screen_media);
//     lv_obj_set_flex_align(screen_media, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

//     label_media_artist = lv_label_create(screen_media);
//     lv_label_set_text(label_media_artist, "N/A");
//     lv_label_set_long_mode(label_media_artist, LV_LABEL_LONG_WRAP);
//     lv_obj_set_width(label_media_artist, lv_pct(90));
//     lv_obj_set_style_text_align(label_media_artist, LV_TEXT_ALIGN_CENTER, 0);

//     label_media_title = lv_label_create(screen_media);
//     lv_label_set_text(label_media_title, "N/A");
//     lv_label_set_long_mode(label_media_title, LV_LABEL_LONG_WRAP);
//     lv_obj_set_width(label_media_title, lv_pct(90));
//     lv_obj_set_style_text_align(label_media_title, LV_TEXT_ALIGN_CENTER, 0);
// }



bool display_init_user(void) {
    init_ui_home_custom();
    // init_screen_volume();
    // init_screen_media();

    return false;
}

// void display_process_raw_hid_data(uint8_t *data, uint8_t length) {
//     uint8_t data_type = data[0];
//     char    string_data[length - 2];
//     dprintf("display_process_raw_hid_data - received data_type %u \n", data_type);
//     switch (data_type) {
//         // case _TIME:
//         //     dprintf("time %02d:%02d\n", data[1], data[2]);
//         //     lv_label_set_text_fmt(label_time, "%02d:%02d", data[1], data[2]);
//         //     break;

//         // case _VOLUME:
//         //     dprintf("volume %d\n", data[1]);
//         //     lv_label_set_text_fmt(label_volume_home, "Volume: %02d%%", data[1]);
//         //     lv_label_set_text_fmt(label_volume_arc, "%02d", data[1]);
//         //     lv_arc_set_value(arc_volume, data[1]);
//         //     lv_scr_load(screen_volume);
//         //     start_home_screen_timer();
//         //     break;

//         // case _LAYOUT:
//         //     dprintf("layout %d\n", data[1]);
//         //     set_layout_icon(data[1]);
//         //     break;

//         case _MEDIA_ARTIST:
//             read_string(data, string_data);
//             dprintf("media artist %s\n", string_data);
//             lv_label_set_text(label_media_artist, string_data);
//             lv_scr_load(screen_media);
//             start_home_screen_timer();
//             break;

//         case _MEDIA_TITLE:
//             read_string(data, string_data);
//             dprintf("media title %s\n", string_data);
//             lv_label_set_text(label_media_title, string_data);
//             lv_scr_load(screen_media);
//             start_home_screen_timer();
//             break;
//     }
// }

void display_process_layer_state(uint8_t layer) {
    switch (layer) {
        case _QWERTY:
            lv_label_set_text(label_layer, "QWERTY");
            break;
        case _POINT:
            lv_label_set_text(label_layer, "POINT");
            break;
        case _GAME:
            lv_label_set_text(label_layer, "GAME");
            break;
        case _NAV:
            lv_label_set_text(label_layer, "NAV");
            break;
        case _NUMBER:
            lv_label_set_text(label_layer, "NUMBER");
            break;
        case _SYMBOL:
            lv_label_set_text(label_layer, "SYMBOL");
            break;
        case _FUNC:
            lv_label_set_text(label_layer, "FUNC");
            break;
        case _SYS:
            lv_label_set_text(label_layer, "SYSTEM");
            break;
    }
}

void display_housekeeping_task(void) {
    if (home_screen_timer && timer_elapsed(home_screen_timer) > 5000) {
        home_screen_timer = 0;
        lv_scr_load(ui_home);
    }

    toggle_state(label_shift, LV_STATE_PRESSED, MODS_SHIFT);
    toggle_state(label_ctrl, LV_STATE_PRESSED, MODS_CTRL);
    toggle_state(label_alt, LV_STATE_PRESSED, MODS_ALT);
    toggle_state(label_gui, LV_STATE_PRESSED, MODS_GUI);

}

void display_process_caps(bool active) {
    toggle_state(label_caps, LV_STATE_PRESSED, active);
}

void display_process_caps_word(bool active) {
    dprint("display_process_caps_word\n");
    toggle_state(label_caps_word, LV_STATE_PRESSED, active);
}
