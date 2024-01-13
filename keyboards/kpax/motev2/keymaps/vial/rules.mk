
# 加入vial支持
VIA_ENABLE = yes
VIAL_ENABLE = yes
VIALRGB_ENABLE = yes
RAW_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
CAPS_WORD_ENABLE = yes
ENCODER_MAP_ENABLE = yes
DYNAMIC_TAPPING_TERM_ENABLE = yes

# 引用lvgl图像文件
SRC +=  zzeneg_display.c \
		fonts/montserrat_20_en_ru.c \
		fonts/montserrat_48_digits.c \
		fonts/lv_font_GOST_14.c \
		fonts/lv_font_GOST_16.c \
		icons/flag_uk.c \
		icons/flag_ru.c \
		pic/_my_logoalpha_alpha_150x150.c \
		pic/_ui_logo_alpha_240x240.c \
		pic/animation.qgf.c

