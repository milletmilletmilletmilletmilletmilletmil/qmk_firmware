#include QMK_KEYBOARD_H
#define TENKEY 0
#define MCRPAD 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [TENKEY] = LAYOUT(
    KC_NUM,   KC_P7, KC_P8,    KC_P9,   KC_BSPC, 
   KC_PPLS,   KC_P4, KC_P5,    KC_P6,    KC_ENT, 
   KC_PMNS,   KC_P1, KC_P2,    KC_P3,    KC_PSLS, 
                     KC_P0,  KC_PDOT, MO(1)
  ),
  /*For Paint.net*/
  [MCRPAD] = LAYOUT(
    C(KC_A),    C(KC_N),    ALT_T(KC_H),C(KC_W),    KC_DEL,
                /*NTAB*/    /*GRAD*/    /*CLSE*/
    C(KC_C),    C(KC_X),    C(KC_H),    C(KC_F),    KC_ENT,
                /*CUTT*/    /*RPLC*/    /*FIND*/
    C(KC_V),    C(KC_S),    C(KC_P),    C(KC_B),    KC_ESC,
                /*SAVE*/    /*PRNT*/    /*BOLD*/
                C(KC_Z), C(KC_Y), KC_TRNS
  ),
};


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* Zoom up, zoom down */
        if (clockwise) {
            tap_code16(C(KC_EQL));
        } else {
            tap_code16(C(KC_MINS));
        }
    } else if (index == 1) { /* left, right */
        if (clockwise) {
            tap_code(KC_LEFT);
        } else {
            tap_code(KC_RIGHT);
        }
    } else if (index == 2) { /* Volume up, down*/
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        
    }
    return false;
}