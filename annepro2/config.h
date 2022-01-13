#pragma once

#define UCIS_MAX_CODE_POINTS 12

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2

#undef TAPPING_TERM
#define TAPPING_TERM 270
#define RETRO_TAPPING

// Some programs will not register TAP keys properly if they are triggered
// too quickly.
//#define TAP_CODE_DELAY 70