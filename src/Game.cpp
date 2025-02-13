#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components/Component.hpp"

SDL_Renderer* Game::renderer = nullptr;
Map* map;
Manager manager;
auto& newPlayer(manager.AddEntity());
Game::Game() : isRunning(false) {}

Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        if (IMG_Init(IMG_INIT_PNG) == 0) {
            std::cerr << "Failed to initialize SDL2_image: " << IMG_GetError() << std::endl;
            isRunning = false;
        }
        std::cout << "System Initialised" << std::endl;
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (window) {
            std::cout << "Window created" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            std::cout << "Renderer created" << std::endl;
        }
        isRunning = true;
    } else {
        isRunning = false;
    }

    map = new Map();
    newPlayer.addComponent<Position>(0,0);
    newPlayer.addComponent<Sprite>("assets/Player.png");
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    default:
        break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();
}

void Game::render() {
    SDL_RenderClear(renderer);
    map->DrawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Game cleaned up" << std::endl;
}
