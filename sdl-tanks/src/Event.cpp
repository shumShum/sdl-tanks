#include "Event.h"
#include "Game.h"

Event::Event() {
}

Event::~Event() {
}

void Event::on_event(SDL_Event* event) {
    switch(event->type) {
        case SDL_KEYDOWN: {
            on_key_down(event->key.keysym.sym, event->key.keysym.mod);
            break;
        }
            
        case SDL_KEYUP: {
            on_key_up(event->key.keysym.sym, event->key.keysym.mod);
            break;
        }
            
        case SDL_MOUSEMOTION: {
            on_mouse_move(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel, (event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }
            
        case SDL_MOUSEBUTTONDOWN: {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                    on_l_button_down(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    on_r_button_down(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    on_m_button_down(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }
            
        case SDL_MOUSEBUTTONUP:    {
            switch(event->button.button) {
                case SDL_BUTTON_LEFT: {
                    on_l_button_up(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    on_r_button_up(event->button.x, event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    on_m_button_up(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }
            
        case SDL_JOYAXISMOTION: {
            on_joy_axis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
            break;
        }
            
        case SDL_JOYBALLMOTION: {
            on_joy_ball(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
            break;
        }
            
        case SDL_JOYHATMOTION: {
            on_joy_hat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;
        }
        case SDL_JOYBUTTONDOWN: {
            on_joy_button_down(event->jbutton.which, event->jbutton.button);
            break;
        }
            
        case SDL_JOYBUTTONUP: {
            on_joy_button_up(event->jbutton.which, event->jbutton.button);
            break;
        }
            
        case SDL_QUIT: {
            on_exit();
            break;
        }
            
        case SDL_SYSWMEVENT: {
            break;
        }
            
        case SDL_WINDOWEVENT: {
            switch (event->window.event) {
                case SDL_WINDOWEVENT_EXPOSED:
                    on_expose();
                    break;
                    
                case SDL_WINDOWEVENT_RESIZED:
                    on_resize(event->window.data1, event->window.data2);
                    break;
                    
                default:
                    break;
            }
            break;
        }
            
        default: {
            on_user(event->user.type, event->user.code, event->user.data1, event->user.data2);
            break;
        }
    }
}

void Event::on_key_down(SDL_Keycode sym, Uint16 mod) {
}

void Event::on_key_up(SDL_Keycode sym, Uint16 mod) {
}

void Event::on_mouse_move(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
}

void Event::on_mouse_wheel(bool Up, bool Down) {
}

void Event::on_l_button_down(int mX, int mY) {
}

void Event::on_l_button_up(int mX, int mY) {
}

void Event::on_r_button_down(int mX, int mY) {
}

void Event::on_r_button_up(int mX, int mY) {
}

void Event::on_m_button_down(int mX, int mY) {
}

void Event::on_m_button_up(int mX, int mY) {
}

void Event::on_joy_axis(Uint8 which,Uint8 axis,Sint16 value) {
}

void Event::on_joy_button_down(Uint8 which,Uint8 button) {
}

void Event::on_joy_button_up(Uint8 which,Uint8 button) {
}

void Event::on_joy_hat(Uint8 which,Uint8 hat,Uint8 value) {
}

void Event::on_joy_ball(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
}

void Event::on_minimize() {
}

void Event::on_restore() {
}

void Event::on_resize(int w, int h) {
}

void Event::on_expose() {
}

void Event::on_exit() {
    Game::quit_game();
}

void Event::on_user(Uint8 type, int code, void* data1, void* data2) {
}