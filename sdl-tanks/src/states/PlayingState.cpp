#include "PlayingState.h"

PlayingState::PlayingState() {
}

PlayingState PlayingState::instance;

void PlayingState::activate() {
}

void PlayingState::deactivate() {
}

void PlayingState::on_event(SDL_Event* event) {
    Event::on_event(event);
}
void PlayingState::on_key_down(SDL_Keycode sym, Uint16 mod) {
    switch (sym) {
        case SDLK_ESCAPE:
            StateManager::set_current_state(STATE_STARTUP);
            break;
            
        default:
            break;
    }
}

void PlayingState::on_loop() {
}

void PlayingState::render(SDL_Renderer* ren) {
    SDL_Texture *background =  IMG_LoadTexture(ren, "bg.png");
    SDL_Rect background_RECT;
    background_RECT.x = 0;
    background_RECT.y = 0;
    background_RECT.w = 640;
    background_RECT.h = 480;
    
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, background, NULL, &background_RECT);
    SDL_RenderPresent(ren);
}

PlayingState* PlayingState::get_instance() {
    return &instance;
}
