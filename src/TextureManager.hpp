#ifndef TEXTURE_MANAGER_HPP
#define TEXTURE_MANAGER_HPP

#include "Game.hpp"

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void DrawTexture(SDL_Texture* texture, SDL_Rect src,SDL_Rect dest);
};
#endif // TEXTURE_MANAGER_HPP