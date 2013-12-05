#include "Game.h"
#include "StateManager.h"

Game::Game() {
    screen = NULL;
    running = true;
    state_manager = new StateManager;
}

bool Game::running;
StateManager* Game::state_manager;

int Game::execute()
{
    if (!init())
    {
        return -1;
    }
    
    while (running) {
        state_manager->game_loop(ren);
    }
    
    cleanup();
    
    return 0;
}

bool Game::init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Unable to init SDL: %s", SDL_GetError());
        return false;
    }
    
    screen = SDL_CreateWindow("Super Tanks",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              640, 480,
                              SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
    if(screen == NULL) {
        printf("Can't set videomode: %s", SDL_GetError());
        return false;
    }
    
    ren = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL){
        printf("SDL_CreateRenderer Error: %s", SDL_GetError());
        return false;
    }
    
    return true;
}


void Game::cleanup()
{
    SDL_DestroyWindow(screen);
    SDL_Quit();
}

void Game::quit_game()
{
    running = false;
}
