#ifndef GAME_HPP
#define GAME_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <iostream>

class Game{

public:
    Game();
    ~Game();
    static SDL_Renderer *renderer;
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running(){return isRunning;};

private:
    int cpt = 0;
    bool isRunning;
    SDL_Window *window;
    
};

#endif /*GAME_HPP*/