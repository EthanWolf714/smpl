#include "logger.h"



b8 logger::init_logger(){
    //TODO: remove for relases build
    SDL_SetLogPriorities(SDL_LOG_PRIORITY_TRACE);
    return TRUE;
}

void logger::shutdown_logger(){

}

void logger::log_output(SDL_LogCategory category, SDL_LogPriority priority, const char* message, ...){
    
    va_list args;
    va_start(args,message);
    //LOGGER priority level low-high
    //Trace, Debug, info, warn, error, ciritcal
    switch (priority)
    {
    case SDL_LOG_PRIORITY_INFO : 
        SDL_SetLogPriorityPrefix(SDL_LOG_PRIORITY_INFO, "INFO: ");
        break;
    case SDL_LOG_PRIORITY_DEBUG : 
        SDL_SetLogPriorityPrefix(SDL_LOG_PRIORITY_DEBUG, "DEBUG: ");
        break;
    case SDL_LOG_PRIORITY_CRITICAL : 
        SDL_SetLogPriorityPrefix(SDL_LOG_PRIORITY_CRITICAL, "CRITICAL: ");
        break;
    case SDL_LOG_PRIORITY_ERROR : 
        SDL_SetLogPriorityPrefix(SDL_LOG_PRIORITY_ERROR, "ERROR: ");
        break;
    default:
        break;
    }
    SDL_LogMessageV(category, priority, message,args);
    va_end(args);
}