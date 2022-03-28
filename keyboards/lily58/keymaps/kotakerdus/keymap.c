/*
* Author      : kotakerdus
* Version     : 0.1.0
* OS          : Windows 10
* Keyboard    : lily58
* Description : Custom lily58 keyboard focusing on left hand layout while using mouse, useful for design application like Blender, Photoshop
*               and many other design application. This layout has _SWAP layer that work like QMK's OSL which useful for triggering
*               a shortcut so you don't have to reach the other half of the keyboard.
*/

#include QMK_KEYBOARD_H
enum layer_number {
    _QWERTY = 0,
    _SWAP, _NUM, _LNAV, _RNAV, _MOUSE
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    MOD_CTL = SAFE_RANGE, // KC_LCTL | Toggle _SWAP layer if tapped | KC_QUOT in _SWAP layer & and turn it off
    MOD_SFT,              // KC_LSFT                                | KC_EQL in _SWAP layer & and turn it off
    MOD_ALT,              // KC_LALT | G(C(KC_LEFT)) if GUI tapped (slide into left desktop) | Turn off _SWAP layer if tapped
    MOD_GUI,              // KC_LGUI | Turn off _SWAP layer if tapped
    MOS_SPD               // KC_ACL0 if hold | KC_BTN3 if tapped
};

#define LT_NUMP LT(_NUM, KC_BSPC) // G(C(KC_RGHT)) if GUI tapped (slide into right desktop)
#define LT_LNAV LT(_LNAV, KC_DEL)
#define LT_RNAV LT(_RNAV, KC_DEL) // Toggle _MOUSE layer if hold together with LT_NUMP
#define SF_TENT KC_SFTENT         // SpaceCadet SHIFT <-> ENTER

#define AP_SNIP KC_F24            // Snipaste shortcut for taking a screenshot
#define AP_HIDE KC_F23            // Snipaste shortcut for hiding the pinned screenshot
#define AP_ALSL A(KC_SLSH)        // VSCode MetaJump extension shortcut

// KC_GRV | G(S(KC_RGHT)) if GUI tapped (move current window to next monitor)
// KC_ESC | KC_SLEP if ALT tapped & A(KC_F4) if CTRL tapped

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             MOD_CTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             MOD_SFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_EQL ,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        MOD_ALT, MOD_GUI, LT_NUMP, KC_SPC ,       SF_TENT, LT_RNAV, KC_MPLY, KC_RALT
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
             _______, KC_F24 , KC_P7  , KC_P8  , KC_P9  , KC_PPLS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, LT_LNAV, KC_P4  , KC_P5  , KC_P6  , KC_PMNS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSPO, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_RPRN,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_PDOT, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_LNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_F23 , KC_PGUP, KC_UP  , KC_PGDN, KC_F11 ,                         _______, _______, _______, _______, _______, _______,
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
             _______, _______, _______, _______, _______, _______,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_ESC ,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, KC_VOLD, KC_HOME, KC_APP , KC_END , AP_ALSL, KC_RSPC,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       KC_CAPS, _______, KC_MPRV, KC_MNXT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, KC_MS_U, _______, _______,                         _______, _______, KC_WH_U, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                         _______, KC_BTN1, MOS_SPD, KC_BTN2, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_BTN4, _______, KC_BTN5, _______, _______,       _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, KC_LGUI, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

uint16_t key_timer = 0;
bool other_key_pressed = false; // This block trigger OSL-like key (CTRL) while quick rolling-key on common shortcut (example: CTRL + Z)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    switch (keycode) {
        case KC_GRV:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods & MOD_MASK_GUI) {
                    other_key_pressed = true;
                    tap_code16(S(KC_RGHT));
                    return false;
                }
            } break;
        case KC_ESC:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods) {
                    if (mods & MOD_MASK_ALT) tap_code(KC_SLEP);
                    else if (mods & MOD_MASK_CTRL) {
                        del_mods(MOD_MASK_CTRL);
                        tap_code16(A(KC_F4));
                        set_mods(mods);
                    }

                    return false;
                }
            } break;
        case MOD_CTL:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_QWERTY)) layer_on(_SWAP);
                    else if (layer_state_is(_SWAP)) {
                        del_mods(MOD_MASK_CTRL);
                        tap_code(KC_QUOT);
                        set_mods(mods);
                        if (!(mods & MOD_MASK_SAG)) layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);

                unregister_code(KC_LCTL);
                other_key_pressed = true;
            } break;
        case MOD_SFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP)) {
                        del_mods(MOD_MASK_SHIFT);
                        tap_code(KC_EQL);
                        set_mods(mods);
                        if (!(mods & MOD_MASK_CAG)) layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);

                unregister_code(KC_LSFT);
                other_key_pressed = true;
            } break;
        case MOD_ALT:
            if (record -> event.pressed) {
                if (record -> event.pressed && (mods & MOD_MASK_GUI)) {
                    tap_code16(C(KC_LEFT));
                    return false;
                }

                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LALT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP) && (!(mods & MOD_MASK_CSG))) layer_off(_SWAP);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);

                unregister_code(KC_LALT);
                other_key_pressed = true;
            } break;
        case MOD_GUI:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP) && (!(mods & MOD_MASK_CSA))) layer_off(_SWAP);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP);

                unregister_code(KC_LGUI);
                other_key_pressed = true;
            } break;
        case LT_NUMP:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (layer_state_is(_SWAP)) layer_off(_SWAP);
                if (mods & MOD_MASK_GUI) {
                    tap_code16(C(KC_RGHT));
                    return false;
                }
            } break;
        case MOS_SPD:
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
                layer_off(_SWAP); // This turn _SWAP off if default keys are pressed while not holding any mod key
            break;
    }

    return true;
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

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _RNAV, _MOUSE);
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
}

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
    else if (layer_state_is(_LNAV) || layer_state_is(_RNAV)) oled_write_P(layer_state[2], false);
    else if (layer_state_is(_NUM))                           oled_write_P(layer_state[1], false);
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
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_master() ? OLED_ROTATION_270 : OLED_ROTATION_180;
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
