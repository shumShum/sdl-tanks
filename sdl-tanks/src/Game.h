#ifndef _CAPP_H_
#define _CAPP_H_

#include <iostream>
#include <SDL2/SDL.h>

#include "StateManager.h"

class Game
{
private:
    static bool running;
    static StateManager* state_manager;
    SDL_Window* screen;
    SDL_Renderer* ren;
    
public:
    Game();
    int execute();
    
public:
    bool init();
    void cleanup();
    
    static void set_current_state(State* state);
    static void quit_game();
};

#endif