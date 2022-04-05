/*
* Author      : kotakerdus
* Version     : 0.2.0
* OS          : Windows 10
* Keyboard    : lily58
* Description : Custom lily58 keyboard focusing on left hand layout + mouse, useful for design application like Blender, Photoshop and many
*               other design application. This layout has _SWAP layer that work like QMK's OSL which useful for trigger a shortcut without
*               having to reach the other half of the keyboard.
*/

#include QMK_KEYBOARD_H
enum layer_number {
    _QWERTY = 0,
    _SWAP, _NUM, _LNAV, _RNAV, _MOUSE
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    MD_LCTL = SAFE_RANGE, // KC_LCTL           | KC_CAPS in _NUM | Toggle _SWAP if tapped (OSL-like)   | KC_QUOT in _SWAP & turn it off
    MD_LSFT,              // KC_LSFT           | S(KC_9) in _NUM (open parentheses)                    | KC_EQL  in _SWAP & turn it off
    MD_LALT,              // KC_LALT           | G(C(KC_LEFT)) if LGUI-tapped (slide to left desktop)  | Turn off _SWAP if tapped
    MD_LGUI,              // KC_LGUI                                                                   & Turn off _SWAP if tapped
    MD_RSFT,              // KC_SFTENT (exactly Space Cadet Shift key)
    LT_NUMP,              // LT(_NUM, KC_BSPC) | G(C(KC_RGHT)) if LGUI-tapped (slide to right desktop) | KC_DEL if SHIFT-tapped
    LT_RNAV,              // LT(_RNAV, KC_DEL)
    LT_LNAV,              // LT(_LNAV, KC_DEL)
    MS_SPED               // KC_ACL0           | KC_BTN3 if tapped
};

#define BR_PREV C(S(KC_TAB)) // Browser shortcut
#define BR_NEXT C(KC_TAB)

#define AP_CLOS A(KC_F4)     // Close window shortcut
#define SP_SNIP KC_F13       // Snipaste app shortcut to take a screenshot
#define SP_HIDE A(S(KC_F13)) // Snipaste app shortcut to hide pinned screenshots
#define VS_META A(KC_SLSH)   // VSCode MetaJump extension shortcut

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             MD_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             MD_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_EQL ,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        MD_LALT, MD_LGUI, LT_NUMP, KC_SPC ,       MD_RSFT, LT_RNAV, KC_RGUI, KC_RALT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_SWAP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_BSLS, KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MINS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   , KC_RBRC,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_NUM] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, SP_SNIP, KC_P7  , KC_P8  , KC_P9  , KC_PPLS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, LT_LNAV, KC_P4  , KC_P5  , KC_P6  , KC_PMNS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_RPRN,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_PDOT, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_LNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, SP_HIDE, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, KC_HOME, KC_MPLY, KC_END , KC_ENT , _______,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_LGUI, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_RNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , AP_CLOS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 , KC_ASTG,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, KC_VOLD, KC_HOME, KC_APP , KC_END , VS_META, KC_RPRN,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, KC_SLEP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, KC_MS_U, _______, _______,                         _______, BR_PREV, KC_WH_U, BR_NEXT, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                         _______, KC_BTN1, MS_SPED, KC_BTN2, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_BTN4, _______, KC_BTN5, _______, _______,       _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_LGUI, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

uint16_t key_timer = 0;
// Helper for quick rolling key on (MD_LCTL / MD_LSFT) + LT_NUMP
bool mod_before_numpad = false; // (ie: MD_LCTL(down) -> LT_NUMP(down) -> MD_LCTL(up) -> LT_NUMP(up) = C(KC_BSPC) instead of (KC_BSPC))
bool mod_after_numpad = false;  // (ie: LT_NUMP(down) -> MD_LSFT(down) -> LT_NUMP(up) -> MD_LSFT(up) = S(KC_9) instead of S(KC_BSPC))
// This block un-intended trigger on custom key while rolling-key on common shortcut (ie: CTRL + Z)
bool other_key_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    switch (keycode) {
        case KC_GRV:
            if (record -> event.pressed) {
                if (mods & MOD_MASK_GUI) {
                    other_key_pressed = true;
                    tap_code16(S(KC_RGHT)); // G(S(KC_RGHT)) - Move current active window to next monitor
                    return false;
                }
            } break;
        case MD_LCTL:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_NUM)) mod_after_numpad = true;
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (mod_before_numpad) tap_code(KC_BSPC); // C(KC_BSPC)
                    else if (layer_state_is(_QWERTY)) layer_on(_SWAP);
                    else if (layer_state_is(_NUM)) tap_code(KC_CAPS);
                    else if (layer_state_is(_SWAP)) {
                        del_mods(MOD_MASK_CTRL);
                        tap_code(KC_QUOT);
                        if (!(mods & ~MOD_MASK_CTRL)) layer_off(_SWAP); // Turn layer _SWAP off if only CTRL mod key is pressed
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release the this button

                unregister_code(KC_LCTL);
                mod_before_numpad = false;
                other_key_pressed = true;
            } break;
        case MD_LSFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_NUM)) mod_after_numpad = true;
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_NUM)) tap_code(KC_9);
                    else if (layer_state_is(_SWAP)) {
                        del_mods(MOD_MASK_SHIFT);
                        tap_code(KC_EQL);
                        if (!(mods & ~MOD_MASK_SHIFT)) layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);

                unregister_code(KC_LSFT);
                mod_before_numpad = false;
                other_key_pressed = true;
            } break;
        case MD_LALT:
            if (record -> event.pressed) {
                if (mods & MOD_BIT(KC_LGUI)) {
                    tap_code16(C(KC_LEFT));
                    return false;
                }

                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP) && (!(mods & ~MOD_MASK_ALT))) layer_off(_SWAP);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);
                other_key_pressed = true;
            } break;
        case MD_LGUI:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                unregister_code(KC_LGUI);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP) && (!(mods & ~MOD_MASK_GUI))) layer_off(_SWAP);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);
                other_key_pressed = true;
            } break;
        case MD_RSFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_ENT);
                other_key_pressed = true;
            } break;
        case LT_NUMP:
            if (record -> event.pressed) {
                layer_off(_SWAP);
                if (mods & MOD_BIT(KC_LGUI)) {
                    tap_code16(C(KC_RGHT));
                    return false;
                }

                other_key_pressed = false;
                if (mods & (MOD_MASK_CTRL | MOD_MASK_SHIFT)) mod_before_numpad = true;
                key_timer = timer_read();
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
                layer_off(_LNAV);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (mod_after_numpad) {
                        if (mods & MOD_MASK_CTRL) tap_code(KC_CAPS);
                        else if (mods & MOD_MASK_SHIFT) tap_code(KC_9); // S(KC_9) - Open parenthesis
                    } else tap_code(KC_BSPC);
                }

                mod_after_numpad = false;
                other_key_pressed = true;
            } break;
        case LT_RNAV:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                layer_on(_RNAV);
            } else {
                layer_off(_RNAV);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_DEL);
                other_key_pressed = true;
            } break;
        case LT_LNAV:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                layer_on(_LNAV);
            } else {
                layer_off(_LNAV);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_DEL);
                other_key_pressed = true;
            } break;
        case MS_SPED:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_ACL0);
            } else {
                unregister_code(KC_ACL0);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_BTN3);
                other_key_pressed = true;
            } break;
        default:
            if (record -> event.pressed) other_key_pressed = true;
            else if (layer_state_is(_SWAP) && (!(mods & MOD_MASK_CSAG)))
                layer_off(_SWAP); // Turn layer _SWAP off if default keys are pressed while not holding any mod key
            break;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _RNAV, _MOUSE);
}

// A U T O  S H I F T |-------------------------------------------------------------------------------------------------------------------------
// https://docs.qmk.fm/#/feature_auto_shift

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_MINUS ... KC_QUOTE:
        case KC_COMMA ... KC_SLASH:
        case KC_NONUS_BACKSLASH:
            return true;
        case KC_A ... KC_Z:
        case KC_TAB:
        case KC_GRV:
            return false; // Disable Auto Shift on these keys
    }

    return get_custom_auto_shifted_key(keycode, record);
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_PMNS ... KC_PENT: // KC_PMNS, KC_PPLS, KC_PENT
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
        case KC_PDOT: register_code16((!shifted) ? KC_PDOT : KC_COMM);  break;
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
        case KC_PDOT: unregister_code16((!shifted) ? KC_PDOT : KC_COMM);  break;
        default: unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

// O L E D   I N T E R F A C E |----------------------------------------------------------------------------------------------------------------
#ifdef OLED_ENABLE

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
        { 0xaa, 0xd0, 0xd1, 0xd2, 0xaa,
          0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0
        }, // Normal (0)
        { 0xaa, 0x1d, 0x1e, 0x1f, 0xaa,
          0xaa, 0x3d, 0x3e, 0x3f, 0xaa, 0
        } // Caps (1)
    };
    static const char PROGMEM layer_state[5][6] = {
        { 0x14, 0x15, 0x16, 0x17, 0x18, 0 }, // QWERT  (0)
        { 0x34, 0x35, 0x36, 0x37, 0x38, 0 }, // SWAP   (1)
        { 0x54, 0x55, 0x56, 0x57, 0x58, 0 }, // NUMPAD (2)
        { 0x74, 0x75, 0x76, 0x77, 0x78, 0 }, // NAVI   (3)
        { 0x94, 0x95, 0x96, 0x97, 0x98, 0 }  // MOUSE  (4)
    };

    static const char PROGMEM mod_blank[]     = { 0xaa, 0xaa, 0 };
    static const char PROGMEM mod_gui[2][3]   = {{ 0x19, 0x1a, 0 }, { 0x39, 0x3a, 0 }};
    static const char PROGMEM mod_alt[2][3]   = {{ 0x1b, 0x1c, 0 }, { 0x3b, 0x3c, 0 }};
    static const char PROGMEM mod_shift[2][3] = {{ 0x59, 0x5a, 0 }, { 0x79, 0x7a, 0 }};
    static const char PROGMEM mod_ctrl[2][3]  = {{ 0x5b, 0x5c, 0 }, { 0x7b, 0x7c, 0 }};

    // Draw content to OLED screen
    oled_write_P(lily58, false);
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) oled_write_P(separator[1], false);
    else                                                 oled_write_P(separator[0], false);

    if (layer_state_is(_MOUSE))                              oled_write_P(layer_state[4], false);
    else if (layer_state_is(_LNAV) || layer_state_is(_RNAV)) oled_write_P(layer_state[3], false);
    else if (layer_state_is(_NUM))                           oled_write_P(layer_state[2], false);
    else if (layer_state_is(_SWAP))                          oled_write_P(layer_state[1], false);
    else                                                     oled_write_P(layer_state[0], false);

    uint8_t mods = get_mods();
    oled_write_P(mods & MOD_MASK_GUI   ? mod_gui[0]   : mod_blank, false); oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT   ? mod_alt[0]   : mod_blank, false);
    oled_write_P(mods & MOD_MASK_GUI   ? mod_gui[1]   : mod_blank, false); oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT   ? mod_alt[1]   : mod_blank, false);
    oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[0] : mod_blank, false); oled_advance_char();
    oled_write_P(mods & MOD_MASK_CTRL  ? mod_ctrl[0]  : mod_blank, false);
    oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[1] : mod_blank, false); oled_advance_char();
    oled_write_P(mods & MOD_MASK_CTRL  ? mod_ctrl[1]  : mod_blank, false);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_90;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) render_master();
    else                      render_tawheed();
    return false;
}

void suspend_power_down_user(void) {
    oled_off();
}

#endif // OLED_ENABLE
