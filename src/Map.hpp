#ifndef MAP_HPP
#define MAP_HPP

#include "Game.hpp"

class Map {
public:
    Map();
    ~Map();
    void LoadMap(int arr[20][25]);
    void DrawMap();

private:
    SDL_Rect src, dest;
    SDL_Texture* dirt;   // Déclaration de la texture pour la terre
    SDL_Texture* grass;  // Déclaration de la texture pour l'herbe
    SDL_Texture* water;  // Déclaration de la texture pour l'eau

    int map[20][25];
};

#endif // MAP_HPP
