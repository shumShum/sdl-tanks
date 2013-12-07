#ifndef __SDL_game__State__
#define __SDL_game__State__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Event.h"
#include "StateManager.h"
#include "ImageStorage.h"

class State: public Event {
public:
    virtual void activate() = 0;
    virtual void deactivate() = 0;
    
    virtual void on_event(SDL_Event* event) = 0;
    virtual void on_loop() = 0;
    virtual void render(SDL_Renderer* ren) = 0;
};

#endif
