#include <utility>

#include "assetCache.h"
#include "../res/sprites.h"


namespace Util {
    using namespace std;
    using namespace Resources;
    using namespace Graphics;

    /**
     * Constructor
     */
    AssetCache::AssetCache(SDL_Renderer* renderer) {
        _renderer = renderer;
        _imageAssets = map<std::string, SDL_Texture*>();
        _fontAssets = map<std::string, TTF_Font*>();
        _spriteAssets = map<const SpriteDefinition*, Sprite*>();

    }

    /**
     * Destructor
     */
    AssetCache::~AssetCache(void) {
        emptyCache();
    }

    Sprite* AssetCache::getSprite(const SpriteDefinition* def) {
        // If asset is already in the cache, just return it.
        if (_spriteAssets.count(def)) {
            return _spriteAssets.at(def);
        }

        SDL_Texture* texture = get(def->sheet());

        // Get the width and height of the whole image.
        SDL_Rect dimensions;
        SDL_QueryTexture(texture, NULL, NULL, &dimensions.w, &dimensions.h);

        // Determine the width and height of each sprite.
        pair<int, int> sheetSize = SpriteIndex::SheetDimensions.at(def->sheet());
        dimensions.w /= sheetSize.first;
        dimensions.h /= sheetSize.second;

        dimensions.x = dimensions.w * (def->index() % sheetSize.first);
        dimensions.y = dimensions.h * (def->index() / sheetSize.first);

        Sprite* sprite = new Sprite(texture, &dimensions);
        _spriteAssets[def] = sprite;

        return sprite;
    }

    /**
     * Loads an asset, either, from file, or from the cache.
     * @param fileName The filename of the asset.
     * @return The asset in memory.
     */
    SDL_Texture* AssetCache::get(string fileName) {
        // If asset is already in the cache, just return it.
        if (_imageAssets.count(fileName) > 0) {
            return _imageAssets.at(fileName);
        }

        // Otherwise, load the image from disc.
        SDL_Surface* temp = IMG_Load(fileName.c_str());
        if( temp == NULL ) {
            std::cout << "Unable to load image " << IMG_GetError() << std::endl;
        }

        SDL_Texture* result = SDL_CreateTextureFromSurface( _renderer, temp);
        SDL_FreeSurface(temp);

        _imageAssets[fileName] = result;
        return result;
    }

    /**
     * Loads a textual component, either creating it new or pulling from the cache.
     * @param filename The TTF font to generate the texture.
     * @param text The text that will appear on the texture.
     * @param the font pixel size to generate at.
     * @return The text as an SDL_Texture
     */
    SDL_Texture* AssetCache::get(string fileName, string text, int fontSize, SDL_Colour colour) {
        TTF_Font* font = get(fileName, fontSize);
        string key = fileName + ":" + text + ":" + std::to_string(fontSize) + std::to_string(colour.r) + std::to_string(colour.g) + std::to_string(colour.b);

        if (_imageAssets.count(key) > 0) {
            return _imageAssets.at(key);
        }

        SDL_Surface* temp = TTF_RenderText_Solid(font, text.c_str(), colour);
        SDL_Texture* result = SDL_CreateTextureFromSurface(_renderer, temp);
        SDL_FreeSurface(temp);

        _imageAssets[key] = result;
        return result;
    }

    /**
     * Loads a TTF font type asset either from file or from the cache.
     * @param fileName The name of path of the file on disc.
     * @param fontSize the pixel size of the font.
     * @return The font.
     */
    TTF_Font* AssetCache::get(string fileName, int fontSize) {
        string key = fileName + std::to_string(fontSize);
        if(_fontAssets.count(key) > 0) {
            return _fontAssets.at(key);
        }

        TTF_Font* font = TTF_OpenFont(fileName.c_str(), fontSize);
        if (font == NULL) {
            std::cout << "Unable to load font " << TTF_GetError() << std::endl;
        }

        _fontAssets[key] = font;
        return font;
    }

    /**
     * Removes a specific asset from the cache.
     * @param key The key (filename) of the asset.
     */
    void AssetCache::discard(string key) {
        SDL_DestroyTexture(_imageAssets[key]);
        _imageAssets[key] = nullptr;
        _imageAssets.erase(key);

        delete _fontAssets[key];
        _fontAssets[key] = nullptr;
        _fontAssets.erase(key);
    }

    /**
     * Invalidates the entire cache, freeing up memory.
     */
    void AssetCache::emptyCache(void) {
        for (auto &item : _spriteAssets) {
            delete item.second;
        }

        for(auto &item : _imageAssets) {
            SDL_DestroyTexture(item.second);
            item.second = nullptr;
        }

        for(auto &item : _fontAssets) {
            delete item.second;
        }

        _imageAssets = map<string, SDL_Texture*>();
        _fontAssets = map<string, TTF_Font*>();
        _spriteAssets = map<const SpriteDefinition*, Sprite*>();
    }
}