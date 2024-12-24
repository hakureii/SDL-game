#include "game.h"

Game* game = 0;

int main (int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    game = new Game();

    game->init("MyGame", 1080, 2412);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }
    game->clean();
    return 0;
}
