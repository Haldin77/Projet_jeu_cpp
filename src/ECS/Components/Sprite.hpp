#ifndef SPRITE_HPP
#define SPRITE_HPP

#include "Component.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Position;

class Sprite : public Component {
private:
    Position * position;
    SDL_Texture * texture;
    SDL_Rect srcRect, destRect;

public:
    Sprite() = default;
    Sprite(const char * path) ;
    void init() override ;
    void update() override ;
    void draw() override ;
};

#endif/*SPRITE_HPP*/
