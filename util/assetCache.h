#ifndef ASSETCACHE_H_INCLUDED
#define ASSETCACHE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <iostream>

#include "../res/sprites.h"

using namespace Resources;

namespace Util {
    class AssetCache {
        public:
            AssetCache();
            AssetCache(SDL_Renderer*);
            ~AssetCache(void);
            SDL_Texture* get(std::string);
            Sprite* getSprite(const SpriteDefinition*);
            TTF_Font* get(std::string, int);
            SDL_Texture* get(std::string, std::string, int, SDL_Colour);

            void discard(std::string);
            void emptyCache(void);

        private:
            std::map<std::string, SDL_Texture*> _imageAssets;
            std::map<const SpriteDefinition*, Sprite*> _spriteAssets;
            std::map<std::string, TTF_Font*> _fontAssets;
            SDL_Renderer* _renderer;
    };
}

#endif
