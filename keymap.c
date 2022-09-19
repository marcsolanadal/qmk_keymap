#include QMK_KEYBOARD_H

enum ferris_layers {
    _COLEMAK_DH,
    _EXTEND,
    _SYMBOLS,
    _FUNCTION,
};

enum {
    TD_CBR,
    TD_PRN,
    TD_BRC,
};
 
enum combos {
    CMB_L3
};
 
const uint16_t PROGMEM combo_l3[] = {LSFT_T(KC_SPC), RSFT_T(KC_SPC), COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    [CMB_L3] = COMBO(combo_l3, MO(_FUNCTION)),
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

/*
 * [EMPTY] = LAYOUT(
 *     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,
 *     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,
 *     XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX,  XXXXXXX,    XXXXXXX,   XXXXXXX,
 *                                         XXXXXXX,    XXXXXXX,            XXXXXXX,    XXXXXXX
 * ),
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
    /* Colemak-DH
     * .----------------------------------.          .----------------------------------.
     * |  q   |  w   |  f   |  p   |  b   |          |  j   |  l   |  u   |  y   |  '   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  a   |  r   |  s   |  t   |  g   |          |  m   |  n   |  e   |  i   |  o   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  z   |  x   |  c   |  d   |  v   |          |  k   |  h   |  ,   |  .   |  /   |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      | Ext  | Shft |          | Ent  | Sym  |    
     *                      `-------------'          `-------------'
     */
    [_COLEMAK_DH] = LAYOUT(
        KC_Q,      KC_W,    KC_F,    KC_P,    KC_B,            KC_J,    KC_L,  KC_U,    KC_Y,   KC_QUOT,
        KC_A,      KC_R,    KC_S,    KC_T,    KC_G,            KC_M,    KC_N,  KC_E,    KC_I,   KC_O,
        KC_Z,      KC_X,    KC_C,    KC_D,    KC_V,            KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH,
                                     MO(_EXTEND),   LSFT_T(KC_SPC),         RSFT_T(KC_SPC),  MO(_SYMBOLS)
    ),

    /* Extend
     * .----------------------------------.          .----------------------------------.
     * | Esc  |  Up  | Find | Down | Ins  |          | Pgup | Home | End  | Prnt | Caps |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * | Alt  | GUI  | Shft | LCtl | Tab  |          | Left | Down |  Up  | Rght | Del  |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * | Undo | Cut  | Copy | Pste |      |          | Pgdn | Bspc | Shft | App  | Pscr |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      | Ext  |      |          | Ent  | RCtl |    
     *                      `-------------'          `-------------'
     */
    [_EXTEND] = LAYOUT(
        KC_ESC,         DT_UP,          LCTL(KC_F),     DT_DOWN,        KC_INS,            KC_PGUP,  KC_HOME,  KC_END,         DT_PRNT,   CAPSWRD,
        OSM(MOD_LALT),  OSM(MOD_LGUI),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_TAB,            KC_LEFT,  KC_DOWN,  KC_UP,          KC_RGHT,   KC_DEL,
        LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     XXXXXXX,           KC_PGDN,  KC_BSPC,  OSM(MOD_RSFT),  KC_APP,    KC_PSCR,
                                                        XXXXXXX,        XXXXXXX,           KC_ENT,   KC_RCTL
    ),

    /* Symbols
     * .----------------------------------.          .----------------------------------.
     * |  !   |  @   |  #   |  :   |  []  |          |  =   |  7   |  8   |  9   |  +   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  \   |  &   |  {}  |  ()  |  ;   |          |  *   |  4   |  5   |  6   |  -   |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |  ^   |  _   |  %   |  $   |  ~   |          |  0   |  1   |  2   |  3   |  /   |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      |  |   |  `   |          |      | Sym  | 
     *                      `-------------'          `-------------'
     */
    [_SYMBOLS] = LAYOUT(
        KC_EXLM,       KC_AT,    KC_HASH,      KC_COLN,      TD(TD_BRC),     KC_EQL,    KC_7,   KC_8,    KC_9,   KC_PLUS,
        KC_BSLS,       KC_AMPR,  TD(TD_CBR),   TD(TD_PRN),   KC_SCLN,        KC_PAST,   KC_4,   KC_5,    KC_6,   KC_PMNS,
        KC_CIRC,       KC_UNDS,  KC_PERC,      KC_DLR,       KC_TILD,        KC_0,      KC_1,   KC_2,    KC_3,   KC_PSLS,
                                               KC_PIPE,      KC_GRV,         XXXXXXX,   XXXXXXX
    ),

    /* Function
     * .----------------------------------.          .----------------------------------.
     * |      |      |      |      | QK_BOOT |       |  F12 |  F7  |  F8  |  F9  |      |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |      |      |      |      |      |          |  F11 |  F4  |  F5  |  F6  |      |
     * |------+------+------+------+------|          |------+------+------+------+------|
     * |      |      |      |      |      |          |  F10 |  F1  |  F2  |  F3  |      |
     * `--------------------.------+------|          |------+------.--------------------'
     *                      |      |      |          |      |      |    
     *                      `-------------'          `-------------'
     */
    [_FUNCTION] = LAYOUT(
        DT_PRNT,    DT_UP,    DT_DOWN,      XXXXXXX,    QK_BOOT,            KC_F12,    KC_F7,  KC_F8,    KC_F9,   XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            KC_F11,    KC_F4,  KC_F5,    KC_F6,   XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,            KC_F10,    KC_F1,  KC_F2,    KC_F3,   XXXXXXX,
                                            XXXXXXX,    XXXXXXX,            XXXXXXX,   XXXXXXX
    ),

};
