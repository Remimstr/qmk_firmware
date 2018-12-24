/* Copyright 2018 Carlos Filoteo
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
#ifdef LED_ENABLE
  #include "protocol/serial.h"
#endif

#define _______ KC_TRNS
#define LT3_TAB LT(3, KC_TAB)
#define MT_RSFT_ENT MT(MOD_RSFT, KC_ENT)

enum custom_keycodes {
    LED_TOG = SAFE_RANGE,
    LED_CHG
};

// Version 1 of Remi's custom UT47 config

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Base Layer
   * ,-------------------------------------------------------------------------.
   * | Esc |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |Bspace |
   * |-------------------------------------------------------------------------+
   * | Down |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  | Spc |  UP  |
   * |-------------------------------------------------------------------------+
   * | Tab   |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  .  |  :  |  '  |Vol+ |
   * |-------------------------------------------------------------------------+
   * |     |     | Fn  |Ctrl | Win |   Shift    | Alt  | <-  | DWN | UP  | ->  |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_ESC,  KC_Q,    KC_W,    KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,     KC_BSPC,
  MO(3),   KC_A,    KC_S,    KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_SPC,   MO(2),
  KC_TAB , KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_DOT,  KC_COLON, KC_QUOTE, KC_AUDIO_VOL_UP,
  _______, _______, _______, KC_LCTRL, KC_LGUI,      MO(1),       KC_LALT, KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT
),

  /* FN Layer 1 (Shift)
   * ,-------------------------------------------------------------------------.
   * |RESET|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  | Delete|
   * |-------------------------------------------------------------------------+
   * |      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  | Ret |      |
   * |-------------------------------------------------------------------------+
   * |       |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  ;  | ''  | Vol-|
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     | Mute|
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  RESET,    S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),   S(KC_U),    S(KC_I),    S(KC_O),    S(KC_P),          KC_DELETE,
  _______,  S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),   S(KC_J),    S(KC_K),    S(KC_L),    KC_ENTER,         _______,
  KC_CAPS,  S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),   S(KC_M),    KC_COMMA,   KC_SCOLON,  KC_DOUBLE_QUOTE,  KC_AUDIO_VOL_DOWN,
  _______,  _______,    _______,    _______,    _______,          _______,         _______,    _______,    _______,    _______,          KC_AUDIO_MUTE
),

  /* FN Layer 2 (UP)
   * ,-------------------------------------------------------------------------.
   * |     |  1  |  3  |  6  |  7  |  9  |     |     |  +  |  *  |  =  |       |
   * |-------------------------------------------------------------------------+
   * |      |  2  |  4  |  5  |  8  |  0  |     |     |  -  |  /  |  %  |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  _______, KC_1,    KC_3,    KC_5,    KC_7,    KC_9,    _______, _______, KC_PLUS,  KC_ASTERISK, KC_EQUAL,   _______,
  _______, KC_2,    KC_4,    KC_6,    KC_8,    KC_0,    _______, _______,  KC_MINUS, KC_SLASH,    KC_PERCENT, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,     _______,    _______,
  _______, _______, _______, _______, _______,      _______,     _______,  _______,  _______,     _______,    _______
),

  /* FN Layer 3 (DOWN)
   * ,-------------------------------------------------------------------------.
   * |     |  (  |  {  |  [  |  <  |     |     |  |  |  !  |  @  |  #  |       |
   * |-------------------------------------------------------------------------+
   * |      |  )  |  }  |  ]  |  >  |     |     |  \  |  ?  |  &  |  ~  |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     | DWN |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  _______, KC_LEFT_PAREN,  KC_LEFT_CURLY_BRACE,  KC_LBRACKET, KC_LEFT_ANGLE_BRACKET,  _______, _______, KC_PIPE,   KC_EXCLAIM,  KC_AT,        KC_HASH,    _______,
  _______, KC_RIGHT_PAREN, KC_RIGHT_CURLY_BRACE, KC_RBRACKET, KC_RIGHT_ANGLE_BRACKET, _______, _______, KC_BSLASH, KC_QUESTION, KC_AMPERSAND, KC_TILDE, _______,
  _______, _______,        _______,              _______,     _______,                _______, _______, _______,   _______,     _______,      _______,    _______,
  _______, _______,        _______,              _______,              _______,                _______, _______,   _______,     _______,      _______,    _______
)
};

//LED keymap functions
 #ifdef LED_ENABLE
void led_chmode(void) {
  serial_send(101);
}

void led_toggle(void) {
  serial_send(100);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case LED_TOG:
        #ifdef LED_ENABLE
        led_toggle();
        #endif
        return false;
      case LED_CHG:
        #ifdef LED_ENABLE
        led_chmode();
        #endif
        return false;
    }
  }
  return true;
};
#endif
