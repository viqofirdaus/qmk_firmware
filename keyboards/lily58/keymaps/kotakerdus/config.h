#pragma once
#define MASTER_RIGHT
#define USE_SERIAL_PD2

#define OLED_TIMEOUT 250
#define OLED_FADE_OUT
#define OLED_FADE_OUT_INTERVAL 3

#define AUTO_SHIFT_TIMEOUT 150

// Make sure using Liyang's mousekey.c and mousekey.h files
#define MK_VARIANT MK_TYPE_KINETIC
#define MK_KINETIC_WHEEL_MAXS 2

#undef OLED_FONT_H
#define OLED_FONT_H "keyboards/lily58/keymaps/kotakerdus/glcdfont_kotakerdus.c"
