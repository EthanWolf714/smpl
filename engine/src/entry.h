#pragma once
#define SDL_MAIN_HANDLED 1
#include "core/application.h"
#include "core/logger.h"




engine::application app;



int main(int argc, char* args[]){
   int exitCode{0};
       

        

        
        
    if(!app.is_initialized()){
        FINFO("Application failed to create!\n");
        return 1;
    }

    
    app.application_run(); 

    return exitCode;
}


