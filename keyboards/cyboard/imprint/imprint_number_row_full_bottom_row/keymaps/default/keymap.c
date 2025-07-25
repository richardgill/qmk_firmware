/* Copyright 2023 Cyboard LLC (@Cyboard-DigitalTailor)
 * SPDX-License-Identifier: GPL-2.0-or-later
 */

#include QMK_KEYBOARD_H

#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LGUI_T(KC_S)
#define HOME_T LSFT_T(KC_T)

#define HOME_N RSFT_T(KC_N)
#define HOME_E RGUI_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

#define ESC_SYS  LT(SYS, KC_ESC)
#define BSPC_NAV LT(NAV, KC_BSPC)
#define SPC_SYM  LT(SYM, KC_SPC)
#define DEL_NUM  LT(NUM, KC_DEL)

enum layers {
    BASE,
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_num_full_bottom_row(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_NO,   KC_NO,
        KC_CAPS, HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,                      KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,  KC_CAPS,
        KC_NO,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                      KC_ENT,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   MO(EMOJI),
        KC_NO,   KC_NO,   ESC_SYS,
        ESC_SYS, BSPC_NAV, KC_NO,
        CW_TOGG, KC_NO,   KC_NO,   KC_F23,  CW_TOGG,
        SPC_SYM, KC_TAB,  DEL_NUM,
        DEL_NUM, KC_TAB,  KC_TAB
    ),
    [NAV] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, G(KC_X),                   G(KC_X), _______, _______, _______, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, G(KC_C),                   G(KC_C), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, _______, _______, _______, _______, G(KC_V),                   G(KC_V), KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______
    ),
    [SYM] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_EXLM, KC_LBRC, KC_QUOT, KC_DQUO, KC_RBRC, KC_QUES,                   _______, _______, _______, _______, _______, _______,
        KC_HASH, KC_CIRC, KC_EQL,  KC_UNDS, KC_DLR,  KC_ASTR,                   _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        KC_AT,   KC_LT,   KC_PIPE, KC_MINS, KC_GT,   KC_SLSH,                   _______, _______, _______, _______, _______, _______,
        KC_TILD, KC_AMPR, KC_LPRN, KC_RPRN, KC_PLUS,
        KC_PERC, KC_COLN, _______,
        _______, KC_BSLS, KC_DOT,
        KC_GRV,  KC_SCLN, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______
    ),
    [NUM] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                   _______, KC_4,    KC_5,    KC_6,    _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_1,    KC_2,    KC_3,    _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, KC_0,    _______
    ),
    [SYS] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, G(C(KC_Q)), _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______,
        _______, _______, _______, _______, _______, _______,                   _______, KC_VOLD, _______, _______, KC_VOLU, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______
    ),
    [EMOJI] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   UM(WAVE), _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, UM(THUMBS_UP), UM(CHECKMARK)
    ),
    [MOUSE] = LAYOUT_num_full_bottom_row(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______,
        _______, _______, _______, _______, _______,
        KC_BTN1, KC_BTN3, KC_BTN2,
        KC_BTN2, KC_BTN3, KC_BTN3
    )
};

// Tapping term: how long to hold a key before it becomes a modifier instead of typing the letter
// Index 145ms, Middle 210ms, Ring 240ms, Pinky 260ms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_T:
        case HOME_N:
            return 145;
        case HOME_S:
        case HOME_E:
            return 210;
        case HOME_R:
        case HOME_I:
            return 240;
        case HOME_A:
        case HOME_O:
            return 260;
        case ESC_SYS:
            return 200;
        case BSPC_NAV:
            return 170;
        case SPC_SYM:
            return 170;
        case DEL_NUM:
            return 200;
        default:
            return TAPPING_TERM;
    }
}

// Hold on other key press: immediately activates modifier when another key is pressed
// Enables all home row mods to trigger instantly when typing combos (like Ctrl+C)
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_R:
        case HOME_S:
        case HOME_T:
        case HOME_N:
        case HOME_E:
        case HOME_I:
        case HOME_O:
            return true;
        case ESC_SYS:
        case BSPC_NAV:
        case SPC_SYM:
        case DEL_NUM:
            return true;
        default:
            return false;
    }
}

// Quick tap term: prevents hold action if key is tapped again within this time
// Allows for key repeat while preventing accidental modifier activation
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SPC_SYM:
            return 120;
        case BSPC_NAV:
        case DEL_NUM:
            return 100;
        default:
            return QUICK_TAP_TERM;
    }
}

// Initialize pointing device with auto mouse feature
void pointing_device_init_user(void) {
    set_auto_mouse_layer(MOUSE);
    set_auto_mouse_enable(true);
}
