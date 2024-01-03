// Author      : kotakerdus
// Version     : 0.4.8
// Keyboard    : lily58
// OS          : Windows 10
// Description : Custom lily58 keyboard designed with left hand + mouse in mind, useful for work that demands on mouse usage like Blender,
//               Photoshop and many other design application. This layout has _SWAP layer that work like default OSL which useful for trigger
//               a shortcut but it won't end the OSL state if still holding a MOD keys
// Features    : - Auto Shift for numbers and symbols but not alphas (can be toggled)
//               - Caps Word for easy code typing by pressing KC_LSFT twice
//               - Easy access to numpad keys complete with number operators, comma, dot, equal symbol and aphostrophe within _NUMP layer which
//                 can be accessed by holding LT_NUMP key
//               - Ergonomic mouse layer by holding LT_MOUS key and if tapped it will send KC_ENT
//               - Move current active window to next monitor by pressing KC_ESC while holding SW_LSWP key
//               - Quick close app via by pressing KC_ESC while in ALT-TAB windows selection (windows only)
//               - One-shot swap layout for the left side by pressing SW_LSWP once and it won't leave the OSL state if pressed together with
//                 MOD key, useful for repeated shortcut key (e.g. CTRL + Y)
// Useful Apps : - RamonUnch AltSnap (window management app, e.g. resize/move window anywhere within the window content by pressing KC_LGUI key)
//               - Snipaste (quick screenshot app that is able to pin the screenshot on screen)

#include QMK_KEYBOARD_H
enum layer_number {
    _QWER = 0,
    _SWAP, _NUMP, _LNAV, _RNAV, _MOUS
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

// KC_ESC                          // MOD + KC_ESC = MOD + KC_GRV | SW_LSWP + KC_ESC = G(S(KC_RGHT)) | KC_DEL in alt-tabbing mode
// KC_LCTL                         // S(KC_TAB) in alt-tabbing mode
#define SP_SNIP KC_F13             // Snipaste screenshot shortcut
#define SW_LSWP LGUI_T(XXXXXXX)    // LGUI_T(OSL(_SWAP)) | Can be hold-and-press KC_LALT or LT_NUMP to switch between virtual desktops
#define SW_RSWP RGUI_T(XXXXXXX)
#define SW_RCTL RCTL_T(KC_QUOT)
#define SW_RSFT RSFT_T(KC_EQL)
#define SW_NUMP LT(_NUMP, KC_DEL)
#define NM_LCTL LCTL_T(KC_NUM)
#define NM_LSFT SC_LSPO
#define NM_LALT LALT_T(KC_MPRV)
#define NM_LGUI LGUI_T(KC_MNXT)
#define NM_LNAV LT(_LNAV, KC_DEL)
#define LT_NUMP LT(_NUMP, KC_BSPC)
#define LT_RNAV LT(_RNAV, KC_DEL)
#define LT_MOUS LT(_MOUS, KC_ENT)

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWER] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_EQL ,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        KC_LALT, SW_LSWP, LT_NUMP, KC_SPC ,       LT_MOUS, LT_RNAV, KC_RGUI, KC_RALT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_SWAP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_BSLS, KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MINS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             SW_RCTL, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             SW_RSFT, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   , KC_RBRC,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        KC_RALT, SW_RSWP, SW_NUMP, LT_MOUS,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_NUMP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             SP_SNIP, KC_PDOT, KC_P7  , KC_P8  , KC_P9  , KC_PPLS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             NM_LCTL, NM_LNAV, KC_P4  , KC_P5  , KC_P6  , KC_PMNS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             NM_LSFT, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_RPRN,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        NM_LALT, NM_LGUI, _______, KC_MPLY,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_LNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_SLEP, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LCTL, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSFT, KC_VOLD, KC_HOME, XXXXXXX, KC_END , KC_ENT , _______,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        KC_LALT, KC_LGUI, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_RNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_PSCR,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 , KC_SCRL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , KC_INS ,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       KC_LPRN, KC_VOLD, KC_HOME, XXXXXXX, KC_END , KC_APP , KC_RPRN,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUS] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,                         XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_R, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                         XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, KC_BTN4, KC_WH_D, KC_BTN5, XXXXXXX, XXXXXXX,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_LGUI, KC_BSPC, _______,       _______, KC_DEL , _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

bool tabbing = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    switch (keycode) {
        case KC_ESC:
        case KC_TAB:
        case KC_LCTL:
            if (record -> event.pressed) {
                if (keycode == KC_ESC) {
                    if (tabbing) {
                        tap_code(KC_DEL); // Close window while in ALT-TAB in Windows
                        return false;
                    } else if (mods == MOD_BIT(KC_LGUI)) {
                        tap_code16(S(KC_RGHT)); // G(S(KC_RGHT)) - Move current window to next monitor
                        return false;
                    } else if (layer_state_is(_QWER) && (mods & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT) | MOD_BIT(KC_LGUI)))) {
                        tap_code(KC_GRV); // For MOD + KC_ESC (e.g. KC_LALT + KC_ESC) can be triggered in _MOUS layer
                        return false;
                    }
                } else if (keycode == KC_LCTL && tabbing) {
                    tap_code16(S(KC_TAB));
                    return false;
                } else if (keycode == KC_TAB && (mods & (MOD_BIT(KC_LALT)))) tabbing = true;
            } break;
        case SW_LSWP:
        case SW_RSWP:
            if (record -> tap.count && record -> event.pressed) {
                layer_invert(_SWAP);
                return false;
            } else if (layer_state_is(_SWAP) && (mods & MOD_MASK_GUI)) layer_off(_SWAP);
            break;
        case KC_LALT:
        case LT_NUMP:
            if (record -> event.pressed && (mods & MOD_BIT(KC_LGUI))) {
                if      (keycode == KC_LALT) tap_code16(C(KC_LEFT)); // G(C(KC_LEFT)) - Switch to left desktop
                else if (keycode == LT_NUMP) tap_code16(C(KC_RGHT)); // G(C(KC_RGHT)) - Switch to right desktop
                return false;
            } else if (keycode == KC_LALT && tabbing) tabbing = false;
            break;
        default:
            if (!(record -> event.pressed) && layer_state_is(_SWAP)) {
                if (!(mods)) layer_off(_SWAP); // Exit _SWAP layer if no other mod keys are being held
                else if (keycode == SW_RCTL && (mods & MOD_MASK_CTRL))  layer_off(_SWAP);
                else if (keycode == SW_RSFT && (mods & MOD_MASK_SHIFT)) layer_off(_SWAP);
                else if (keycode == KC_RALT && (mods & MOD_MASK_ALT))   layer_off(_SWAP);
                else if (keycode == KC_RGUI && (mods & MOD_MASK_GUI))   layer_off(_SWAP);
            }
    }

    return true;
}

#ifdef AUTO_SHIFT_ENABLE

// A U T O  S H I F T |-------------------------------------------------------------------------------------------------------------------------

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_PMNS:
        case KC_PPLS:
        case KC_PENT:
        case KC_PDOT:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_PMNS: register_code16((!shifted) ? KC_PMNS : KC_PSLS); break;
        case KC_PPLS: register_code16((!shifted) ? KC_PPLS : KC_PAST); break;
        case KC_PENT: register_code16((!shifted) ? KC_PENT : KC_EQL);  break;
        case KC_PDOT: register_code16((!shifted) ? KC_PDOT : KC_COMM); break;
        default:
            if (shifted) add_weak_mods(MOD_BIT(KC_LSFT));
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_PMNS: unregister_code16((!shifted) ? KC_PMNS : KC_PSLS); break;
        case KC_PPLS: unregister_code16((!shifted) ? KC_PPLS : KC_PAST); break;
        case KC_PENT: unregister_code16((!shifted) ? KC_PENT : KC_EQL);  break;
        case KC_PDOT: unregister_code16((!shifted) ? KC_PDOT : KC_COMM); break;
        default: unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

#endif // AUTO_SHIFT_ENABLE

#ifdef CAPS_WORD_ENABLE

// C A P S  W O R D |---------------------------------------------------------------------------------------------------------------------------
// https://docs.qmk.fm/#/feature_caps_word

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_P1 ... KC_P0:
        case KC_RGHT ... KC_UP:
        case KC_MINS ... KC_SLSH:
        case MODIFIER_KEYCODE_RANGE:
        case LT_NUMP:
        case LT_RNAV:
        case NM_LSFT:
        case NM_LNAV:
        case KC_LPRN:
        case KC_RPRN:
            return true;
        // Other key will deactive the Caps Word.
        default:
            return false;
    }
}

#endif // CAPS_WORD_ENABLE

#ifdef OLED_ENABLE

// O L E D   I N T E R F A C E |----------------------------------------------------------------------------------------------------------------

void render_tawheed(void) {
    static const char PROGMEM tawheed[] = {
        0x20, 0x21, 0x22, 0x23, 0x24,
        0x40, 0x41, 0x42, 0x43, 0x44,
        0x60, 0x61, 0x62, 0x63, 0x64,
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,
        0x25, 0x26, 0x27, 0x28, 0x29,
        0x45, 0x46, 0x47, 0x48, 0x49,
        0x65, 0x66, 0x67, 0x68, 0x69,
        0x85, 0x86, 0x87, 0x88, 0x89,
        0xa5, 0xa6, 0xa7, 0xa8, 0xa9,
        0xc5, 0xc6, 0xc7, 0xc8, 0xc9,
        0x2a, 0x2b, 0x2c, 0x2d, 0x2e,
        0x4a, 0x4b, 0x4c, 0x4d, 0x4e,
        0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
        0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0
    };

    oled_write_P(tawheed, false);
}

void render_master(void) {
    static const char PROGMEM lily58[] = {
        0xaa, 0xab, 0xac, 0xad, 0xae,
        0xca, 0xcb, 0xcc, 0xcd, 0xce,
        0x0f, 0x10, 0x11, 0x12, 0x13,
        0x2f, 0x30, 0x31, 0x32, 0x33,
        0x4f, 0x50, 0x51, 0x52, 0x53,
        0x6f, 0x70, 0x71, 0x72, 0x73,
        0x8f, 0x90, 0x91, 0x92, 0x93,
        0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0
    };

    static const char PROGMEM separator[2][11] = {
        { 0xdf, 0x1d, 0x1e, 0x1f, 0xdf,
          0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0 }, // Normal (0)
        { 0xdf, 0x3d, 0x3e, 0x3f, 0xdf,
          0xdf, 0x5d, 0x5e, 0x5f, 0xdf, 0 }  // Caps   (1)
    };

    static const char PROGMEM layer_state[5][6] = {
        { 0x14, 0x15, 0x16, 0x17, 0x18, 0 }, // QWER        (0)
        { 0x34, 0x35, 0x36, 0x37, 0x38, 0 }, // SWAP        (1)
        { 0x54, 0x55, 0x56, 0x57, 0x58, 0 }, // NUMP        (2)
        { 0x74, 0x75, 0x76, 0x77, 0x78, 0 }, // LNAV / RNAV (3)
        { 0x94, 0x95, 0x96, 0x97, 0x98, 0 }  // MOUS        (4)
    };

    static const char PROGMEM mod_blank[]          = { 0xdf, 0xdf, 0 };
    static const char PROGMEM mod_gui[2][3]        = {{ 0x19, 0x1a, 0 }, { 0x39, 0x3a, 0 }};
    static const char PROGMEM mod_alt[2][3]        = {{ 0x1b, 0x1c, 0 }, { 0x3b, 0x3c, 0 }};
    static const char PROGMEM mod_ctrl[2][3]       = {{ 0x59, 0x5a, 0 }, { 0x79, 0x7a, 0 }};
    static const char PROGMEM mod_shift[2][3]      = {{ 0x5b, 0x5c, 0 }, { 0x7b, 0x7c, 0 }};
    static const char PROGMEM mod_shift_auto[2][3] = {{ 0x99, 0x9a, 0 }, { 0xb9, 0xba, 0 }};

    // Start render --------------------------------------------------------------------------------------

    // Lily58 logo and CAPS/divider section
    oled_write_P(lily58, false);
    if (host_keyboard_led_state().caps_lock || is_caps_word_on()) oled_write_P(separator[1], false);
    else                                                          oled_write_P(separator[0], false);

    // Layer names
    if      (layer_state_is(_MOUS))                          oled_write_P(layer_state[4], false);
    else if (layer_state_is(_LNAV) || layer_state_is(_RNAV)) oled_write_P(layer_state[3], false);
    else if (layer_state_is(_NUMP))                          oled_write_P(layer_state[2], false);
    else if (layer_state_is(_SWAP))                          oled_write_P(layer_state[1], false);
    else                                                     oled_write_P(layer_state[0], false);

    // Mods
    const uint8_t mods = get_mods();
    oled_write_P(mods & MOD_MASK_GUI  ? mod_gui[0]  : mod_blank, false);
    oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT  ? mod_alt[0]  : mod_blank, false);
    oled_write_P(mods & MOD_MASK_GUI  ? mod_gui[1]  : mod_blank, false);
    oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT  ? mod_alt[1]  : mod_blank, false);
    oled_write_P(mods & MOD_MASK_CTRL ? mod_ctrl[0] : mod_blank, false);
    oled_advance_char();
    if (get_autoshift_state()) oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift_auto[0] : mod_blank, false);
    else                       oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[0]      : mod_blank, false);
    oled_write_P(mods & MOD_MASK_CTRL ? mod_ctrl[1] : mod_blank, false);
    oled_advance_char();
    if (get_autoshift_state()) oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift_auto[1] : mod_blank, false);
    else                       oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[1]      : mod_blank, false);

    // End of render -------------------------------------------------------------------------------------
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_90;
}

bool oled_task_user() {
    if (is_keyboard_master()) render_master();
    else                      render_tawheed();
    return false;
}

void suspend_power_down_user() {
    oled_off();
}

#endif // OLED_ENABLE
