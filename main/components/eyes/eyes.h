/*#pragma once

#include <stdbool.h>
#include "esp_err.h"


typedef enum {
    EYE_OFF = 0,
    EYE_THINKING,
    EYE_CONSTANT,
} eye_emotion_t;

esp_err_t eyes_init(void);

void eyes_set_emotion(eye_emotion_t e);
                    
eye_emotion_t eyes_get_emotion(void);

eye_emotion_t eyes_get_target(void);

bool eyes_is_transitioning(void);
 
void eyes_set_brightness_cap(float cap);

void eyes_set_zero(void);

void eyes_set_emotion(eye_emotion_t e, float fade_s);


#pragma once

#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif*/

#pragma once

#include <stdbool.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif
#define EYE_FADE_DEFAULT   2.5f

#define EYE_FADE_MIN       0.01f

typedef enum {
    EYE_OFF = 0,  
    EYE_THINKING,   
    EYE_CONSTANT,   
} eye_emotion_t;

esp_err_t eyes_init(void);
void eyes_set_emotion(eye_emotion_t e, float fade_s);
void eyes_set_emotion_default(eye_emotion_t e);

/* Drive the eye brightness directly to `level` (0..1), bypassing the emotion
 * state machine. Use this to synchronize the eyes with another animation by
 * calling it every frame. Call eyes_set_emotion() to hand control back to the
 * automatic fade behaviour. */
void eyes_set_level(float level);
void eyes_set_zero(void);
eye_emotion_t eyes_get_emotion(void);
eye_emotion_t eyes_get_target(void);
float eyes_get_fade(void);
bool eyes_is_transitioning(void);
void eyes_set_brightness_cap(float cap);

#ifdef __cplusplus
}
#endif