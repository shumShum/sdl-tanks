#ifndef __SDL_game__StartupState__
#define __SDL_game__StartupState__

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "Game.h"
#include "State.h"

class StartupState: public State
{
private:
    static StartupState instance;
    
public:
    StartupState();
    
public:
    void activate();
    void deactivate();
    
    void on_event(SDL_Event* event);
    void on_loop();
    void render(SDL_Renderer* ren);
    
    static StartupState* get_instance();
};

#endif