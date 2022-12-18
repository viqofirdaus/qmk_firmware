// Author      : kotakerdus
// Version     : 0.3.6
// OS          : Windows 10
// Useful Apps : - RamonUnch AltSnap (window management app, ie: resize/move window anywhere within the window content)
//               - Snipaste (screenshot app that is able to pin the screenshot on screen. KC_F13 as its shortcut)
//               - ViRb3 SylphyHornEx (windows's task view management app, ie: move window to right desktop view)
// Keyboard    : lily58
// Features    : - Auto Shift for numbers and symbols but not alphas
//               - Caps Word is like CAPSLOCK but supercharged (disabled if Auto Shift is disabled as well)
//               - Swap Hands but customized to work like one-shot key for left side of the keyboard by pressing MD_LCTL key once & won't break
//                 out of one-shot key state if pressed with MOD key (ie: possible to type SHIFT + i)
// Description : Custom lily58 keyboard focusing on left hand layout + mouse, useful for work that demands on mouse usage like Blender,
//               Photoshop and many other design application. This layout has _SWAP layer that work like QMK's OSL which useful for trigger
//               a shortcut without having to reach the other half of the keyboard.
//               The OSL in this keymap won't end if you press the alpha-key while holding a mod-key so it is useful if you want to trigger
//               the shortcut more than once and goes back to default layer as soon as you release the mod-key (ie: CTRL + Y for redo).

#include QMK_KEYBOARD_H
enum layer_number {
    _QWERTY = 0,
    _SWAP, _NUMP, _NAVI, _MOUS
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    MD_LCTL = SAFE_RANGE, // LCTL_T(OSL(_SWAP)) | LCTL_T(KC_QUOT) in _SWAP layer | S(KC_TAB) while alt_tabbing (select previous)
    MD_LSFT,              // LSFT_T(CAPSWRD)    | LSFT_T(KC_EQL)  in _SWAP layer | LSFT_T(KC_LPRN) in _NUMP layer
    MD_RCTL, MD_RSFT,     // RCTL_T(KC_QUOT)    & RSFT_T(KC_EQL)
    MD_LALT,              // KC_LALT            | G(C(KC_LEFT)) if MD_LGUI tapped                                | KC_MPRV in _NUMP layer
    MD_LGUI,              // KC_LGUI            & Can be combined with MD_LALT or LT_NUMP for desktop navigation | KC_MNXT in _NUMP layer
    LT_NUMP,              // LT(_NUMP, KC_BSPC) | G(C(KC_RGHT)) if MD_LGUI tapped | Turn _SWAP layer off (won't trigger KC_BSPC if tapped)
    LT_LNAV, LT_RNAV,     // LT(_NAVI, KC_DEL)  | Turn _MOUS layer on if pressed together both LT_NUMP & LT_RNAV
    KY_SPED               // KC_ACL0            | KC_BTN3 if tapped
};

// KC_ESC               | G(S(KC_RGHT)) if LGUI tapped (move current window to next monitor) | KC_DEL while alt_tabbing (close selected window)
// KC_ASTG              | Toggles the state of the Auto Shift and Caps Word features
#define SP_SNIP KC_F13 // Shortcut for taking a screenshot using Snipaste

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             MD_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, MD_RCTL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             MD_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, MD_RSFT,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        MD_LALT, MD_LGUI, LT_NUMP, KC_SPC ,       KC_ENT , LT_RNAV, KC_RGUI, KC_RALT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_SWAP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_BSLS, KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_MINS, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   , KC_RBRC,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_NUMP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             SP_SNIP, KC_PDOT, KC_P7  , KC_P8  , KC_P9  , KC_PPLS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, LT_LNAV, KC_P4  , KC_P5  , KC_P6  , KC_PMNS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , KC_PENT, KC_RPRN,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, KC_MPLY,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_NAVI] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_SLEP, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_INS ,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_NUM , XXXXXXX, KC_UP  , KC_PGUP, KC_F11 ,                         KC_VOLU, XXXXXXX, KC_UP  , KC_PGUP, KC_F11 , KC_SCRL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 ,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_ASTG, KC_HOME, KC_END , KC_PGDN, KC_ENT , _______,       KC_LPRN, KC_VOLD, KC_HOME, KC_END , KC_PGDN, KC_APP , _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUS] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, XXXXXXX, KC_PGUP, KC_MS_U, XXXXXXX, XXXXXXX,                         _______, XXXXXXX, KC_WH_U, XXXXXXX, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤        │     │        ├────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LCTL, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,                         _______, KC_BTN1, KY_SPED, KC_BTN2, _______, KC_RCTL,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KC_LSFT, XXXXXXX, KC_PGDN, KC_HOME, KC_END , KC_ENT , XXXXXXX,       XXXXXXX, _______, KC_BTN4, KC_WH_D, KC_BTN5, _______, KC_RSFT,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        KC_LALT, KC_LGUI, _______, _______,       _______, _______, KC_RGUI, KC_RALT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

uint16_t key_timer = 0;
// Easy SHIFT + alt/ctrl-tabbing by pressing KC_ESC for S(KC_TAB) instead of holding SHIFT key for selecting previous tab/window
bool tabbing = false;
// Boolean for checking on quick rolling-key on MD_* keys combo with LT_* keys
bool mod_before_layer = false; // ie: MD_LCTL(▼) ⟶ LT_NUMP(▼) ⟶ MD_LCTL(▲) ⟶ LT_NUMP(▲) = C(KC_BSPC) instead of (KC_BSPC)
bool mod_after_layer = false;  // ie: LT_NUMP(▼) ⟶ MD_LSFT(▼) ⟶ LT_NUMP(▲) ⟶ MD_LSFT(▲) = S(KC_9) instead of S(KC_BSPC) due to dual-role key
// This block un-intended trigger on custom key while quick rolling-key on common shortcut (ie: CTRL + Z would not trigger OSL(_SWAP)
bool other_key_pressed = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods();
    switch (keycode) {
        case KC_TAB:
            if (record -> event.pressed && (mods & (MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL)))) tabbing = true;
            break;
        case KC_ESC:
            if (record -> event.pressed) {
                if (tabbing) {
                    tap_code16(S(KC_TAB));
                    return false;
                } else if (mods & MOD_BIT(KC_LGUI)) {
                    tap_code16(S(KC_RGHT)); // Trigger G(S(KC_RGHT)) (move current active window to next monitor)
                    return false;
                }
            } break;
        case MD_LCTL:
            if (record -> event.pressed) {
                if (tabbing) {
                    tap_code(KC_DEL);
                    other_key_pressed = true;
                    return false;
                }

                other_key_pressed = false;
                if (layer_state_is(_NUMP)) mod_after_layer = true;
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_before_layer is for triggering quick-rolling MD_LCTL(▼) ⟶ LT_NUMP(▼) or LT_RNAV(▼) ⟶ MD_LCTL(▲)
                    // which then trigger C(KC_BSPC) or C(KC_DEL)
                    if (mod_before_layer) {
                        if (layer_state_is(_NUMP)) tap_code(KC_BSPC);
                        else if (layer_state_is(_NAVI)) tap_code(KC_DEL);
                    } else if (layer_state_is(_QWERTY)) layer_on(_SWAP); // This toggle OSL(_SWAP)
                    else if (layer_state_is(_SWAP)) {
                        del_mods(MOD_BIT(KC_LCTL));
                        tap_code(KC_QUOT);
                        if (mods == MOD_BIT(KC_LCTL)) layer_off(_SWAP); // Turn layer _SWAP off if only KC_LCTL mod key is pressed
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button

                unregister_code(KC_LCTL);
                tabbing = false;
                mod_before_layer = false;
                other_key_pressed = true;
            } break;
        case MD_RCTL:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_NUMP)) mod_after_layer = true;
                key_timer = timer_read();
                register_code(KC_RCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_before_layer is for triggering quick-rolling MD_RCTL(▼) ⟶ LT_NUMP(▼) or LT_RNAV(▼) ⟶ MD_RCTL(▲)
                    // which then trigger C(KC_BSPC) or C(KC_DEL)
                    if (mod_before_layer) {
                        if (layer_state_is(_NUMP)) tap_code(KC_BSPC);
                        else if (layer_state_is(_NAVI)) tap_code(KC_DEL);
                    } else {
                        del_mods(MOD_BIT(KC_RCTL));
                        tap_code(KC_QUOT);
                        if (layer_state_is(_SWAP) && (mods == MOD_BIT(KC_RCTL))) layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button

                unregister_code(KC_RCTL);
                tabbing = false;
                mod_before_layer = false;
                other_key_pressed = true;
            } break;
        case MD_LSFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_NUMP) || layer_state_is(_NAVI)) mod_after_layer = true;
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_after_layer only trigger if the key is pressed in _NUMP or _NAVI layer
                    // which trigger S(KC_9) on MD_LSFT(▲)
                    if (mod_after_layer) {
                        if (layer_state_is(_NUMP) || layer_state_is(_NAVI)) tap_code(KC_9);
                    } else if (layer_state_is(_SWAP)) {
                        del_mods(MOD_BIT(KC_LSFT));
                        tap_code(KC_EQL);
                        if (mods == MOD_BIT(KC_LSFT)) layer_off(_SWAP);
                    } else if (get_autoshift_state() && layer_state_is(_QWERTY)) caps_word_toggle();
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button

                unregister_code(KC_LSFT);
                mod_before_layer = false;
                other_key_pressed = true;
            } break;
        case MD_RSFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (layer_state_is(_NUMP) || layer_state_is(_NAVI)) mod_after_layer = true;
                key_timer = timer_read();
                register_code(KC_RSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_after_layer only trigger if the key is pressed in _NUMP or _NAVI layer
                    // which trigger S(KC_0) on MD_RSFT(▲)
                    if (mod_after_layer) {
                        if (layer_state_is(_NUMP) || layer_state_is(_NAVI)) tap_code(KC_0);
                    } else {
                        del_mods(MOD_BIT(KC_RSFT));
                        tap_code(KC_EQL);
                        if (layer_state_is(_SWAP) && (mods == MOD_BIT(KC_RSFT))) layer_off(_SWAP);
                    }
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button

                unregister_code(KC_RSFT);
                mod_before_layer = false;
                other_key_pressed = true;
            } break;
        case MD_LALT:
            if (record -> event.pressed) {
                if (mods & MOD_BIT(KC_LGUI)) {
                    other_key_pressed = true;
                    if (layer_state_is(_NUMP)) tap_code16(A(C(KC_LEFT))); // SylphyHornEx shortcut to move current window to the left desktop
                    else tap_code16(C(KC_LEFT));
                    return false;
                }

                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (layer_state_is(_SWAP) && (mods == MOD_BIT(KC_LALT))) layer_off(_SWAP);
                    else if (layer_state_is(_NUMP)) tap_code(KC_MPRV);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button
                tabbing = false;
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
                    if (layer_state_is(_SWAP) && (mods == MOD_BIT(KC_LGUI))) layer_off(_SWAP);
                    else if (layer_state_is(_NUMP)) tap_code(KC_MNXT);
                } else if (layer_state_is(_SWAP)) layer_off(_SWAP); // Turn layer _SWAP off after hold-then-release this button
                other_key_pressed = true;
            } break;
        case LT_NUMP:
            if (record -> event.pressed) {
                if (mods & MOD_BIT(KC_LGUI)) {
                    other_key_pressed = true;
                    tap_code16(C(KC_RGHT));
                    return false;
                }

                other_key_pressed = layer_state_is(_NAVI) ? true : false;
                // mod_before_layer checking point
                if (mods & (MOD_MASK_CTRL | MOD_MASK_SHIFT)) mod_before_layer = true;
                key_timer = timer_read();
                layer_on(_NUMP);
                update_tri_layer(_NUMP, _NAVI, _MOUS);
            } else {
                layer_off(_NUMP);
                update_tri_layer(_NUMP, _NAVI, _MOUS);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_before_layer is for triggering quick-rolling LT_NUMP(▼) ⟶ MD_LSFT(▼) ⟶ LT_NUMP(▲)
                    // which then trigger S(KC_9) on LT_NUMP(▲)
                    if (mod_after_layer) {
                        if (mods & MOD_BIT(KC_LSFT)) tap_code(KC_9);
                    } else if (!layer_state_is(_SWAP)) tap_code(KC_BSPC);
                }

                layer_off(_SWAP);
                mod_after_layer = false;
                other_key_pressed = true;
            } break;
        case LT_LNAV:
            if (record -> event.pressed) {
                other_key_pressed = true;
                key_timer = timer_read();
                layer_on(_NAVI);
            } else {
                layer_off(_NAVI);
                if (timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_DEL);
            } break;
        case LT_RNAV:
            if (record -> event.pressed) {
                other_key_pressed = layer_state_is(_NUMP) ? true : false;
                // mod_before_layer checking point
                if (mods & (MOD_MASK_CTRL | MOD_MASK_SHIFT)) mod_before_layer = true;
                key_timer = timer_read();
                layer_on(_NAVI);
                update_tri_layer(_NUMP, _NAVI, _MOUS);
            } else {
                layer_off(_NAVI);
                update_tri_layer(_NUMP, _NAVI, _MOUS);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    // mod_before_layer is for triggering quick-rolling LT_RNAV(▼) ⟶ MD_RSFT(▼) ⟶ LT_RNAV(▲)
                    // which then trigger S(KC_0) on LT_RNAV(▲)
                    if (mod_after_layer) {
                        if (mods & MOD_BIT(KC_RSFT)) tap_code(KC_0);
                    } else tap_code(KC_DEL);
                }
                other_key_pressed = true;
            } break;
        case KY_SPED:
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
            else {
                if (layer_state_is(_SWAP) && mods == 0)
                    layer_off(_SWAP); // Turn layer _SWAP off if default keys are pressed while not holding any mod key
            } break;
    }

    return true;
}

// A U T O  S H I F T |-------------------------------------------------------------------------------------------------------------------------
// https://docs.qmk.fm/#/feature_auto_shift

bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_MINUS ... KC_SLASH:
        case KC_NONUS_BACKSLASH:
            return true; // Only enable Auto Shift on these keys above
        case KC_A ... KC_Z:
        case KC_TAB:
            return false;
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
        case KC_MINS:
        case MD_RCTL:
        case MD_LSFT:
        case MD_RSFT:
        case LT_NUMP:
        case LT_LNAV:
        case LT_RNAV:
            return true;
        // Other key will deactive the Caps Word.
        default:
            return false;
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
        { 0xdf, 0x1d, 0x1e, 0x1f, 0xdf,
          0xdf, 0xdf, 0xdf, 0xdf, 0xdf, 0 }, // Normal (0)
        { 0xdf, 0x3d, 0x3e, 0x3f, 0xdf,
          0xdf, 0x5d, 0x5e, 0x5f, 0xdf, 0 }  // Caps   (1)
    };
    static const char PROGMEM layer_state[5][6] = {
        { 0x14, 0x15, 0x16, 0x17, 0x18, 0 }, // QWERT  (0)
        { 0x34, 0x35, 0x36, 0x37, 0x38, 0 }, // SWAP   (1)
        { 0x54, 0x55, 0x56, 0x57, 0x58, 0 }, // NUMPAD (2)
        { 0x74, 0x75, 0x76, 0x77, 0x78, 0 }, // NAVI   (3)
        { 0x94, 0x95, 0x96, 0x97, 0x98, 0 }  // MOUSE  (4)
    };

    static const char PROGMEM mod_blank[]          = { 0xdf, 0xdf, 0 };
    static const char PROGMEM mod_gui[2][3]        = {{ 0x19, 0x1a, 0 }, { 0x39, 0x3a, 0 }};
    static const char PROGMEM mod_alt[2][3]        = {{ 0x1b, 0x1c, 0 }, { 0x3b, 0x3c, 0 }};
    static const char PROGMEM mod_ctrl[2][3]       = {{ 0x59, 0x5a, 0 }, { 0x79, 0x7a, 0 }};
    static const char PROGMEM mod_shift[2][3]      = {{ 0x5b, 0x5c, 0 }, { 0x7b, 0x7c, 0 }};
    static const char PROGMEM mod_auto[2][3]       = {{ 0x9b, 0x9c, 0 }, { 0xbb, 0xbc, 0 }};
    static const char PROGMEM mod_shift_auto[2][3] = {{ 0x99, 0x9a, 0 }, { 0xb9, 0xba, 0 }};

    // Start render ------------------------

    // Lily58 logo and CAPS/divider section
    oled_write_P(lily58, false);
    if ((host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) || is_caps_word_on()) oled_write_P(separator[1], false);
    else                                                                        oled_write_P(separator[0], false);

    // Layer names
    if      (layer_state_is(_MOUS)) oled_write_P(layer_state[4], false);
    else if (layer_state_is(_NAVI)) oled_write_P(layer_state[3], false);
    else if (layer_state_is(_NUMP)) oled_write_P(layer_state[2], false);
    else if (layer_state_is(_SWAP)) oled_write_P(layer_state[1], false);
    else                            oled_write_P(layer_state[0], false);

    // Mods & AutoShift indicator
    const uint8_t mods = get_mods();
    oled_write_P(mods & MOD_MASK_GUI  ? mod_gui[0]  : mod_blank, false);
    oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT  ? mod_alt[0]  : mod_blank, false);
    oled_write_P(mods & MOD_MASK_GUI  ? mod_gui[1]  : mod_blank, false);
    oled_advance_char();
    oled_write_P(mods & MOD_MASK_ALT  ? mod_alt[1]  : mod_blank, false);
    oled_write_P(mods & MOD_MASK_CTRL ? mod_ctrl[0] : mod_blank, false);
    oled_advance_char();
    if (get_autoshift_state()) {
        if (mods & MOD_MASK_SHIFT) oled_write_P(mod_shift_auto[0], false);
        else                       oled_write_P(mod_auto[0], false);
    } else {
        if (mods & MOD_MASK_SHIFT) oled_write_P(mod_shift[0], false);
        else                       oled_write_P(mod_blank, false);
    }

    oled_write_P(mods & MOD_MASK_CTRL ? mod_ctrl[1] : mod_blank, false);
    oled_advance_char();

    if (get_autoshift_state()) {
        if (mods & MOD_MASK_SHIFT) oled_write_P(mod_shift_auto[1], false);
        else                       oled_write_P(mod_auto[1], false);
    } else {
        if (mods & MOD_MASK_SHIFT) oled_write_P(mod_shift[1], false);
        else                       oled_write_P(mod_blank, false);
    }

    // End of render -----------------------
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
