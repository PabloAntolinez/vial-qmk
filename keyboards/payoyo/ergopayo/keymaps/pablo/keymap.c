// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAMING,
    _COLEMAK
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |                                   |   Y  |   U  |   I  |   O  |   P  |  -        |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  LShift |   A  |   S  |   D  |   F  |   G  |                                   |   H  |   J  |   K  |   L  |   ;  |  '        |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  LCTRL  |   Z  |   X  |   C  |   V  |   B  |                                   |   N  |   M  |   ,  |  .   |   /  |   RALT    |
 * `------------------------------------------------------------/    \--------------|----------------------------------------------'
 *                                       |LALT  |Space | LOWER /      \ RAISE| Enter|BackSP| 
 *                                       `--------------------'        '-------------------'
 */
 [_QWERTY] = LAYOUT_split_3x6_3(
    KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
    KC_LSFT, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,                       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                   KC_LALT,  KC_ENT,   LOWER,    RAISE,  KC_SPC,   KC_BSPC
),
/* LOWER
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |         |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |    `    |   !  |   @  |   #  |   $  |   %  |                                   |   ^  |   &  |   *  |   (  |   )  |  ~        |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |         |      |      |      |      |      |                                   |      |   _  |   +  |   {  |   }  |  \        |
 * `--------------------------------------------|---------------/    \--------------|----------------------------------------------'
 *                                      | LALT  |Space | LOWER /      \ RAISE| Enter|BackSP| 
 *                                      `---------------------'        '-------------------'
 */
[_LOWER] = LAYOUT_split_3x6_3(
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
    _______, _______, _______, _______, _______, _______,                   XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
                                        _______, _______, _______, _______, _______, _______
),
/* RAISE
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * |   `     |   1  |   2  |   3  |   4  |   5  |                                   |   6  |   7  |   8  |   9  |   0  |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  F1     |  F2  |  F3  |   F4 |  F5  |  F6  |                                   | Left | Down |  Up  |Right |   ;  |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * |  F7     |  F8  |  F9  | F10  | F11  | F12  |                                   |   +  |   -  |   =  |  [  |   ]   |   \       |
 * `--------------------------------------------|---------------/    \--------------|----------------------------------------------'
 *                                       |LALT  |Space | LOWER /      \ RAISE| Enter|BackSP|
 *                                       `--------------------'        '-------------------'
 */
 [_RAISE] = LAYOUT_split_3x6_3(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                 KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
                                       _______, _______, _______, _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * | RGB ON  | HUE+ | SAT+ | VAL+ |      |      |                                   | PREV | PLAY | NEXT |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | MODE    | HUE- | SAT- | VAL- |      |      |---------------.   ,---------------| VOL+ | MUTE | VOL- |      |      |           |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * | QK_BOOT |      |      |      |      |      |------|--------|   |-------|-------|      |      |      |      |      |  QK_BOOT  |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                                       |LALT  |Space | LOWER /      \ RAISE| Enter|BackSP|
 *                                       `--------------------'        '-------------------'
 */
[_ADJUST] = LAYOUT_split_3x6_3(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                        _______, _______, _______,   _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * | RGB ON  | HUE+ | SAT+ | VAL+ |      |      |                                   | PREV | PLAY | NEXT |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | MODE    | HUE- | SAT- | VAL- |      |      |---------------.   ,---------------| VOL+ | MUTE | VOL- |      |      |           |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * | QK_BOOT |      |      |      |      |      |------|--------|   |-------|-------|      |      |      |      |      |  QK_BOOT  |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                                       |LALT  |Space | LOWER /      \ RAISE| Enter|BackSP|
 *                                       `--------------------'        '-------------------'
 */
[_GAMING] = LAYOUT_split_3x6_3(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                        _______, _______, _______,   _______, _______, _______
),
/* ADJUST (Press LOWER and RAISE together)
 * ,--------------------------------------------.                                   ,----------------------------------------------.
 * | RGB ON  | HUE+ | SAT+ | VAL+ |      |      |                                   | PREV | PLAY | NEXT |      |      |           |
 * |---------+------+------+------+------+------|                                   |------+------+------+------+------+-----------|
 * | MODE    | HUE- | SAT- | VAL- |      |      |---------------.   ,---------------| VOL+ | MUTE | VOL- |      |      |           |
 * |---------+------+------+------+------+------|      |        |   |       |       |------+------+------+------+------+-----------|
 * | QK_BOOT |      |      |      |      |      |------|--------|   |-------|-------|      |      |      |      |      |  QK_BOOT  |
 * `--------------------------------------------|               /    \              |----------------------------------------------'
 *                                       |LALT  |Space | LOWER /      \ RAISE| Enter|BackSP|
 *                                       `--------------------'        '-------------------'
 */
[_COLEMAK] = LAYOUT_split_3x6_3(
    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                     KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,
    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
                                        _______, _______, _______,   _______, _______, _______
)
};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
//     return state;
// }

const rgblight_segment_t PROGMEM layer0_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 0, 0, 0}
);
const rgblight_segment_t PROGMEM layer1_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 255, 255, 75}
);
const rgblight_segment_t PROGMEM layer2_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 0, 255, 0}
);
const rgblight_segment_t PROGMEM layer3_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 0, 0, 255}
);
const rgblight_segment_t PROGMEM layer4_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 255, 0, 0}
);
const rgblight_segment_t PROGMEM layer5_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 255, 255, 255}
);
const rgblight_segment_t PROGMEM layer6_colors[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, 106, 255, 75}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer0_colors,
    layer1_colors,
    layer2_colors,
    layer3_colors,
    layer4_colors,
    layer5_colors,
    layer6_colors
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    return state;
}