@ECHO OFF
SetLocal EnableDelayedExpansion

SET cppFilenames=
FOR /R %%f in (*.cpp) do (
    SET cppFilenames=!cppFilenames! %%f
)

SET assembly=testbed
SET compilerFlags=-g
SET SDL_PATH=C:\SDL\SDL3-3.4.4
SET includeFlags=-Isrc -I../engine/src/ -I%SDL_PATH%/include
SET linkerFlags=-L../bin/ -lengine.lib -L%SDL_PATH%/lib/x64 -lSDL3
SET defines=-D_DEBUG -DFIMPORT -D_ITERATOR_DEBUG_LEVEL=0

ECHO "Building %assembly%%..."
clang++ %cppFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%