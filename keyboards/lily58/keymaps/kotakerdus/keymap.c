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
    _NUM, _LNAV, _SWAP, _RNAV, _MOUSE
};

// D E F I N E   K E Y C O D E S |--------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    KY_GRAV = SAFE_RANGE, // KC_GRV             | G(S(KC_RGHT)) if GUI-tapped (move window to next monitor) | +SHIFT in alt_ctrl_tabbing
    KY_TABS,              // KC_TAB             & as alt_ctrl_tabbing initiator key
    KY_LSFT,              // KC_LSFT            | S(KC_9) if tapped (Space Cadet key but without delay on SHIFT key, Blender approved)
    KY_LCTL,              // KC_LCTL            | KC_DEL (can be used to close window in ALT_-TAB | KC_CAPS if GUI-tapped
// ---------------------------------------------------------------------------------------------------------------------------------------------
    KY_LALT,              // KC_LALT            | G(C(KC_LEFT)) if GUI-tapped
    KY_LGUI,              // KC_LGUI            | Work in tandem with KY_LCTL but it also register KC_CAPS if this key is released first
    KY_NMPD,              // LT(_NUM, KC_BSPC)  | MO(_SWAP) if any MOD-hold | G(C(KC_RGHT)) if GUI-tapped
    KY_LNAV,              // LT(_LNAV, KC_BPSC) | Custom LT so that it react as soon as user press it & prevent mis-type
    KY_RNAV,              // LT(_RNAV, KC_DEL)  | KC_MPRV if KY_PLAY-tapped
    KY_PLAY,              // KC_MPLY            & can be combined with KY_RNAV & KY_RALT for media scrubbing/control
    KY_RALT,              // KC_RALT            | RALT_T(KC_RGHT) if tapped (VSCode cursor navigation shortcut) | KC_MNXT if KY_PLAY-tapped
    KY_LBRC,              // KC_LBRC            | S(KC_0) if SHIFT-tapped this one is for left hand only typing
    KY_EQUA,              // KC_EQL             | S(KC_0) if SHIFT-tapped
// ---------------------------------------------------------------------------------------------------------------------------------------------
    NM_PLUS,              // KC_PPLS            | KC_PAST if being held (Auto Shift key)
    NM_MINS,              // KC_PMNS            | KC_PSLS if being held (Auto Shift key)
    NM_COMM,              // KC_COMM            | KC_PDOT if being held (Auto Shift key)
    NM_ENTR,              // KC_ENT             | KC_EQL  if being held (Auto Shift key)
    WN_POWR,              // KC_SLEP            | KC_PWR if SHIFT-tapped
    MS_MCLK,              // KC_ACL0            | KC_BTN3 if tapped
    MS_LOCK               //                    | Lock _MOUSE layer
};

#define WN_CLOS A(KC_F4)     // Close current window
#define WN_LOCK G(KC_L)      // Lock windows session
#define BR_NEXT C(KC_TAB)    // Next tab browser shortcut
#define BR_PREV S(C(KC_TAB)) // Previous tab browser shortcut
#define AP_SNIP KC_F13       // Snipaste shortcut to take a screenshot
#define AP_SNHD A(S(KC_F13)) // Snipaste shortcut to hide the screenshot
#define AP_MTJM A(KC_SLSH)   // VSCode's MetaJump plugin shortcut key
#define SFT_ENT KC_SFTENT

// K E Y M A P S |------------------------------------------------------------------------------------------------------------------------------

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KY_GRAV, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                         KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KY_TABS, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             KY_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                         KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             KY_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KY_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KY_EQUA,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        KY_LALT, KY_LGUI, KY_NMPD, KC_SPC ,       SFT_ENT, KY_RNAV, KY_PLAY, KY_RALT
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_NUM] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, AP_SNIP, KC_P7  , KC_P8  , KC_P9  , NM_PLUS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KY_LNAV, KC_P4  , KC_P5  , KC_P6  , NM_MINS,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_P0  , KC_P1  , KC_P2  , KC_P3  , NM_ENTR, _______,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, NM_COMM, _______, _______,       _______, _______, _______, _______
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

    [_SWAP] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             KC_ESC , KC_0   , KC_9   , KC_8   , KC_7   , KC_6   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,                         _______, _______, _______, _______, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   , KC_RBRC,       _______, _______, _______, _______, _______, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_RNAV] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_VOLU, KC_PGUP, KC_UP  , KC_PGDN, KC_F11 , WN_CLOS,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______,                         KC_MUTE, KC_LEFT, KC_DOWN, KC_RGHT, KC_F12 , WN_LOCK,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, KC_VOLD, KC_HOME, KC_BSPC, KC_END , AP_MTJM, WN_POWR,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, KC_APP , _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    ),

    [_MOUSE] = LAYOUT (
        // ┌────────┬────────┬────────┬────────┬────────┬────────┐                       ┌────────┬────────┬────────┬────────┬────────┬────────┐
             _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, MS_LOCK,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, BR_PREV, KC_MS_U, BR_NEXT, _______,                         _______, KC_WH_L, KC_WH_U, KC_WH_R, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┤                       ├────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,                         _______, KC_BTN1, MS_MCLK, KC_BTN2, _______, _______,
        // ├────────┼────────┼────────┼────────┼────────┼────────┼────────┐     ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
             _______, _______, _______, _______, _______, _______, _______,       _______, _______, KC_BTN4, KC_WH_D, KC_BTN5, _______, _______,
        // └────────┴────────┴────────┼────────┼────────┼────────┼────────┤     ├────────┼────────┼────────┼────────┼────────┴────────┴────────┘
                                        _______, _______, _______, _______,       _______, _______, _______, _______
        //                            └────────┴────────┴────────┴────────┘     └────────┴────────┴────────┴────────┘
    )
};

// C U S T O M   K E Y C O D E |----------------------------------------------------------------------------------------------------------------

uint16_t key_timer = 0;
bool other_key_pressed = false;
bool alt_ctrl_tabbing = false;
bool mouse_layer_lock = false;
bool ky_play_state = false;
bool ky_lbrc_autoshift = false;
bool ky_equa_autoshift = false;
bool nm_plus_autoshift = false;
bool nm_mins_autoshift = false;
bool nm_comm_autoshift = false;
bool nm_entr_autoshift = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t mods = get_mods();
    switch (keycode) {
        case KY_GRAV:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods & MOD_MASK_GUI) {
                    tap_code16(S(KC_RGHT));
                    return false;
                } else if (alt_ctrl_tabbing) {
                    tap_code16(S(KC_TAB));
                    return false;
                } else register_code(KC_GRV);
            } else unregister_code(KC_GRV);
            break;
        case KY_TABS:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if ((mods & (MOD_MASK_ALT | MOD_MASK_CTRL)) > 0) alt_ctrl_tabbing = true;
                register_code(KC_TAB);
            } else unregister_code(KC_TAB);
            break;
        case KY_LSFT:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LSFT);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_9);
                unregister_code(KC_LSFT);
                other_key_pressed = true;
            } break;
        case KY_LCTL:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                register_code(KC_LCTL);
            } else {
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) {
                    if (mods & MOD_MASK_GUI) tap_code(KC_CAPS);
                    else {
                        del_mods(MOD_MASK_CTRL);
                        tap_code(KC_DEL);
                        set_mods(mods);
                    }
                }

                unregister_code(KC_LCTL);
                alt_ctrl_tabbing = false;
                other_key_pressed = true;
            } break;
        case KY_LALT:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods & MOD_MASK_GUI) {
                    tap_code16(C(KC_LEFT));
                    return false;
                }

                register_code(KC_LALT);
            } else {
                unregister_code(KC_LALT);
                alt_ctrl_tabbing = false;
            } break;
        case KY_LGUI:
            if (record -> event.pressed) {
                key_timer = timer_read();
                register_code(KC_LGUI);
            } else {
                if (mods & MOD_MASK_CTRL && !other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_CAPS);
                unregister_code(KC_LGUI);
                other_key_pressed = true;
            } break;
        case KY_LNAV:
            if (record -> event.pressed) {
                other_key_pressed = false;
                key_timer = timer_read();
                layer_on(_LNAV);
            } else {
                layer_off(_LNAV);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_BSPC);
                other_key_pressed = true;
            } break;
        case KY_NMPD:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (mods & MOD_MASK_GUI) {
                    tap_code16(C(KC_RGHT));
                    return false;
                }

                key_timer = timer_read();
                if ((mods & (MOD_MASK_ALT | MOD_MASK_CTRL | MOD_MASK_SHIFT)) > 0) layer_on(_SWAP);
                else {
                    layer_on(_NUM);
                    if (!mouse_layer_lock) update_tri_layer(_NUM, _RNAV, _MOUSE);
                }
            } else {
                layer_off(_NUM);
                layer_off(_LNAV);
                layer_off(_SWAP);
                if (!mouse_layer_lock) update_tri_layer(_NUM, _RNAV, _MOUSE);
                if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_BSPC);
                other_key_pressed = true;
            } break;
        case KY_RNAV:
            if (record -> event.pressed) {
                other_key_pressed = false;
                if (ky_play_state) register_code(KC_MPRV);
                else {
                    key_timer = timer_read();
                    layer_on(_RNAV);
                    if (!mouse_layer_lock) update_tri_layer(_NUM, _RNAV, _MOUSE);
                }
            } else {
                if (ky_play_state) unregister_code(KC_MPRV);
                else {
                    layer_off(_RNAV);
                    if (!mouse_layer_lock) update_tri_layer(_NUM, _RNAV, _MOUSE);
                    if (!other_key_pressed && timer_elapsed(key_timer) < TAPPING_TERM) tap_code(KC_DEL);
                }

                other_key_pressed = true;
            } break;
        case KY_PLAY:
            if (record -> event.pressed) {
                other_key_pressed = false;
                ky_play_state = true;
            } else {
                if (!other_key_pressed) tap_code(KC_MPLY);
                ky_play_state = false;
            } break;
        case KY_RALT:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (ky_play_state) register_code(KC_MNXT);
                else register_code(KC_RALT);
            } else {
                if (ky_play_state) unregister_code(KC_MNXT);
                else {
                    unregister_code(KC_RALT);
                    alt_ctrl_tabbing = false;
                }
            } break;
        case KY_LBRC:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods & MOD_MASK_SHIFT) {
                    tap_code(KC_0);
                    return false;
                }

                key_timer = timer_read();
                ky_lbrc_autoshift = true;
            } else if (ky_lbrc_autoshift) {
                ky_lbrc_autoshift = false;
                tap_code(KC_LBRC);
            } break;
        case KY_EQUA:
            if (record -> event.pressed) {
                other_key_pressed = true;
                if (mods & MOD_MASK_SHIFT) {
                    tap_code(KC_0);
                    return false;
                }

                key_timer = timer_read();
                ky_equa_autoshift = true;
            } else if (ky_equa_autoshift) {
                ky_equa_autoshift = false;
                tap_code(KC_EQL);
            } break;
        case NM_PLUS:
            if (record -> event.pressed) {
                other_key_pressed = true;
                nm_plus_autoshift = true;
                key_timer = timer_read();
            } else if (nm_plus_autoshift) {
                nm_plus_autoshift = false;
                tap_code(KC_PPLS);
            } break;
        case NM_MINS:
            if (record -> event.pressed) {
                other_key_pressed = true;
                nm_mins_autoshift = true;
                key_timer = timer_read();
            } else if (nm_mins_autoshift) {
                nm_mins_autoshift = false;
                tap_code(KC_PMNS);
            } break;
        case NM_COMM:
            if (record -> event.pressed) {
                other_key_pressed = true;
                nm_comm_autoshift = true;
                key_timer = timer_read();
            } else if (nm_comm_autoshift) {
                nm_comm_autoshift = false;
                tap_code(KC_COMM);
            } break;
        case NM_ENTR:
            if (record -> event.pressed) {
                other_key_pressed = true;
                nm_entr_autoshift = true;
                key_timer = timer_read();
            } else if (nm_entr_autoshift) {
                nm_entr_autoshift = false;
                tap_code(KC_ENT);
            } break;
        case WN_POWR:
            if (record -> event.pressed) {
                other_key_pressed = true;
                mouse_layer_lock = false;
                if (mods & MOD_MASK_SHIFT) tap_code(KC_PWR);
                else                       tap_code(KC_SLEP);
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
        case MS_LOCK:
            if (record -> event.pressed) {
                mouse_layer_lock = mouse_layer_lock ? false : true;
                if (!mouse_layer_lock) update_tri_layer(_NUM, _RNAV, _MOUSE);
                return false;
            }
        default:
            other_key_pressed = true;
            break;
    }

    return true;
};

// Workaround to mimic AutoShift (trigger the second key if it pressed above the given time) on cutom key
void matrix_scan_user(void) {
    if (ky_lbrc_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code16(S(KC_LBRC));
            ky_lbrc_autoshift = false;
        }
    } else if (ky_equa_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code16(S(KC_EQL));
            ky_equa_autoshift = false;
        }
    } else if (nm_plus_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code(KC_PAST);
            nm_plus_autoshift = false;
        }
    } else if (nm_mins_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code(KC_PSLS);
            nm_mins_autoshift = false;
        }
    } else if (nm_comm_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code(KC_PDOT);
            nm_comm_autoshift = false;
        }
    } else if (nm_entr_autoshift) {
        if (timer_elapsed(key_timer) > AUTO_SHIFT_TIMEOUT) {
            tap_code(KC_EQL);
            nm_entr_autoshift = false;
        }
    }
};

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

    static const char PROGMEM separator[3][11] = {
        { 0x20, 0x9d, 0x9e, 0x9f, 0x20,
          0x20, 0x20, 0x20, 0x20, 0x20, 0
        }, // Normal (0)
        { 0x20, 0xbd, 0xbe, 0xbf, 0x20,
          0x20, 0xdd, 0xde, 0xdf, 0x20, 0
        }, // Caps (1)
        { 0x20, 0x5d, 0x5e, 0x5f, 0x20,
          0x20, 0x7d, 0x7e, 0x7f, 0x20, 0
        }, // _MOUSE layer lock (2)
    };
    static const char PROGMEM layer_state[6][6] = {
        { 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0 }, // QWERT  (0)
        { 0x8f, 0x90, 0x91, 0x92, 0x93, 0 }, // COLMAK (1) | NOT USED ATM
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
    if (mouse_layer_lock)                                     oled_write_P(separator[2], false);
    else if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) oled_write_P(separator[1], false);
    else                                                      oled_write_P(separator[0], false);

    if (layer_state_is(_MOUSE))                              oled_write_P(layer_state[4], false);
    else if (layer_state_is(_SWAP))                          oled_write_P(layer_state[5], false);
    else if (layer_state_is(_LNAV) || layer_state_is(_RNAV)) oled_write_P(layer_state[3], false);
    else if (layer_state_is(_NUM))                           oled_write_P(layer_state[2], false);
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

void oled_task_user(void) {
    if (is_keyboard_master()) render_master();
    else                      render_tawheed();
};

void suspend_power_down_user(void) {
    oled_off();
};

#endif // OLED_ENABLE
