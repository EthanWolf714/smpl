REM Build script for engine
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get list opf all cpp files
SET cppFilenames=
FOR /R %%f in (*.cpp) do (
    SET cppFilenames=!cppFilenames! %%f
)

SET assembly=engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror -std=c++17 -fms-runtime-lib=dll --target=x86_64-pc-windows-msvc
SET SDL_PATH=C:\SDL\SDL3-3.4.4
SET includeFlags=-Isrc -I%SDL_PATH%/include
SET linkerFlags=-luser32 -L%SDL_PATH%/lib/x64 -lSDL3
SET defines=-D_DEBUG -DFEXPORT -D_CRT_SECURE_NO_WARNINGS -D_ITERATOR_DEBUG_LEVEL=0 -DSDL_MAIN_HANDLED

ECHO "Copying SDL3 DLL..."
xcopy /y %SDL_PATH%\lib\x64\SDL3.dll ..\bin\

ECHO "Building %assembly%%..."
clang++ %cppFilenames% %compilerFlags% -o ../bin/%assembly%.dll %defines% %includeFlags% %linkerFlags%

