#ifndef __SDL_game__StartupState__
#define __SDL_game__StartupState__

#include "State.h"

class StartupState: public State {
private:
    static StartupState instance;
    
public:
    StartupState();
    
public:
    void activate();
    void deactivate();
    
    void on_event(SDL_Event* event);
    void on_key_down(SDL_Keycode sym, Uint16 mod);
    
    void on_loop();
    void render(SDL_Renderer* ren);
    
    static StartupState* get_instance();
    
private:
    void draw_background(SDL_Renderer* ren);
    void draw_labels(SDL_Renderer* ren);
};

#endif