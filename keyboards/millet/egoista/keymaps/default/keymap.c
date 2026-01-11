#include QMK_KEYBOARD_H
#define _LAYER0 0
#define _LAYER1 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LAYER0] = LAYOUT(
    KC_MUTE,  KC_ESC,    KC_1,      KC_2,     KC_3,     KC_4,     KC_5,     KC_6,                KC_7,     KC_8,     KC_9,     KC_0,     KC_MINUS,   KC_EQUAL,   KC_BSPC,
    KC_HOME,  KC_PGUP,   KC_TAB,    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,      KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,
    KC_END,   KC_PGDN,   KC_CAPS,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,    KC_QUOT,    KC_ENT,
              KC_UP,     KC_LSFT,   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                          KC_N,     KC_M,     KC_COMM,  KC_DOT,     KC_SLSH,    KC_RSFT,
    KC_LEFT,  KC_DOWN,   KC_RIGHT,  KC_LWIN,            KC_SPC,   KC_LCTL,                                           MO(1),    KC_SPC,   KC_APP,     KC_RALT,    KC_RCTL
   ),
   [_LAYER1] = LAYOUT(
    KC_NUM,   KC_TRNS,   KC_F1,     KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,               KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,     KC_DEL,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_KP_4,  KC_KP_5,  KC_KP_6,             KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
              KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_KP_1,  KC_KP_2,  KC_KP_3,                       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,            KC_TRNS,  KC_KP_0,                                           KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS
   ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}