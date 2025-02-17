#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <SDL2/SDL.h>
#include "Position.hpp"


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
    void setText(const char * path);
};

#endif/*SPRITE_HPP*/
