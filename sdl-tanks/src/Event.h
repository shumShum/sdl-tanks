#ifndef _CEVENT_H_
#define _CEVENT_H_

#include <SDL2/SDL.h>

class Event {
public:
    Event();
    virtual ~Event();
    virtual void on_event(SDL_Event* Event);
    
    virtual void on_key_down(SDL_Keycode sym, Uint16 mod);
    virtual void on_key_up(SDL_Keycode sym, Uint16 mod);
    
    virtual void on_mouse_move(int mX, int mY, int relX, int relY, bool Left, bool Right, bool Middle);
    virtual void on_mouse_wheel(bool Up, bool Down);
    
    virtual void on_l_button_down(int mX, int mY);
    virtual void on_l_button_up(int mX, int mY);
    virtual void on_r_button_down(int mX, int mY);
    virtual void on_r_button_up(int mX, int mY);
    virtual void on_m_button_down(int mX, int mY);
    virtual void on_m_button_up(int mX, int mY);
    
    virtual void on_joy_axis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void on_joy_button_down(Uint8 which, Uint8 button);
    virtual void on_joy_button_up(Uint8 which, Uint8 button);
    virtual void on_joy_hat(Uint8 which, Uint8 hat, Uint8 value);
    virtual void on_joy_ball(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
    
    virtual void on_minimize();
    virtual void on_restore();
    virtual void on_resize(int w,int h);
    virtual void on_expose();
    virtual void on_exit();
    virtual void on_user(Uint8 type, int code, void* data1, void* data2);
};

#endif