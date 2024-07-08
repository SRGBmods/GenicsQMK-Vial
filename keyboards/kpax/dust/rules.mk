
# 打开旋钮编码器
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
# 打开lcd和lvgl
QUANTUM_PAINTER_ENABLE = no
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
QUANTUM_PAINTER_DRIVERS = gc9a01_spi
# 引用lvgl文件

# 打开rgb灯光
# RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor
BACKLIGHT_ENABLE = yes

# 打开震动功能
HAPTIC_ENABLE = yes
HAPTIC_DRIVER = drv2605l
# HAPTIC_DRIVER = solenoid


# 打开音频功能
AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware


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


