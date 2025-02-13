#include "Game.hpp"

int main(int argc, char* argv[]) {
    const int FPS = 60;
    const int FrameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    Game* game = new Game();
    game->init("Game Title", 100, 100, 800, 600, false);

    while (game->running()) {
        frameStart = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;
        if (FrameDelay > frameTime) {
            SDL_Delay(FrameDelay - frameTime);
        }
    }

    game->clean();
    delete game;

    return 0;
}
