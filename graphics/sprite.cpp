#include <SDL2/SDL.h>
#include "sprite.h"

namespace Graphics {
    // Lifecycle

    /**
     * Constructor
     * @param texture The spritesheet this sprite is taken from.
     * @param x The horizontal co-ordinate the sprite starts on.
     * @param y The vertical co-ordinate the sprite starts on.
     * @param width Horizontal size of the sprite
     * @param height Vertical size of the sprite.
     */
    Sprite::Sprite(SDL_Texture* texture, int x, int y, int width, int height) {
        _texture = texture;
        _stencil.x = x;
        _stencil.y = y;
        _stencil.w = width;
        _stencil.h = height;
    }

    /**
     * Constructor
     * @param texture The spritesheet this sprite is taken from.
     * @param stencil position and size of the sprite on the sheet.
     */
    Sprite::Sprite(SDL_Texture* texture, const SDL_Rect* stencil) {
        _texture = texture;
        _stencil.x = stencil->x;
        _stencil.y = stencil->y;
        _stencil.w = stencil->w;
        _stencil.h = stencil->h;
    }

    /**
     * The spritesheet the imate is on.
     */
    SDL_Texture* Sprite::texture() const {
        return _texture;
    }

    /**
     * Position and size of the sprite on the sheet.
     */
    const SDL_Rect* Sprite::stencil() const {
        return &_stencil;
    }
}