#include "StartupState.h"

StartupState::StartupState() {
    
}

StartupState StartupState::instance;

void StartupState::activate()
{
    
}

void StartupState::deactivate()
{
    
}

void StartupState::on_event(SDL_Event* event)
{
    if(event->type == SDL_QUIT) {
        Game::quit_game();
    }
}

void StartupState::on_loop()
{
    
}

void StartupState::render(SDL_Renderer* ren)
{
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

StartupState* StartupState::get_instance()
{
    return &instance;
}



