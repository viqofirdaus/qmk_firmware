#pragma once
#define MASTER_RIGHT
#define USE_SERIAL_PD2

#define OLED_TIMEOUT 250
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 3

#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 150
#define AUTO_SHIFT_TIMEOUT 150

// Liyang's fork on Kinetic Mouse
// Using Liyang's mousekey.c & mousekey.h custom build
// https://github.com/liyang/qmk_firmware/blob/develop/kinetic/docs/feature_mouse_keys.md
#define MK_VARIANT MK_TYPE_KINETIC
#define MK_KINETIC_WHEEL_MAXS 3

#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/lily58/keymaps/kotakerdus/glcdfont_kotakerdus.c"
