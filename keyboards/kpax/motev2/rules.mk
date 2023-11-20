SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor


ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes

HAPTIC_ENABLE = yes
# HAPTIC_DRIVER = drv2605l
HAPTIC_DRIVER = solenoid


RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = ws2812
WS2812_DRIVER = vendor

AUDIO_ENABLE = yes
AUDIO_DRIVER = pwm_hardware

BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes            # Enable N-Key Rollover


# RP2040-specific options
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

# POINTING_DEVICE_ENABLE = yes
# POINTING_DEVICE_DRIVER = cirque_pinnacle_spi
POINTING_DEVICE_DRIVER = adns5050



