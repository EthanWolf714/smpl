#include "input.h"



b8 input::input_init(){
    initialized = TRUE;
}

void input::input_shutdown(){
    memset(key_current, 0, sizeof(key_current));
    memset(key_previous, 0, sizeof(key_previous));
    memset(mouse_current, 0, sizeof(mouse_current));
    memset(mouse_previous, 0, sizeof(mouse_previous));
    mouse_x = 0.0f;
    mouse_y = 0.0f;
    mouse_dx = 0.0f;
    mouse_dy = 0.0f;
    mouse_z_delta = 0.0f;
    initialized = FALSE;
}



void input::input_update(){
    if(!initialized){
        return;
    }
    // copy current into previous
    memcpy(key_previous, key_current, sizeof(key_current));
    memcpy(mouse_previous, mouse_current, sizeof(mouse_current));

     // reset per frame data
    mouse_dx = 0.0f;
    mouse_dy = 0.0f;
    mouse_z_delta = 0.0f;


}

void input::process_input(SDL_Event& e){
    switch(e.type){
        case SDL_EVENT_KEY_DOWN:
            key_current[e.key.scancode] = TRUE;
            event_syst.fire(EVENT_KEY_DOWN, (void*)(u64)e.key.scancode);
            break;
        case SDL_EVENT_KEY_UP:
            key_current[e.key.scancode] = FALSE;
            event_syst.fire(EVENT_KEY_UP, (void*)(u64)e.key.scancode);
            break;
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            mouse_current[e.button.button] = TRUE;
            event_syst.fire(EVENT_MOUSE_BUTTON_DOWN, (void*)(u64)e.button.button);
            break;
        case SDL_EVENT_MOUSE_BUTTON_UP:
            mouse_current[e.button.button] = FALSE;
            event_syst.fire(EVENT_KEY_UP, (void*)(void*)(u64)e.button.button);
            break;
        case SDL_EVENT_MOUSE_MOTION:
            mouse_x = e.motion.x;
            mouse_y = e.motion.y;
            mouse_dx = e.motion.xrel;
            mouse_dy = e.motion.yrel;
            event_syst.fire(EVENT_MOUSE_MOVED);
            break;
        case SDL_EVENT_MOUSE_WHEEL:
            mouse_z_delta = e.wheel.y;
            event_syst.fire(EVENT_MOUSE_WHEEL);
            break;
    }
}


b8 input::is_key_pressed(SDL_Scancode key){
    if(!initialized){
        return FALSE;
    }
    return key_current[key] && !key_previous[key];
}
b8 input::is_key_held(SDL_Scancode key){
    if(!initialized){
        return FALSE;
    }
    return key_current[key] && key_previous[key];
}
b8 input::is_key_released(SDL_Scancode key){
    if(!initialized){
        return FALSE;
    }
    return !key_current[key] && key_previous[key];
}   
b8 input::is_mouse_pressed(u8 button){
    if(!initialized){
        return false;
    }
    return mouse_current[button] && !mouse_previous[button];
} 
b8 input::is_mouse_held(u8 button){
    if(!initialized){
        return false;
    }
    return mouse_current[button] && !mouse_previous[button];
}
b8 input::is_mouse_released(u8 button){
    if(!initialized){
        return false;
    }
    return !mouse_current[button] && mouse_previous[button];
}      
void input::get_mouse_position(f32& x, f32& y){
    x = mouse_x;
    y = mouse_y;
}
void input::get_mouse_delta(f32& dx, f32& dy){
    dx = mouse_dx;
    dy = mouse_dy;
}
f32 input::get_scroll_delta(){
    return mouse_z_delta;
}