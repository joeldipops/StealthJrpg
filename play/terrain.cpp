#include "terrain.h"
#include "playStateManager.h"

namespace Play {
    using Resources::MapObjectTemplate;
    using Resources::TerrainTemplate;
    using Util::AssetCache;

    // Lifecycle

    MapObjectTemplate getTerrainDefaultTemplate() {
        MapObjectTemplate result;
        result.ImagePath = "";
        result.IsDense = true;
        return result;
    }

    /**
     * Empty Constructor
     */
    Terrain::Terrain(AssetCache* cache)
     : MapObject(getTerrainDefaultTemplate(), cache) {}

    /**
     * Constructor
     * @param type
     */
    Terrain::Terrain(const TerrainTemplate& tmpl, AssetCache* cache)
     : MapObject(tmpl, cache) {
        _onEnter = tmpl.OnEnter;
    }

    // Methods

    PlayStateContainer& Terrain::onInspect(PlayStateContainer& data) {
        if (onInspectFn() != nullptr)
            return onInspectFn()(this, data);

        return data;
    }

    PlayStateContainer& Terrain::onEnter(PlayStateContainer& data) {
        if (_onEnter != nullptr) {
            return _onEnter(this, data);
        }

        return data;
    }
}
