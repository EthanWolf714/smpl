#pragma once
#include "defines.h"
#include "SDL3/SDL.h"
#include "event.h"


enum key_state{
    OnPress,
    OnRelease,
    Pressed,
    Released,
};

class input{

    public:
        b8 input_init();
        void input_shutdown();
        void input_update(f64 delta_time);
        FAPI b8 input_is_key_down(SDL_Scancode key);
        FAPI b8 input_is_key_up(SDL_Scancode key);
    
    private:
        //mouse and key states
        b8 key_current;
        b8 key_previous;
        
        b8 mouse_current;
        b8 mouse_previous;

        f32 mouse_x;
        f32 mouse_y;
        f32 mouse_dx;
        f32 mouse_dy;
        f32 mouse_z_delta;
};


