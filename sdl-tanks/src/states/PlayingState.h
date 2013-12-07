#ifndef __SDL_game__PlayingState__
#define __SDL_game__PlayingState__

#include "State.h"

class PlayingState: public State {
private:
    static PlayingState instance;
    
public:
    PlayingState();
    
public:
    void activate();
    void deactivate();
    
    void on_event(SDL_Event* event);
    void on_key_down(SDL_Keycode sym, Uint16 mod);
    
    void on_loop();
    void render(SDL_Renderer* ren);
    
    static PlayingState* get_instance();
};

#endif