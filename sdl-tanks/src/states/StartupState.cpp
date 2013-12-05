#include "StartupState.h"
#include "StateManager.h"

StartupState::StartupState() {
}

StartupState StartupState::instance;

void StartupState::activate() {
}

void StartupState::deactivate() {
}

void StartupState::on_event(SDL_Event* event) {
    Event::on_event(event);
}
void StartupState::on_key_down(SDL_Keycode sym, Uint16 mod) {
    switch (sym) {
        case SDLK_ESCAPE:
            on_exit();
            break;
        case SDLK_RETURN:
        case SDLK_s:
            StateManager::set_current_state(STATE_PLAYING);
            break;
            
        default:
            break;
    }
}

void StartupState::on_loop() {
}

void StartupState::render(SDL_Renderer* ren) {
    SDL_Texture *background =  IMG_LoadTexture(ren, "bg_intro.jpg");
    SDL_Rect background_RECT;
    background_RECT.x = 0;
    background_RECT.y = 0;
    background_RECT.w = 640;
    background_RECT.h = 480;
    
    SDL_RenderClear(ren);
    SDL_RenderCopy(ren, background, NULL, &background_RECT);
    SDL_RenderPresent(ren);
}

StartupState* StartupState::get_instance() {
    return &instance;
}
