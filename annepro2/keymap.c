#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FN1_LAYER,
  _FN2_LAYER,
};

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  \  | DELETE |
* |-----------------------------------------------------------------------------------------+
* |   FN1   |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  Ctrl |  FN2  |  FN1  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
    		KC_GRV,    KC_1,    KC_2,   KC_3,    KC_4, KC_5, KC_6, KC_7,    KC_8,   KC_9,     KC_0,       KC_MINS,  KC_EQL, KC_BSPC,
    		KC_TAB,    KC_Q,    KC_W,   KC_E,    KC_R, KC_T, KC_Y, KC_U,    KC_I,   KC_O,     KC_P,       KC_LBRC, KC_NUBS, KC_DEL,
    TT(_FN1_LAYER),    KC_A,    KC_S,   KC_D,    KC_F, KC_G, KC_H, KC_J,    KC_K,   KC_L,  KC_SCLN,       KC_QUOT, KC_ENT,
    	   KC_LSFT,    KC_Z,    KC_X,   KC_C,    KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP),
    	   KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, RCTL_T(KC_LEFT) , LT(_FN2_LAYER,KC_DOWN), LT(_FN1_LAYER,KC_RGHT)
),
  /*
  * Layer _FN1_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Esc |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |   Bksp    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps   |     | UP  | END |     |     |     | HOME | UP | END | PS |   ]  | \  | DELETE  |
  * |-----------------------------------------------------------------------------------------+
  * |   FN1   |LEFT |DOWN |RIGHT|     |     |HOME |LEFT |DOWN |RIGHT|     |     |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-DWN |V-UP|MUTE |PREV |PAUSE| NEXT|     |PGUP |PGDWN|     |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  Ctrl |  FN2  |  FN1  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN1_LAYER] = KEYMAP( /* Layer 1 */
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
    KC_CAPS, _______,   KC_UP,  KC_END, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PSCR, KC_RBRC, KC_BSLS, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_PGUP, KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
),
  /*
  * Layer _FN2_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Esc | BT1 | BT2 |     |     |      |    |     |    |LED_S|LLEDOF|LEDON|LED_I |   Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |     | UP  | END |     |     |     | HOME | UP | END | PS |   ]  | \  | DELETE  |
  * |-----------------------------------------------------------------------------------------+
  * |   FN1   |LEFT |DOWN |RIGHT|     |     |HOME |LEFT |DOWN |RIGHT|     |     |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-DWN |V-UP|MUTE |PREV |PAUSE| NEXT|     |PGUP |PGDWN|     |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  Ctrl |  FN2  |  FN1  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FN2_LAYER] = KEYMAP( /* Layer 2 */
    _______, KC_AP2_BT1, KC_AP2_BT2, _______, _______, _______, _______, _______, _______, KC_AP_LED_SPEED, KC_AP_LED_OFF, KC_AP_LED_ON, KC_AP_LED_NEXT_INTENSITY, _______,
    _______, _______,   KC_UP,  KC_END, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PSCR, KC_RBRC, KC_BSLS, _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,
    _______, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_PGUP, KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}

// Code to run after initializing the keyboard
void keyboard_post_init_user(void) {
    // Here are two common functions that you can use. For more LED functions, refer to the file "qmk_ap2_led.h"

    // annepro2-shine disables LEDs by default. Uncomment this function to enable them at startup.
    annepro2LedEnable();

    // Additionally, it also chooses the first LED profile by default. Refer to the "profiles" array in main.c in
    // annepro2-shine to see the order. Replace "i" with the index of your preferred profile. (i.e the RED profile is index 0)
    annepro2LedSetProfile(0);
}