#ifndef SPRITES_H_INCLUDED
#define SPRITES_H_INCLUDED

#include <utility>
#include <string>
#include <map>
#include <SDL2/SDL.h>

namespace Resources {
    struct Sprite {
        public:
            Sprite(SDL_Texture* texture, int x, int y, int width, int height);
            Sprite(SDL_Texture* texture, SDL_Rect* stencil);
            SDL_Texture* texture();
            SDL_Rect stencil();
        private:
            SDL_Texture* _texture;
            SDL_Rect _stencil;
    };

    struct SpriteDefinition {
        public:
            SpriteDefinition(std::string sheet, int index);
            std::string sheet();
            int index();
        private:
            std::string _sheet;
            int _index;
    };

    class SpriteIndex {
        public:
            static const std::map<std::string, std::pair<int, int>> SheetDimensions;
            static SpriteDefinition KID_NORTH_0;
            static SpriteDefinition KID_NORTH_1;
            static SpriteDefinition KID_NORTH_2;
            static SpriteDefinition KID_SOUTH_0;
            static SpriteDefinition KID_SOUTH_1;
            static SpriteDefinition KID_SOUTH_2;
            static SpriteDefinition KID_EAST_0;
            static SpriteDefinition KID_EAST_1;
            static SpriteDefinition KID_EAST_2;
            static SpriteDefinition KID_WEST_0;
            static SpriteDefinition KID_WEST_1;
            static SpriteDefinition KID_WEST_2;
    };
}

#endif