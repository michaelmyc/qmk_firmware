#include QMK_KEYBOARD_H
#include "version.h"
#include <print.h>

#define BASE 0 // default layer
#define L1 1 // navigation/fn layer

bool NUMLOCK_ON;

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  CSTM_RESET,
  CST,
  TEST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   =  |  Bksp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   L1   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   `  |           | PrSc |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |      | LGUI |  Alt |  Esc |                                       |  Esc |  Del |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Vol- | Vol+ |       | Prev | Next |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      | Mute |       | Play |      |      |
 *                                 | LGUI | Ctrl |------|       |------| Entr |Space |
 *                                 |      |      | Space|       | Entr |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,
        MO(L1),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_GRV,
        KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT, KC_ESC,
                                                     KC_VOLD, KC_VOLU,
                                                              KC_MUTE,
                                            KC_LGUI, KC_LCTL, KC_SPC,
        // right hand
        KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
                 KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_PSCR, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                          KC_ESC,  KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX,
        KC_MPRV, KC_MNXT,
        KC_MPLY,
        KC_ENT,  KC_ENT,  KC_SPC
    ),
/* Keymap 1: Navigation Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    `    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   Del  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      |  Up  |      |      |      |           |      |      |      | PgUp | PgDn |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right|      |------|           |------| Left | Down |  Up  | Right|      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      | Home |  End |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |         |      |      |      |      |                                       |      |      |      |      | RESET|
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------+------+------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// L1 fn layer
[L1] = LAYOUT_ergodox(
        // left hand
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                     KC_TRNS, KC_TRNS,
                                                              KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,
        // right hand
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_HOME, KC_END,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, CSTM_RESET,
        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case CSTM_RESET:
      if (record->event.pressed) {
        ergodox_blink_all_leds();
        reset_keyboard();
      }
      return false;
      break;
    case CST:
      if (record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LSFT);
        register_code(KC_TAB);
        unregister_code(KC_LCTL);
        unregister_code(KC_LSFT);
        unregister_code(KC_TAB);
      }
      return false;
      break;
    case TEST:
      if (record->event.pressed) {
        print("TEST");
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  NUMLOCK_ON = host_keyboard_leds() & (1<<USB_LED_NUM_LOCK);
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }
  if (!NUMLOCK_ON) {
    // tap_code(KC_NUMLOCK);
    // NUMLOCK_ON = !NUMLOCK_ON;
  } else {
    ergodox_right_led_3_on();
  }
};
