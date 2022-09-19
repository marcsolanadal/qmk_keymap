#pragma once

// Pick good defaults for enabling homerow modifiers
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 180
#define TAP_CODE_DELAY 10 // To fix wayland's not sending shift in time we need to add a small delay on the tap
#define RETRO_TAPPING
#define COMBO_COUNT 1

#define ONESHOT_TAP_TOGGLE 10  /* Tapping this number of times holds the key until tapped once again. */
//#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define LAYER_STATE_8BIT // limit to 8 layers 
