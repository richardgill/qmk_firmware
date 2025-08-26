/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

// Use LT (layer-tap) for home row mods, which handles the layer switching
// We'll add the modifier functionality in process_record_user
#define HOME_A LT(LEFT_MODS_HELD, KC_A)
#define HOME_R LT(LEFT_MODS_HELD, KC_R)
#define HOME_S LT(LEFT_MODS_HELD, KC_S)
#define HOME_T LT(LEFT_MODS_HELD, KC_T)

#define HOME_N LT(RIGHT_MODS_HELD, KC_N)
#define HOME_E LT(RIGHT_MODS_HELD, KC_E)
#define HOME_I LT(RIGHT_MODS_HELD, KC_I)
#define HOME_O LT(RIGHT_MODS_HELD, KC_O)

#define ESC_SYS  LT(SYS, KC_ESC)
#define BSPC_NAV LT(NAV, KC_BSPC)
#define BTN3_NAV LT(NAV, KC_BTN3)
#define SPC_SYM  LT(SYM, KC_SPC)
#define DEL_NUM  LT(NUM, KC_DEL)

enum layers {
    BASE,
    LEFT_MODS_HELD,  // Layer activated when left-hand home row mods are held
    RIGHT_MODS_HELD, // Layer activated when right-hand home row mods are held
    NAV,
    SYM,
    NUM,
    SYS,
    EMOJI,
    MOUSE
};

enum unicode_names {
    CHECKMARK,
    THUMBS_UP,
    WAVE
};

const uint32_t PROGMEM unicode_map[] = {
    [CHECKMARK] = 0x2705,   // ✅
    [THUMBS_UP] = 0x1F44D,  // 👍
    [WAVE]      = 0x1F44B,  // 👋
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_num_full_bottom_row(
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L', 'L',                     'R', 'R', 'R', 'R', 'R', 'R',

        'L', 'L', 'L', 'L', 'L',

        /* Top left thumb cluster */
        'L', 'L', 'L',
        /* Top right thumb cluster */
        'R', 'R', 'R',
        /* Bottom row right side */
        'R', 'R', 'R', 'R', 'R',
        /* Bottom left thumb cluster row */
        'L', 'L', 'L',
        /* Bottom right thumb cluster row */
        'R', 'R', 'R'
    );

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_NO,   KC_NO,
        KC_CAPS, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                      KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_CAPS,
        KC_NO,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_NO,   KC_NO,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(EMOJI),

        /* Top left thumb cluster  */
        ESC_SYS, KC_NO, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NUBS, KC_ENTER,
        /* Bottom row right side */
        KC_F23, KC_NO,   KC_NO,   KC_NO,  KC_NO,
        /* Bottom left thumb cluster row */
        BSPC_NAV, DEL_NUM, CW_TOGG,
        /* Bottom right thumb cluster row */
        CW_TOGG, KC_TAB,  SPC_SYM
    ),
    // When any left-hand home row mod is held, replace left-hand keys with KC_NO or modifiers
    // This prevents accidental same-hand key activations while allowing opposite-hand shortcuts
    [LEFT_MODS_HELD] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        /* Top left thumb cluster  */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Top right thumb cluster  */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom row right side */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom left thumb cluster row */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom right thumb cluster row */
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [RIGHT_MODS_HELD] = LAYOUT_num_full_bottom_row(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

        /* Top left thumb cluster  */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Top right thumb cluster  */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom row right side */
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom left thumb cluster row */
        KC_TRNS, KC_TRNS, KC_TRNS,
        /* Bottom right thumb cluster row */
        KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   G(KC_X),                   G(KC_X), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, G(KC_C),                   G(KC_C), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   G(KC_V),                   G(KC_V), KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        /* Top left thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Bottom row right side */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        KC_NO, KC_NO, KC_NO,
        /* Bottom right thumb cluster row */
        KC_NO, KC_NO, KC_NO
    ),
    [SYM] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_GRV,  KC_LPRN, KC_RPRN, KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_EXLM, KC_LCBR, KC_QUOT, KC_DQUO, KC_RCBR, KC_QUES,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_HASH, KC_CIRC, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR,                   KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_NO,
        KC_AT,   KC_LT,   KC_PIPE, KC_MINS, KC_GT,   KC_SLSH,                   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        KC_TILD, KC_AMPR, KC_LBRC, KC_RBRC, KC_PLUS,

        /* Top left thumb cluster  */
        KC_BSLS, KC_DOT, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Bottom row right side */
        KC_GRV,  KC_SCLN, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        KC_PERC, KC_COLN, KC_SCLN,
        /* Bottom right thumb cluster row */
        KC_NO, KC_NO, KC_NO
    ),
    [NUM] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                     KC_NO,   KC_4,    KC_5,    KC_6,    KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        /* Top left thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Bottom row right side */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        KC_NO, KC_NO, KC_NO,
        /* Bottom right thumb cluster row */
        KC_NO,   KC_NO,   KC_0
    ),
    [SYS] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,       KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   G(C(KC_Q)), KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_MPRV,     KC_MSTP, KC_MPLY, KC_MNXT, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_VOLD,     KC_NO,   KC_NO,   KC_VOLU, KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        /* Top left thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Bottom row right side */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        KC_NO, KC_NO, KC_NO,
        /* Bottom right thumb cluster row */
        KC_NO, KC_NO, KC_NO
    ),
    [EMOJI] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     UM(WAVE), KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        /* Top left thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Top right thumb cluster  */
        KC_NO, KC_NO, KC_NO,
        /* Bottom row right side */
        UM(CHECKMARK), KC_NO, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        KC_NO, KC_NO, KC_NO,
        /* Bottom right thumb cluster row */
        KC_NO, KC_NO, UM(THUMBS_UP)
    ),
    [MOUSE] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,

        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

        /* Top left thumb cluster  */
        KC_BTN1, KC_BTN2, KC_NO,
        /* Top right thumb cluster  */
        KC_BTN1, KC_BTN2, KC_NO,
        /* Bottom row right side */
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        /* Bottom left thumb cluster row */
        BTN3_NAV, KC_NO,   KC_NO,
        /* Bottom right thumb cluster row */
        KC_NO,   KC_BTN3, KC_NO
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_T:
        case HOME_N:
            return TAPPING_TERM - 55;
        case HOME_S:
        case HOME_E:
            return TAPPING_TERM + 10;
        case HOME_R:
        case HOME_I:
            return TAPPING_TERM + 40;
        case HOME_A:
        case HOME_O:
            return TAPPING_TERM + 60;
        case ESC_SYS:
            return TAPPING_TERM;
        case BSPC_NAV:
            return TAPPING_TERM - 30;
        case SPC_SYM:
            return TAPPING_TERM - 30;
        case DEL_NUM:
            return TAPPING_TERM;
        default:
            return TAPPING_TERM;
    }
}

// Quick tap term: prevents hold action if key is tapped again within this time
// Allows for key repeat while preventing accidental modifier activation
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return RICH_QUICK_TAP_TERM;
    }
}

// Initialize pointing device with auto mouse feature
void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE);
    set_auto_mouse_enable(true);
}

// Initialize keyboard - enable left dragscroll on startup
void keyboard_post_init_user(void) {
    charybdis_set_pointer_dragscroll_enabled(true, true);

    // Set different DPI for left and right trackballs
    charybdis_cycle_pointer_default_dpi(true, true);  // Left up once

    charybdis_cycle_pointer_default_dpi(true, false); // Right up once
}

// Process home row mods to add modifier functionality to layer-tap keys
// LT() handles the layer switching, here we just add the modifiers
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Check if this is a home row mod being held (not tapped)
    // record->tap.count == 0 means it's being held
    if (!record->tap.count && record->event.pressed) {
        // A key is being held - check which one and apply the appropriate modifier
        switch (keycode) {
            case HOME_A:  // LT(LEFT_MODS_HELD, KC_A)
                register_code(KC_LGUI);
                break;
            case HOME_R:  // LT(LEFT_MODS_HELD, KC_R)
                register_code(KC_LALT);
                break;
            case HOME_S:  // LT(LEFT_MODS_HELD, KC_S)
                register_code(KC_LCTL);
                break;
            case HOME_T:  // LT(LEFT_MODS_HELD, KC_T)
                register_code(KC_LSFT);
                break;
            case HOME_N:  // LT(RIGHT_MODS_HELD, KC_N)
                register_code(KC_RSFT);
                break;
            case HOME_E:  // LT(RIGHT_MODS_HELD, KC_E)
                register_code(KC_RCTL);
                break;
            case HOME_I:  // LT(RIGHT_MODS_HELD, KC_I)
                register_code(KC_RALT);
                break;
            case HOME_O:  // LT(RIGHT_MODS_HELD, KC_O)
                register_code(KC_RGUI);
                break;
        }
    } else if (!record->tap.count && !record->event.pressed) {
        // A held key is being released - unregister the modifier
        switch (keycode) {
            case HOME_A:
                unregister_code(KC_LGUI);
                break;
            case HOME_R:
                unregister_code(KC_LALT);
                break;
            case HOME_S:
                unregister_code(KC_LCTL);
                break;
            case HOME_T:
                unregister_code(KC_LSFT);
                break;
            case HOME_N:
                unregister_code(KC_RSFT);
                break;
            case HOME_E:
                unregister_code(KC_RCTL);
                break;
            case HOME_I:
                unregister_code(KC_RALT);
                break;
            case HOME_O:
                unregister_code(KC_RGUI);
                break;
        }
    }
    return true;  // Let QMK handle the layer-tap functionality for other keys
}

// Flow Tap configuration - only apply to home row mods, not layer taps
/* bool is_flow_tap_key(uint16_t keycode) { */
/*     switch (keycode) { */
/*         // Home row mods - enable flow tap for these */
/*         case HOME_A: */
/*         case HOME_R: */
/*         case HOME_S: */
/*         case HOME_T: */
/*         case HOME_N: */
/*         case HOME_E: */
/*         case HOME_I: */
/*         case HOME_O: */
/*             return false; */
/*         // Layer taps - disable flow tap so they work reliably */
/*         case ESC_SYS: */
/*         case BSPC_NAV: */
/*         case SPC_SYM: */
/*         case DEL_NUM: */
/*             return false; */
/*         default: */
/*             // For regular keys, check if they're in the main typing area */
/*             if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) { */
/*                 return false; // Disable Flow Tap on hotkeys */
/*             } */
/*             switch (keycode) { */
/*                 case KC_A ... KC_Z: */
/*                 case KC_DOT: */
/*                 case KC_COMM: */
/*                 case KC_SCLN: */
/*                 case KC_SLSH: */
/*                 case KC_SPC: */
/*                     return false; */
/*             } */
/*             return false; */
/*     } */
/* } */

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case BSPC_NAV:
            return true;  // allow same hand permissive holds since copy and paste are same hands
        default:
            return get_chordal_hold_default(tap_hold_record, other_record);  // Use default opposite-hands rule for everything else
    }
}



