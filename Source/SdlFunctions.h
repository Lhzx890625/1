#pragma once

#include <cstdint>

#include "Platform/DynamicLibrary.h"
#include "Utils/SafeAddress.h"

struct SdlFunctions {
    SdlFunctions(DynamicLibrary libSDL)
        : pollEvent{ libSDL.getFunctionAddress("SDL_PollEvent").add(2).abs().get() },
          swapWindow{ libSDL.getFunctionAddress("SDL_GL_SwapWindow").add(2).abs().get() }
    {
    }

    std::uintptr_t pollEvent = 0;
    std::uintptr_t swapWindow = 0;
};
