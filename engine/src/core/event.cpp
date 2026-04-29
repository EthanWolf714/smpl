#include "event.h"
event_system event_syst;
//initialized event system
b8 event_system::event_init(){
    if(initialized == TRUE){
        return FALSE;
    }
    //register all events in sdl event queue
    base_event = SDL_RegisterEvents((int)events::EVENT_COUNT);

    initialized = TRUE;
    return TRUE;
}

void event_system::event_shutdown(){
    initialized = false;
}

void event_system::fire(events event_id, void* data1, void* data2)
{
    SDL_Event e;
    SDL_zero(e);
    e.type = base_event + (u32)event_id;
    e.user.data1 = data1;
    e.user.data2 = data2;
    SDL_PushEvent(&e);

}

b8 event_system::is_custom_event(SDL_Event& e, events event_id)
{
    return e.type == base_event + (u32)event_id;
}
