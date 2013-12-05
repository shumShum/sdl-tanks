#ifndef __SDL_game__StateManager__
#define __SDL_game__StateManager__

#include <iostream>
#include <SDL2/SDL.h>

#include "State.h"

enum {
    STATE_STARTUP,
    STATE_PLAYING
};

class StateManager
{
private:
    static State* current_state;

public:
    StateManager();
    
public:
    static void game_loop(SDL_Renderer* ren);
    static void on_event(SDL_Event* event);
    static void on_loop();
    static void render(SDL_Renderer* ren);
    
public:
    static void set_current_state(int state_id);
    static State* get_current_state();
};

#endif
