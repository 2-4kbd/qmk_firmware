#include QMK_KEYBOARD_H
#include "bootloader.h"

#include "keymap_jp.h"

extern keymap_config_t keymap_config;
extern uint8_t is_master;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _QWERTYJP 4
#define _LOWERJP 5
#define _RAISEJP 6
#define _ADJUSTJP 7

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  QWERTYJP,
  LOWERJP,
  RAISEJP,
  ADJUSTJP,
  WN_MINS,
  MCR_US,
  MCR_JP,
};

#define KC_LOWER LOWER
#define KC_RAISE RAISE
#define KC_ADJUST ADJUST
#define KC_QWERTYJP QWERTYJP
#define KC_LOWERJP LOWERJP
#define KC_RAISEJP RAISEJP
#define KC_ADJUSTJP ADJUSTJP

#define KC_XXXXXXX KC_NO
#define KC________ KC_TRNS

#define KC_RST   RESET

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( \
       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,    KC_J,    KC_K,    KC_L, KC_MINS, \
       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, \
             KC_LALT,KC_LCTRL,   LOWER,  KC_SPC, KC_RSFT,   RAISE,KC_RCTRL,  KC_RGUI           \
  ),
  [_LOWER] = LAYOUT( \
      KC_F11,  KC_F12,  KC_TAB,  KC_ESC, KC_CAPS, KC_BSPC, KC_HOME,   KC_UP,  KC_END,  KC_DEL, \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_ZKHK, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_ENT, \
       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC,  KC_DEL, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_RAISE] = LAYOUT( \
     KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_ADJUST] = LAYOUT( \
     KC_PLUS, KC_COLN,  KC_DQT, KC_TILD, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, \
      KC_EQL, KC_SCLN, KC_QUOT,  KC_GRV, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MCR_US,QWERTYJP, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_QWERTYJP] = LAYOUT( \
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, WN_MINS, \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, JP_COMM,  JP_DOT, JP_SLSH, \
              _______, _______, LOWERJP, _______, _______, RAISEJP, _______, _______           \
  ),
  [_LOWERJP] = LAYOUT( \
      KC_F11,  KC_F12,  KC_TAB,  KC_ESC, KC_CAPS, KC_BSPC, KC_HOME,   KC_UP,  KC_END,  KC_DEL, \
       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_ZKHK, KC_LEFT, KC_DOWN,KC_RIGHT,  KC_ENT, \
       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_BSPC,  KC_DEL, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_RAISEJP] = LAYOUT( \
     JP_EXLM,   JP_AT, JP_HASH,  JP_DLR, JP_PERC, JP_CIRC, JP_AMPR, JP_ASTR, JP_LPRN, JP_RPRN, \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  ),
  [_ADJUSTJP] = LAYOUT( \
     JP_PLUS, JP_COLN,  JP_DQT, JP_TILD, XXXXXXX, XXXXXXX, XXXXXXX, JP_LCBR, JP_RCBR, JP_PIPE, \
      JP_EQL, JP_SCLN, JP_QUOT,  JP_GRV, XXXXXXX, XXXXXXX, XXXXXXX, JP_LBRC, JP_RBRC,  JP_YEN, \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  MCR_JP,  QWERTY, \
              _______, _______, _______, _______, _______, _______, _______, _______           \
  )
};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  static bool shift = false;

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

    case QWERTYJP:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTYJP);
      }
      return false;
      break;

    case LOWERJP:
      if (record->event.pressed) {
        layer_on(_LOWERJP);
        update_tri_layer(_LOWERJP, _RAISEJP, _ADJUSTJP);
      } else {
        layer_off(_LOWERJP);
        update_tri_layer(_LOWERJP, _RAISEJP, _ADJUSTJP);
      }
      return false;
      break;

    case RAISEJP:
      if (record->event.pressed) {
        layer_on(_RAISEJP);
        update_tri_layer(_LOWERJP, _RAISEJP, _ADJUSTJP);
      } else {
        layer_off(_RAISEJP);
        update_tri_layer(_LOWERJP, _RAISEJP, _ADJUSTJP);
      }
      return false;
      break;

    case ADJUSTJP:
      if (record->event.pressed) {
        layer_on(_ADJUSTJP);
      } else {
        layer_off(_ADJUSTJP);
      }
      return false;
      break;

    case WN_MINS:
      if (record->event.pressed) {
        shift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        if (shift) {
          register_code(JP_BSLS);
          unregister_code(JP_BSLS);
        } else {
          register_code(JP_MINS);
          unregister_code(JP_MINS);
        }
      }
      return false;
      break;

    case MCR_US:
      if (record->event.pressed) {
        SEND_STRING("US");
      }
      return false;
      break;

    case MCR_JP:
      if (record->event.pressed) {
        SEND_STRING("JP");
      }
      return false;
      break;
    }

  return true;
}

