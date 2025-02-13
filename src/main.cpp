#include "Game.hpp"

int main(int argc, char* argv[]) {
    Game* game = new Game();
    game->init("Game Title", 100, 100, 800, 600, false);

    while (game->running()) {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    delete game;

    return 0;
}
