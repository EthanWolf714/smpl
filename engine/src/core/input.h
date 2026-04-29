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
        void input_update();
        void process_input(SDL_Event& e);
        FAPI b8 is_key_pressed(SDL_Scancode key);
        FAPI b8 is_key_held(SDL_Scancode key);
        FAPI b8 is_key_released(SDL_Scancode key);
        

        FAPI b8 is_mouse_pressed(u8 button);
        FAPI b8 is_mouse_held(u8 button);
        FAPI b8 is_mouse_released(u8 button);

        FAPI void get_mouse_position(f32& x, f32& y);
        FAPI void get_mouse_delta(f32& dx, f32& dy);
        FAPI f32 get_scroll_delta();

    
    private:
        //mouse and key states
        b8 key_current[SDL_SCANCODE_COUNT]{};
        b8 key_previous[SDL_SCANCODE_COUNT]{};
        
        b8 mouse_current[6]{};
        b8 mouse_previous[6]{};

        f32 mouse_x{};
        f32 mouse_y{};
        f32 mouse_dx{};
        f32 mouse_dy{};
        f32 mouse_z_delta{};
        b8 initialized;
};


extern input input_syst;