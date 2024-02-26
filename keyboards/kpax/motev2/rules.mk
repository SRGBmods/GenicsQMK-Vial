SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

# 打开旋钮编码器
ENCODER_ENABLE ?= no
ifeq ($(strip $(ENCODER_ENABLE)), yes)
  ENCODER_MAP_ENABLE = yes
  VIAL_ENCODERS_ENABLE = yes
endif
# 打开lcd和lvgl
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = gc9a01_spi
# 引用lvgl文件
SRC += lvgl_helpers.c \
	   display.c

# 打开rgb灯光

# RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGB_MATRIX_ENABLE ?= no      # not supported yet, but will add
RGB_MATRIX_DRIVER = WS2812
WS2812_DRIVER = vendor
# BACKLIGHT_ENABLE = yes
ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
   VIALRGB_ENABLE := yes  # not required, but enabling for mouse button keys
   RGB_MATRIX_CUSTOM_KB = yes
   OPT_DEFS += -DRGB_MATRIX_CUSTOM_KB
endif


# 打开震动功能
HAPTIC_ENABLE ?= no
HAPTIC_DRIVER = drv2605l
# HAPTIC_DRIVER = solenoid


# 打开音频功能
AUDIO_ENABLE ?= no
AUDIO_DRIVER = pwm_hardware
# 打开点设备
POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
# POINTING_DEVICE_DRIVER = adns5050
POINTING_DEVICE_DRIVER = pmw3389
# POINTING_DEVICE_DRIVER = azoteq_iqs5xx


# 打开附加功能
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys6
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = yes         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover


# # RP2040-specific options
# PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.


# 加入oled显示屏
# OLED_ENABLE = no
# OLED_DRIVER = SSD1306
# OLED_TRANSPORT = i2c
# 下面选项选一个或者不选
TRACKBALL ?= no
CIRQUE ?= no

ifeq ($(strip $(TRACKBALL)), yes)
   PMW3360_ENABLE = yes
   OPT_DEFS += -DFP_TRACKBALL_BOTH
endif
ifeq ($(strip $(CIRQUE)), yes)
   CIRQUE_ENABLE = yes
   OPT_DEFS += -DFP_CIRQUE_BOTH
endif


ifeq ($(strip $(CIRQUE_ENABLE)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := cirque_pinnacle_spi
   OPT_DEFS += -DCIRQUE_ENABLE
endif

ifeq ($(strip $(PMW3360_ENABLE)), yes)
   POINTING_DEVICE_ENABLE := yes
   POINTING_DEVICE_DRIVER := pmw3360
   QUANTUM_LIB_SRC += spi_master.c
   OPT_DEFS += -DFP_TRACKBALL_ENABLE
endif




include keyboards/fingerpunch/src/rules.mk
