/*
* Author:   kotakerdus
* OS:       Windows 10
* Keyboard: lily58 with custom OLED graphic
*
* The idea of this keymap is to be able to use one side of the keyboard with mouse comfortably which benefit it greatly while using design-app
* like Blender & Photoshop while also maintain the ergonomics aspect of split keyboard without compromising on many shortcut and keys and also
* able to input both numeric data (useful for precise input data in Blender, Photoshop, Excel, etc) and cursor text navigation on left side.
* This keymap also has SWAP layer on left side of the keyboard so that you can shoot that shortcut without having too much hand movement.
*/

#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _SWAP, _NUM, _LNAV, _RNAV, _MOUSE
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    MO_CTRL = SAFE_RANGE, // KC_LCTL           | OSL(_SWAP) if tapped | KC_QUOT in _SWAP layer if tapped | KC_CAPS in _NUM layer if tapped
    MO_SHFT,              // KC_LSFT           | OSL(_SWAP) if tapped | KC_EQL  in _SWAP layer if tapped | S(KC_9) in _NUM layer if tapped
    MO_ALT ,              // KC_LALT           | OSL(_SWAP) if tapped | G(C(KC_LEFT)) if GUI-tapped
    LY_NMPD,              // LT(_NUM, KC_BSPC)                        | G(C(KC_RGHT)) if GUI-tapped
    MS_MCLK               // KC_ACL1           | KC_BTN3 if tapped
};

#define LY_LNAV LT(_LNAV, KC_DEL)
#define LY_RNAV LT(_RNAV, KC_DEL)
#define LY_MOUS LT(_MOUSE, KC_MPLY)

#define SFT_ENT KC_SFTENT    // Space Cadet - Right Shift when held, Enter when tapped
#define AP_SNIP KC_F13       // Snipaste shortcut to take a screenshot
#define AP_SNHD A(S(KC_F13)) // Snipaste shortcut to hide the screenshot

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             MO_CTRL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             MO_SHFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_EQL ,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        MO_ALT , KC_LGUI, LY_NMPD, KC_SPC ,       SFT_ENT, LY_RNAV, LY_MOUS, KC_RALT
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
             _______, AP_SNIP, KC_P7  , KC_P8  , KC_P9  , KC_PPLS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, LY_LNAV, KC_P4  , KC_P5  , KC_P6  , KC_PMNS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_RPRN,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_PDOT, _______, KC_CAPS,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_LNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, AP_SNHD, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, KC_HOME, KC_MPLY, KC_END , _______, _______,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_LGUI, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_RNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_SLEP,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, KC_VOLD, KC_HOME, XXXXXXX, KC_END , XXXXXXX, KC_RPRN,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, KC_APP , _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, KC_MS_U, _______, _______,                         _______, KC_WH_L, KC_WH_U, KC_WH_R, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                         _______, KC_BTN1, MS_MCLK, KC_BTN2, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, _______, KC_BTN4, KC_WH_D, KC_BTN5, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, KC_MPRV, _______, KC_MNXT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E |----------------------------------------------------------------------------------------------------------------

uint16_t key_timer = 0;
bool ctrl_pressed_before_numpad = false; // Rolling key on MO_CTRL(down) -> LY_NMPD(down) -> MO_CTRL(up) -> LY_NMPD(up) = C(KC_BSPC)
bool shift_pressed_after_numpad = false; // Rolling key on LY_NMPD(down) -> MO_SHFT(down) -> LY_NMPD(up) -> MO_SHFT(up) = S(KC_9)
bool mods_pressed_in_swap = false;       // Keep staying on _SWAP layer until released
bool other_key_pressed = false;          // Avoid getting triggered on other custom keys

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    switch (keycode) {
        case MO_CTRL:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_SWAP)) mods_pressed_in_swap = true;
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (ctrl_pressed_before_numpad) tap_code(KC_BSPC); // C(KC_BSPC)
                    else if (mods & MOD_MASK_GUI) {
                        unregister_code(KC_LCTL);
                        tap_code16(S(KC_RGHT)); // G(S(KC_RGHT))
                        return true;
                    } else if (!layer_state_is(_SWAP)) set_oneshot_layer(_SWAP, ONESHOT_START);
                    else {
                        del_mods(MOD_MASK_CTRL);
                        tap_code(KC_QUOT);
                        set_mods(mods);
                        reset_oneshot_layer();
                        layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) {
                    reset_oneshot_layer();
                    layer_off(_SWAP);
                }

                unregister_code(KC_LCTL);
                ctrl_pressed_before_numpad = false;
                mods_pressed_in_swap = false;
                other_key_pressed = true;
            } break;
        case MO_SHFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_SWAP)) mods_pressed_in_swap = true;
                if (layer_state_is(_NUM)) shift_pressed_after_numpad = true;
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_NUM)) tap_code(KC_9);
                    else if (!layer_state_is(_SWAP)) set_oneshot_layer(_SWAP, ONESHOT_START);
                    else {
                        del_mods(MOD_MASK_SHIFT);
                        tap_code(KC_EQL);
                        set_mods(mods);
                        reset_oneshot_layer();
                        layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) {
                    reset_oneshot_layer();
                    layer_off(_SWAP);
                }

                unregister_code(KC_LSFT);
                mods_pressed_in_swap = false;
                other_key_pressed = true;
            } break;
        case MO_ALT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_SWAP)) mods_pressed_in_swap = true;
                else if (mods & MOD_MASK_GUI) {
                    tap_code16(C(KC_LEFT));
                    return false;
                }

                key_timer = timer_read();
                register_code(KC_LALT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (!layer_state_is(_SWAP)) set_oneshot_layer(_SWAP, ONESHOT_START);
                    else {
                        reset_oneshot_layer();
                        layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) {
                    reset_oneshot_layer();
                    layer_off(_SWAP);
                }

                unregister_code(KC_LALT);
                mods_pressed_in_swap = false;
                other_key_pressed = true;
            } break;
        case LY_NMPD:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_SWAP)) {
                    reset_oneshot_layer();
                    layer_off(_SWAP);
                }

                if (mods & MOD_MASK_CTRL) ctrl_pressed_before_numpad = true;
                else if (mods & MOD_MASK_GUI) {
                    tap_code16(C(KC_RGHT)); // G(C(KC_RGHT))
                    return false;
                }

                key_timer = timer_read();
                layer_on(_NUM);
            } else {
                layer_off(_NUM);
                layer_off(_LNAV);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (shift_pressed_after_numpad) tap_code(KC_9);
                    else tap_code(KC_BSPC);
                }

                shift_pressed_after_numpad = false;
                other_key_pressed = true;
            } break;
        case MS_MCLK:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_ACL1);
            } else {
                unregister_code(KC_ACL1);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_BTN3);
                other_key_pressed = true;
            } break;
        default:
            if (layer_state_is(_SWAP) & !mods_pressed_in_swap) clear_oneshot_layer_state(ONESHOT_PRESSED);
            ctrl_pressed_before_numpad = false;
            shift_pressed_after_numpad = false;
            other_key_pressed = true;
            break;
    }

    return true;
};

// Custom Auto Shift - https://docs.qmk.fm/#/feature_auto_shift
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
            return false;  // Disable Auto Shift on those keys
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
        case KC_PENT: register_code16((!shifted) ? KC_PENT : KC_EQL); break;
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
        case KC_PENT: unregister_code16((!shifted) ? KC_PENT : KC_EQL); break;
        case KC_PDOT: unregister_code16((!shifted) ? KC_PDOT : KC_COMM); break;
        default:
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

// O L E D   I N T E R F A C E |----------------------------------------------------------------------------------------------------------------

#ifdef OLED_ENABLE

void render_tawheed(void) {
    static const char PROGMEM tawheed[] = {
          0,  0,  0,254,254,  6,  6,  6,  6,134,134,134,134,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,134,134,134,
        134,  6,  6,134,134,134,134,134,134,  6,  6,134,134,134,134,134,134,134,134,134,134,  6,  6,134,134,134,134,134,134,  6,  6,134,134,134,
        134,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,134,134,134,
        134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,134,134,  6,  6,  6,  6,254,254,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,
          0,255,255,  1,  1,255,255,  0,  0,255,255,  0,  0,255,255,  0,  0,255,255,  0,  0,159,159,129,129,255,255, 24, 24,159,159, 25, 25,159,
        159,152,152,153,153, 25, 25,153,153, 25, 25,159,159, 24, 24,159,159, 25, 25,159,159,  0,  0,255,255,  1,  1,255,255,  0,  0,255,255,  0,
          0,255,255,  0,  0,255,255,  0,  0,255,255,128,128,255,255,  0,  0,255,255,  0,  0,255,255,  1,  1,255,255,  0,  0,255,255,  0,  0,255,
        255,  0,  0,255,255,128,128,255,255,  0,  0,  0,  0,255,255,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,  0,249,249,152,152,255,255,128,
        128,255,255,128,128,255,255,  0,  0,255,255,  0,  0,249,249,153,153,153,153,128,128,255,255,  0,  0,159,159,153,153,255,255, 24, 24,159,
        159,152,152,159,159,152,152,159,159,128,128,255,255,  0,  0,249,249,152,152,255,255,128,128,255,255,128,128,255,255,  0,  0,255,255,  0,
          0,249,249,159,159,249,249,  0,  0,255,255,  0,  0,249,249,152,152,255,255,128,128,255,255,  0,  0,255,255,  0,  0,249,249,159,159,249,
        249,  0,  0,  0,  0,255,255,  0,  0,  0,  0,  0,  0,127,127, 96, 96, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 96,
         96, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97,
         97, 97, 97, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 96, 96, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 96,
         96, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 97, 97, 97, 97, 96, 96, 97, 97, 96, 96, 97, 97, 97, 97, 97, 97, 96, 96, 96, 96,127,127,  0,
          0,  0,
    };

    oled_write_raw_P(tawheed, sizeof(tawheed));
};

void render_master(void) {
    static const char PROGMEM lily58[] = {
        0x20, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,
        0x85, 0x86, 0x87, 0x88, 0x89,
        0xc5, 0xa6, 0xa7, 0xa8, 0xc5,
        0xc5, 0xc6, 0xc7, 0xc8, 0xc5,
        0x8a, 0x8b, 0x8c, 0x8d, 0x8e,
        0xaa, 0xab, 0xac, 0xad, 0xae, 0
    };

    static const char PROGMEM separator[2][11] = {
        { 0x20, 0x9d, 0x9e, 0x9f, 0x20,
          0x20, 0x20, 0x20, 0x20, 0x20, 0
        }, // Normal (0)
        { 0x20, 0xbd, 0xbe, 0xbf, 0x20,
          0x20, 0xdd, 0xde, 0xdf, 0x20, 0
        }, // Caps (1)
        // { 0x20, 0x5d, 0x5e, 0x5f, 0x20,
        //   0x20, 0x7d, 0x7e, 0x7f, 0x20, 0
        // }, // _MOUSE layer lock (2) | NOT USED ATM
    };
    static const char PROGMEM layer_state[5][6] = {
        { 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0 }, // QWERT  (0)
        // { 0x8f, 0x90, 0x91, 0x92, 0x93, 0 }, // COLMAK (1) | NOT USED ATM
        { 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0 }, // NUMPAD (2)
        { 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0 }, // NAVIGT (3)
        { 0x94, 0x95, 0x96, 0x97, 0x98, 0 }, // MOUSE  (4)
        { 0x80, 0x99, 0x9a, 0x9b, 0x9c, 0 }  // SWAP   (5)
    };

    static const char PROGMEM mod_gui[2][3]   = {{ 0xb4, 0xb5, 0 }, { 0xd4, 0xd5, 0 }};
    static const char PROGMEM mod_alt[2][3]   = {{ 0xb6, 0xb7, 0 }, { 0xd6, 0xd7, 0 }};
    static const char PROGMEM mod_shift[2][3] = {{ 0xb8, 0xb9, 0 }, { 0xd8, 0xd9, 0 }};
    static const char PROGMEM mod_ctrl[2][3]  = {{ 0xba, 0xbb, 0 }, { 0xda, 0xdb, 0 }};

    oled_write_P(lily58, false);
    if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) oled_write_P(separator[1], false);
    else                                                 oled_write_P(separator[0], false);

    if (layer_state_is(_MOUSE))                              oled_write_P(layer_state[3], false);
    else if (layer_state_is(_NUM))                           oled_write_P(layer_state[1], false);
    else if (layer_state_is(_LNAV) || layer_state_is(_RNAV)) oled_write_P(layer_state[2], false);
    else if (layer_state_is(_SWAP))                          oled_write_P(layer_state[4], false);
    else                                                     oled_write_P(layer_state[0], false);

    uint8_t mods = get_mods() | get_oneshot_mods();
    oled_write_P(mods & MOD_MASK_GUI   ? mod_gui[0]   : PSTR("  "), false); oled_write(" ", false);
    oled_write_P(mods & MOD_MASK_ALT   ? mod_alt[0]   : PSTR("  "), false);
    oled_write_P(mods & MOD_MASK_GUI   ? mod_gui[1]   : PSTR("  "), false); oled_write(" ", false);
    oled_write_P(mods & MOD_MASK_ALT   ? mod_alt[1]   : PSTR("  "), false);
    oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[0] : PSTR("  "), false); oled_write(" ", false);
    oled_write_P(mods & MOD_MASK_CTRL  ? mod_ctrl[0]  : PSTR("  "), false);
    oled_write_P(mods & MOD_MASK_SHIFT ? mod_shift[1] : PSTR("  "), false); oled_write(" ", false);
    oled_write_P(mods & MOD_MASK_CTRL  ? mod_ctrl[1]  : PSTR("  "), false);
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_180;
};

bool oled_task_user(void) {
    if (is_keyboard_master()) render_master();
    else                      render_tawheed();
    return false;
};

void suspend_power_down_user(void) {
    oled_off();
};

#endif // OLED_ENABLE
