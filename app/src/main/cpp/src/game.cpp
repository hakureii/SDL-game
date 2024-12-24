#include "game.h"

bool Game::running() {
    return isRunning;
}

bool Game::init(const char* title, int width, int height) {
    bool status_init = SDL_Init(SDL_INIT_EVERYTHING);
    if (!status_init)
        return false;
    bool status_window = SDL_CreateWindowAndRenderer(title, width, height, 0, &game_window, &game_renderer);
    if (!status_window)
        return false;
    isRunning = true;
    return true;
}

void Game::handleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_EVENT_QUIT:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::clean() {
    SDL_Quit();
}

void Game::render() {
    SDL_RenderClear(game_renderer);
    SDL_RenderPresent(game_renderer);
}

void Game::update() {
    SDL_SetRenderDrawColor(game_renderer, 255, 255, 255, 255);
}
