#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define SDL_INIT_EVERYTHING ~0U

class Game {
public:
    Game() {}
    ~Game() {}

    bool init(const char* title, int width, int height);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running();

private:
    SDL_Window* game_window = NULL;
    SDL_Renderer* game_renderer = NULL;

    bool isRunning = false;
};
