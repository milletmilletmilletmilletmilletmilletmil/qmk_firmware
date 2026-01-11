#include QMK_KEYBOARD_H
#define TENKEY 0
#define MCRPAD 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [TENKEY] = LAYOUT(
    KC_1,   KC_7, KC_8,    KC_9,    KC_BSPC, 
    KC_1,   KC_4, KC_5,    KC_6,    KC_ENT, 
    KC_1,   KC_1, KC_2,    KC_3,    KC_ESC, 
                  KC_LSFT, KC_LCTL, MO(1)
  ),
  /*For Paint.net*/
  [MCRPAD] = LAYOUT(
    C(KC_A),    KC_T,    KC_G,    KC_F,    KC_DEL,
              /*TEXT*/ /*GRAD*/ /*FILL*/
    C(KC_Y),    KC_P,    KC_S,    KC_K,    KC_ENT,
              /*PNCL*/ /*SLCT*/ /*PICK*/
    C(KC_Z),    KC_B,    KC_E,    KC_M,    KC_ESC,
              /*BRSH*/ /*ERSE*/ /*MOVE*/
                C(KC_C), C(KC_V), KC_TRNS
  ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Zoom, zoom out, only US layout*/
        if (clockwise) {
            tap_code16(C(KC_MINS));
        } else {
            tap_code16(C(KC_EQL));
        }
    } else if (index == 1) { /* Move up, move down */
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    } else if (index == 2) { /*Brush size up, down*/
        if (clockwise) {
            tap_code(KC_LBRC);
        } else {
            tap_code(KC_RBRC);
        }
        
    }
    return false;
}