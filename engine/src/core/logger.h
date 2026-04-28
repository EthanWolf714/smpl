#pragma once

#include "defines.h"
#include "SDL3/SDL.h"
#include <SDL3/SDL_oldnames.h>

class logger{
    public:
        b8 init_logger();

        void shutdown_logger();

        FAPI static void log_output(SDL_LogCategory category, SDL_LogPriority priority, const char* message, ...);
};

//define, fatal, warn, info, trace debug

#define FFATAL(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_CRITICAL,message, ##__VA_ARGS__)
#ifndef FERROR

#define FERROR(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,message, ##__VA_ARGS__)
#endif


#define FWARN(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_WARN,message, ##__VA_ARGS__)

#define FINFO(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,message, ##__VA_ARGS__)

#define FDEBUG(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_DEBUG,message, ##__VA_ARGS__)

#define FTRACE(message,...) logger::log_output(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_TRACE,message, ##__VA_ARGS__)