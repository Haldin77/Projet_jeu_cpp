#include "Sprite.hpp"
#include "TextureManager.hpp"

Sprite::Sprite(const char* path){
    setText(path);
}

void Sprite::init()
{
    position = &entity->addComponent<Position>(0,0);
    srcRect.x = srcRect.y = 0;
    srcRect.w = srcRect.h = 32;
    destRect.w = destRect.h = 64;
}

void Sprite::update()
{
    destRect.x = position->x();
    destRect.y = position->y();
}

void Sprite::draw()
{
    TextureManager::DrawTexture(texture,srcRect,destRect);
}

void Sprite::setText(const char * path){
    texture = TextureManager::LoadTexture(path);
}