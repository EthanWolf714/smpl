#include "application.h"

using namespace engine;
   

logger syst_logger;
event_system event_syst;


application::application()
{
    if(initilized){
       FERROR("application_create called more than once");
    }
    
    width = 640;
    height = 480;
    if(SDL_Init(SDL_INIT_VIDEO) == FALSE){
        SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
    }else{
     gWindow = SDL_CreateWindow("My application", width, height, 0);   
    }

    syst_logger.init_logger();
    event_syst.event_init();

      //log test
    FFATAL("A TEST MESSAGE: %f", 3.14);
    FERROR("A TEST MESSAGE: %f", 3.14);
    FWARN("A TEST MESSAGE: %f", 3.14);
    FINFO("A TEST MESSAGE: %f", 3.14);
    FDEBUG("A TEST MESSAGE: %f", 3.14);
    FTRACE("A TEST MESSAGE: %f", 3.14);

    running = TRUE;
    initilized = TRUE;
}

application::~application()
{
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    //Quit SDL subsystems
    SDL_Quit();
}

FAPI b8 application::application_run()
{
    while (is_running())
    {

        SDL_Event e;
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_EVENT_QUIT){
                running = FALSE;
            }
        }
        
    }
    
    syst_logger.shutdown_logger();
    event_syst.event_shutdown();

    return TRUE;

    
}

FAPI SDL_Window* application::get_window()
{
    return gWindow;
}

 FAPI b8 application::is_initialized()
{
    return initilized;
}

FAPI b8 application::is_running()
{
    return running;
}




