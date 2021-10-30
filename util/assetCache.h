#ifndef ASSETCACHE_H_INCLUDED
#define ASSETCACHE_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>
#include <iostream>

#include "../res/sprites.h"
#include "../graphics/sprite.h"

namespace Util {
    class AssetCache {
        public:
            AssetCache();
            AssetCache(SDL_Renderer*);
            ~AssetCache(void);
            Graphics::Sprite* getSprite(std::string, int = 0);
            Graphics::Sprite* getSprite(const Graphics::SpriteDefinition*);
            TTF_Font* get(std::string, int);
            SDL_Texture* getGlyph(std::string, std::string, int, SDL_Colour);

            void discard(std::string);
            void emptyCache(void);

        private:
            SDL_Texture* getTexture(std::string);
            std::map<std::string, SDL_Texture*> _imageAssets;
            std::map<std::string, Graphics::Sprite*> _spriteAssets;
            std::map<std::string, TTF_Font*> _fontAssets;
            SDL_Renderer* _renderer;
    };
}

#endif
