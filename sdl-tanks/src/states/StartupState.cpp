#include "StartupState.h"

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

void StartupState::render(SDL_Renderer* ren)
{
    SDL_RenderClear(ren);
    
    draw_background(ren);
    draw_labels(ren);
    
    SDL_RenderPresent(ren);
}

void StartupState::draw_background(SDL_Renderer* ren)
{
    SDL_Surface *bg_surface = ImageStorage::get_texture(BACKGROUND_STARTUP);
    SDL_Texture *bg = SDL_CreateTextureFromSurface(ren, bg_surface);
//    SDL_FreeSurface(bg_surface);
    
    SDL_Rect bg_RECT;
    bg_RECT.x = 0;
    bg_RECT.y = 0;
    bg_RECT.w = 640;
    bg_RECT.h = 480;
    
    SDL_RenderCopy(ren, bg, NULL, &bg_RECT);
}

void StartupState::draw_labels(SDL_Renderer* ren)
{
    
}

StartupState* StartupState::get_instance() {
    return &instance;
}
