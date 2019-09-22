#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define EISU LALT(KC_GRV)

// abekoh
#define CTAB LCTL(KC_TAB)
#define CSTAB LCTL(LSFT(KC_TAB))
#define CTLB LCTL(KC_B)
#define CMDPLUS LCMD(KC_PLUS)
#define CMDMINS LCMD(KC_MINS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  Esc |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   [  |                    |   ]  |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  Tab |                    |   '  |   N  |   M  |   ,  |   .  |   /  |  '   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Raise|CMD(M)|CMD(P)| LAlt |||||||| LCMD | Lower| Space|||||||| Space| Raise| RCMD |||||||| RAlt |  UP  |  Del | Lower|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_MINS,                        KC_EQL , KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LBRC,                        KC_RBRC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,                         KC_QUOT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
    RAISE,   CMDMINS, CMDPLUS, KC_LALT,          KC_LGUI, LOWER,   LCTL_T(KC_SPC),C_S_T(KC_SPC), RAISE,   KC_RGUI,          KC_RALT, KC_UP,   KC_DEL,  LOWER    \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |   `  |   1  |   2  |   3  |   4  |   5  |   -  |                    |   =  |   6  |   7  |   8  |   9  |   0  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  | Left | Down |   Up | Right|   [  |                    |   ]  |   -  |   4  |   5  |   6  |   +  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |  C-B | C-Tab|                    |   "  |   *  |   1  |   2  |   3  |   /  |  "   |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Raise| Left |   0  | LAlt |||||||| LCMD | Lower| Space|||||||| Space| Raise| RCMD ||||||||   0  |   .  | RIGHT| Lower|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_MINS,                        KC_EQL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
    KC_LCTL, KC_A,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LBRC,                        KC_RBRC, KC_MINS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    CTLB,    CTAB,                           KC_DQT,  KC_ASTR, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_DQT, \
    RAISE,   KC_LEFT, KC_0,    KC_LALT,          KC_LGUI, LOWER,   LCTL_T(KC_SPC),C_S_T(KC_SPC), RAISE,   KC_RGUI,          KC_0,    KC_DOT, KC_RGHT,   LOWER    \
  ),

  /* Raise
  * ,----------------------------------------------------------------------------------------------------------------------.
  * |   ~  |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
  * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
  * | Ctrl |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |  }   | Left | Down |  Up  | Right|  ;   | Enter|
  * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
  * | Shift|  F6  |  F7  |  F8  |  F9  |  F10 |CS-TAB|                    |  '   |   N  |   M  |   <  |   >  |   ?  |  '   |
  * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
  * | Raise|  F11 |  F12 | LAlt |||||||| LCMD | Lower| Space|||||||| Space| Raise| RCMD |||||||| RAlt |  UP  | RIGHT| Lower|
  * ,----------------------------------------------------------------------------------------------------------------------.
  */
  [_RAISE] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_UNDS,                        KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
    KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  CSTAB,                          KC_QUOT, KC_N,    KC_M,    KC_LT,   KC_GT,   KC_QUES, KC_QUOT, \
    RAISE,   KC_F11,  KC_F12,  KC_LALT,          KC_LGUI, LOWER,   LCTL_T(KC_SPC),C_S_T(KC_SPC), RAISE,   KC_RGUI,          KC_RALT, KC_UP, KC_RGHT,   LOWER   \
    ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |PlaPau| Power|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      | BrDwn| BrUp |      |      |                    |      |PreTra|VolDwn| VolUp|NxtTra|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      | Mute |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, KC_MEDIA_PLAY_PAUSE, KC_POWER, \
    _______, _______, _______, KC_BRMD, KC_BRMU, _______, _______,                       _______, KC_MEDIA_REWIND, KC__VOLDOWN, KC__VOLUP, KC_MEDIA_FAST_FORWARD, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,                       _______, _______, KC__MUTE, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
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
