/* Copyright 2022 dlucenad
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keymap_br_abnt2.h"

enum layers {
  _QWERTY,
  _SYM,
  _FUNCTION,
//  _MIDI,
  _NAV,
  _NUM,
  _ADJUST
  
};

enum planck_keycodes {
  QWERTY//,
//  MIDI
};

#define SYM MO(_SYM)
#define FUN LT(_FUNCTION, KC_DOWN)
#define MYTAB LT(_NAV, KC_TAB)
#define MYNAV LT(_NAV, KC_DEL)
#define MYNUM LT(_NUM, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//qwerty base layer ok
[_QWERTY] = LAYOUT_planck_mit(
            KC_GRV,    KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,    KC_Y,  KC_U,            KC_I,   KC_O,    KC_P, BR_ACUT,
             MYTAB,    KC_A,    KC_S,  KC_D,  KC_F,  KC_G,    KC_H,  KC_J,            KC_K,   KC_L, BR_CCED, BR_TILD,
           KC_LSPO,    KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,    KC_N,  KC_M,         KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
    LCTL_T(KC_ENT), KC_LGUI, KC_LALT,   SYM, MYNAV,      KC_SPC,    MYNUM, RALT_T(KC_LEFT),    FUN,   KC_UP, RCTL_T(KC_RGHT)
),

//navigation and utility layer ok
[_NAV] = LAYOUT_planck_mit(
     KC_ESC, _______, _______, _______, _______, _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP, KC_VOLU,
    _______, _______, _______, _______, _______, _______,  KC_ENT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_VOLD,
    _______, _______, _______, _______, _______, _______, _______, KC_BSPC,  KC_DEL, _______, _______, KC_MUTE,
    _______, _______, _______, _______, _______,     _______,        MYNUM, _______, KC_MPRV, KC_MPLY, KC_MNXT
),

//symbols layer ok
[_SYM] = LAYOUT_planck_mit(
    BR_UNDS, BR_EXLM,   BR_AT, BR_HASH, BR_DLR,  BR_PERC, BR_DIAE, BR_AMPR, BR_ASTR, BR_LPRN, BR_RPRN, BR_MINS,
    _______, BR_BSLS, BR_PIPE, BR_SLSH, _______, _______,  KC_ENT, BR_PLUS, BR_UNDS, BR_LBRC, BR_RBRC, BR_UNDS,
    KC_CAPS, _______, _______, _______, _______, _______, _______,  BR_EQL, BR_MINS, BR_LCBR, BR_RCBR, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

//numbers layer ok
[_NUM] = LAYOUT_planck_mit(
     KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, BR_MINS,
    _______, BR_PLUS, BR_MINS, BR_SLSH, BR_ASTR,  BR_EQL,  KC_ENT,    KC_4,    KC_5,    KC_6, BR_COMM, BR_PLUS,
    _______, BR_PERC, BR_EQL,  BR_COMM,  BR_DOT, _______, KC_CALC,    KC_1,    KC_2,    KC_3,  BR_DOT,  BR_EQL,
    _______, _______, _______, _______,  MYNAV,      _______,      _______,    KC_0,    KC_0, KC_COMM,  KC_ENT
),

//FN layer ok
[_FUNCTION] = LAYOUT_planck_mit(
     KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______, _______, _______, _______, _______, KC_PSCR,  KC_INS,
    _______,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______, _______, _______, _______, _______, _______, KC_PAUS,
    _______,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),

// adjust layer ok
[_ADJUST] = LAYOUT_planck_mit(
      RESET, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______,
    _______,RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______,  QWERTY, _______, _______, _______, _______,
    _______,   MI_ON,  MI_OFF,  MI_TOG,   MU_ON,  MU_OFF,  MU_TOG,  MU_MOD,   AU_ON,  AU_OFF, _______, _______,
    RGB_TOG, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
)/*,

// midi layer
[_MIDI] = LAYOUT_planck_mit(
    MI_Cs,   MI_Ds,   _______, MI_Fs,   MI_Gs,   MI_As,   _______, MI_Cs,   MI_Ds,   _______, MI_Fs,   MI_Gs,
    MI_C,    MI_D,    MI_E,    MI_F,    MI_G,    MI_A,    MI_B,    MI_C,    MI_D,    MI_E,    MI_F,    MI_G,
    MI_BENDU,MI_OCTU, MI_TRNSU,MI_VELU, _______, _______, _______, _______, _______, MI_ON,   MI_CHU,  MI_TOG,
    MI_BENDD,MI_OCTD, MI_TRNSD,MI_VELD, MYNAV,       MI_SUS,       MYNUM, _______,   MI_OFF,  MI_CHD,  MI_ALLOFF
)*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
/*    case MIDI:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MIDI);
      }
      return false;
*/ }
   return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _NAV, _NUM, _ADJUST);
}
