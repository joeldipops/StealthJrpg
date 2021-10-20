#include <SDL2/SDL.h>
#include "sprite.h"

namespace Graphics {
    Sprite::Sprite(SDL_Texture* texture, int x, int y, int width, int height) {
        _texture = texture;
        _stencil.x = x;
        _stencil.y = y;
        _stencil.w = width;
        _stencil.h = height;
    }

    Sprite::Sprite(SDL_Texture* texture, SDL_Rect* stencil) {
        _texture = texture;
        _stencil.x = stencil->x;
        _stencil.y = stencil->y;
        _stencil.w = stencil->w;
        _stencil.h = stencil->h;
    }

    SDL_Texture* Sprite::texture() const {
        return _texture;
    }

    SDL_Rect Sprite::stencil() const {
        return _stencil;
    }
}