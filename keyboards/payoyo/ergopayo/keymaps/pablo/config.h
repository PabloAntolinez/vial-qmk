/* keyboard uid */
#define VIAL_KEYBOARD_UID {0xDC, 0x6D, 0x9C, 0x42, 0x53, 0x48, 0x75, 0x0F}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 4 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 5 }

#define WS2812_DI_PIN GP23
#define RGBLIGHT_LED_COUNT 2
#define RGBLED_SPLIT { 1, 1 }

#define RGBLIGHT_LAYERS

// #define RGBLIGHT_LAYERS_RETAIN_VAL


/* default layer count */
#define DYNAMIC_KEYMAP_LAYER_COUNT 10

#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// //------------------------------------------
// // 'old' RGB Lightning definitions, used when RGBLIGHT_ENABLE = yes in rules.mk
// //------------------------------------------
// #ifdef RGBLIGHT_ENABLE
// #define RGBLIGHT_HUE_STEP 8
// #define RGBLIGHT_SAT_STEP 8
// #define RGBLIGHT_VAL_STEP 8
// #define RGBLIGHT_SLEEP       /* the RGB lighting will be switched off when the host goes to sleep */
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// // #    define RGBLIGHT_EFFECT_SNAKE
// // #    define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// // #    define RGBLIGHT_EFFECT_STATIC_GRADIENT
// // #    define RGBLIGHT_EFFECT_RGB_TEST
// // #    define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
// #endif
// //------------------------------------------
