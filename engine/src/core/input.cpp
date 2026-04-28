#include "input.h"

b8 input::proccess_input(){
    //The event data
        SDL_Event e;
        SDL_zero( e );
        
        while(quit == FALSE){
            while(SDL_PollEvent(&e) == TRUE){
                if(e.type == SDL_EVENT_QUIT) {
                    quit = TRUE;
                }
            }
        }
    return TRUE;
}