#pragma once 
#include "defines.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "logger.h"
#include "event.h"
#include "input.h"
#include <string.h>


namespace engine
{
    class application
    {
        public:
            FAPI application();
            FAPI ~application();
            FAPI b8 application_run();
            FAPI SDL_Window* get_window();
            FAPI b8 is_initialized();
            FAPI b8 is_running();
           
        private:
            b8 initilized;
            b8 running;
            i16 width;
            i16 height;
            SDL_Window* gWindow {nullptr};
            
     

    };
   
    
}