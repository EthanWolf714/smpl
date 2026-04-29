#pragma once
#include "defines.h"
#include "SDL3/SDL.h"

typedef enum events{
    EVENT_QUIT,

    //keyboard
    EVENT_KEY_DOWN,
    EVENT_KEY_UP,

    //mouse
    EVENT_MOUSE_BUTTON_DOWN,
    EVENT_MOUSE_BUTTON_UP,
    EVENT_MOUSE_MOVED,
    EVENT_MOUSE_WHEEL,

    EVENT_COUNT
    
    
}events;


class event_system{

    public:
        b8 event_init();
        void event_shutdown();
        FAPI void fire(events event_id, void* data1 = nullptr, void* data2 = nullptr);
        b8 is_custom_event(SDL_Event& e, events event_id);
    private:
        u32 base_event = 0;
        b8 initialized;

};

extern event_system event_syst;


