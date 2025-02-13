#include "Map.hpp"
#include "TextureManager.hpp" // Assurez-vous que cette inclusion est présente

Map::Map() {
    // Initialisation des textures
    dirt = TextureManager::LoadTexture("assets/dirt.png");
    grass = TextureManager::LoadTexture("assets/grass.png");
    water = TextureManager::LoadTexture("assets/water.png");

    // Initialisation de la carte
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 25; x++) {
            map[y][x] = 0; // Remplir la carte avec des valeurs par défaut
        }
    }
}

Map::~Map() {
    // Libération des ressources si nécessaire
}

void Map::LoadMap(int arr[20][25]) {
    // Chargement de la carte depuis le tableau
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 25; x++) {
            map[y][x] = arr[y][x];
        }
    }
}

void Map::DrawMap() {
    // Dessiner la carte
    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 25; x++) {
            SDL_Rect src, dest;
            src.x = 0;
            src.y = 0;
            src.w = 32; // Largeur de la texture
            src.h = 32; // Hauteur de la texture

            dest.x = x * 32; // Position x sur la fenêtre
            dest.y = y * 32; // Position y sur la fenêtre
            dest.w = 32;
            dest.h = 32;

            // Choisir la texture en fonction de la valeur dans la carte
            switch (map[y][x]) {
                case 0:
                    TextureManager::DrawTexture(dirt, src, dest);
                    break;
                case 1:
                    TextureManager::DrawTexture(grass, src, dest);
                    break;
                case 2:
                    TextureManager::DrawTexture(water, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
