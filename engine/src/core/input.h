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

        b8 proccess_input();
    private:
    //The quit flag
        bool quit{ false };
};


