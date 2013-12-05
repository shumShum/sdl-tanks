#include "StateManager.h"

#include "StartupState.h"

State* StateManager::current_state;

StateManager::StateManager()
{
    set_current_state(STATE_STARTUP);
}

void StateManager::game_loop(SDL_Renderer* ren)
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        on_event(&event);
    }
    
    on_loop();
    render(ren);
}

void StateManager::on_event(SDL_Event* event)
{
    current_state->on_event(event);
}

void StateManager::on_loop()
{
    current_state->on_loop();
}

void StateManager::render(SDL_Renderer* ren)
{
    current_state->render(ren);
}

void StateManager::set_current_state(int state_id)
{
    if (current_state) current_state->deactivate();
    
    switch (state_id) {
        case STATE_STARTUP:
            current_state = StartupState::get_instance();
            break;
//        case STATE_PLAYING:
//            current_state = PlayingState::get_instance();
//            break;
            
        default:
            break;
    }
    
    if (current_state) current_state->activate();
}

State* StateManager::get_current_state() {
    return current_state;
}