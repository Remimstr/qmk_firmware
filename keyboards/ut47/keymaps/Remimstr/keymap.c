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
   * |DWN(3)|  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  :  |UP(2) |
   * |-------------------------------------------------------------------------+
   * |Tab/SFT|  z  |  x  |  c  |  v  |  b  |  n  |  m  |  .  |  '  |  /  |Vol+ |
   * |-------------------------------------------------------------------------+
   * |     |     | Alt | Win |Ctrl | SFT(1)/SPC | RET  |MV(4)|     |Mute |Vol- |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_ESC,               KC_Q,    KC_W,    KC_E,     KC_R,                KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,          KC_BSPC,
  MO(3),                KC_A,    KC_S,    KC_D,     KC_F,                KC_G,    KC_H,    KC_J,    KC_K,    KC_L,     KC_COLON,      MO(2),
  MT(MOD_LSFT, KC_TAB), KC_Z,    KC_X,    KC_C,     KC_V,                KC_B,    KC_N,    KC_M,    KC_DOT,  KC_QUOTE, KC_SLASH,      KC_AUDIO_VOL_UP,
  _______,              _______, KC_LALT, KC_LGUI,  KC_LCTRL,            LT(1, KC_SPACE),  KC_ENTER,TT(4),   _______,  KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN
),

  /* FN Layer 1 (Shift)
   * ,-------------------------------------------------------------------------.
   * |     |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |Delete |
   * |-------------------------------------------------------------------------+
   * |      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |      |
   * |-------------------------------------------------------------------------+
   * | CAPS  |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  | ''  |  \  |     |
   * |-------------------------------------------------------------------------+
   * |RESET|     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  _______,  S(KC_Q),    S(KC_W),    S(KC_E),    S(KC_R),    S(KC_T),    S(KC_Y),   S(KC_U),    S(KC_I),    S(KC_O),         S(KC_P),      KC_DELETE,
  _______,  S(KC_A),    S(KC_S),    S(KC_D),    S(KC_F),    S(KC_G),    S(KC_H),   S(KC_J),    S(KC_K),    S(KC_L),         KC_SCOLON,    _______,
  KC_CAPS,  S(KC_Z),    S(KC_X),    S(KC_C),    S(KC_V),    S(KC_B),    S(KC_N),   S(KC_M),    KC_COMMA,   KC_DOUBLE_QUOTE, KC_BSLASH,    _______,
  RESET,    _______,    _______,    _______,    _______,          _______,         _______,    _______,    _______,         _______,      _______
),

  /* FN Layer 2 (UP)
   * ,-------------------------------------------------------------------------.
   * |  0  |  1  |  2  |  3  |     |     |     |  +  |  *  |  ^  |  $  |       |
   * |-------------------------------------------------------------------------+
   * |      |  4  |  5  |  6  |     |     |     |  -  |  %  |  =  |  #  |      |
   * |-------------------------------------------------------------------------+
   * |       |  7  |  8  |  9  |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  KC_0,     KC_1,    KC_2,    KC_3,    _______, _______, _______, KC_PLUS,   KC_ASTERISK, KC_CIRCUMFLEX,   KC_DOLLAR, _______,
  _______,  KC_4,    KC_5,    KC_6,    _______, _______, _______, KC_MINUS,  KC_PERCENT,  KC_EQUAL,        KC_HASH,   _______,
  _______,  KC_7,    KC_8,    KC_9,    _______, _______, _______, _______,   _______,     _______,         _______,   _______,
  _______,  _______, _______, _______, _______,      _______,     _______,   _______,     _______,         _______,   _______
),

  /* FN Layer 3 (DOWN)
   * ,-------------------------------------------------------------------------.
   * |     |     |  (  |  {  |  [  |  <  |     |  &  |  !  |  ~  |     |       |
   * |-------------------------------------------------------------------------+
   * |      |     |  )  |  }  |  ]  |  >  |     |  _  |  ?  |     |     |      |
   * |-------------------------------------------------------------------------+
   * |       |     |     |     |     |     |     |     |     |  `  |  |  |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |     |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  _______, _______,  KC_LEFT_PAREN,  KC_LEFT_CURLY_BRACE,  KC_LBRACKET, KC_LEFT_ANGLE_BRACKET,  _______,   KC_AMPERSAND,  KC_EXCLAIM,  KC_TILDE,     _______,        _______,
  _______, _______,  KC_RIGHT_PAREN, KC_RIGHT_CURLY_BRACE, KC_RBRACKET, KC_RIGHT_ANGLE_BRACKET, _______,   KC_UNDERSCORE, KC_QUESTION, _______,      _______,        _______,
  _______, _______,  _______,        _______,              _______,     _______,                _______,   _______,       _______,     KC_GRAVE,     KC_PIPE,        _______,
  _______, _______,  _______,        _______,              _______,                             _______,   _______,       _______,     _______,      _______,        _______
),

  /* FN Layer 4 (ARROW)
   * ,-------------------------------------------------------------------------.
   * |  0  |  1  |  2  |  3  |     |     |     |     |     |     |     |       |
   * |-------------------------------------------------------------------------+
   * |      |  4  |  5  |  6  |     |     |LEFT |DOWN | UP  |RIGHT|      |     |
   * |-------------------------------------------------------------------------+
   * |       |  7  |  8  |  9  |     |     |     |     |     |     |     |     |
   * |-------------------------------------------------------------------------+
   * |     |     |     |     |      |          |       |     |     |UMOV |     |
   * `-------------------------------------------------------------------------'
   */

LAYOUT(
  _______, KC_1,    KC_2,    KC_3,    _______, _______, _______, _______, _______, _______,  _______, _______,  
  _______, KC_4,    KC_5,    KC_6,    _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,  
  _______, KC_7,    KC_8,    KC_9,    _______, _______, _______, _______, _______, _______,  _______, _______,  
  _______, _______, _______, _______, _______,      _______,     _______, _______, _______,  _______, _______ 
) 
};

//LED keymap functions
 #ifdef LED_ENABL5
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
