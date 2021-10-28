#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include <SDL2/SDL.h>

namespace Graphics {
    /**
     * An image from a sprite sheet.
     */
    struct Sprite {
        public:
            Sprite(SDL_Texture* texture, int x, int y, int width, int height);
            Sprite(SDL_Texture* texture, SDL_Rect* stencil);
            SDL_Texture* texture() const;
            SDL_Rect stencil() const;
        private:
            SDL_Texture* _texture;
            SDL_Rect _stencil;
    };
}

#endif