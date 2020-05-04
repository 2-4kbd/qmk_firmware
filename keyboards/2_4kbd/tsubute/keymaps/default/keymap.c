/* Copyright 2019 2_4kbd
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define KC_XXXXXXX KC_NO
#define KC________ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L, KC_MINS, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
             KC_LALT,KC_LCTRL,   LOWER,  KC_SPC,  KC_RSFT,   RAISE,KC_RCTRL, KC_RGUI           \
  ),
  [_LOWER] = LAYOUT( \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_PGUP, KC_HOME,   KC_UP,  KC_END, KC_PGDN, \
       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, XXXXXXX, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_ENT, \
      KC_F11,  KC_F12,  KC_TAB,  KC_ESC, KC_CAPS, KC_BSPC,  KC_DEL, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_RAISE] = LAYOUT( \
     KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_ADJUST] = LAYOUT( \
     XXXXXXX, KC_TILD, KC_COLN, KC_DQUO, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, XXXXXXX, XXXXXXX, \
     XXXXXXX,  KC_GRV, KC_SCLN, KC_QUOT,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, XXXXXXX, XXXXXXX, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  )
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

  }

  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
