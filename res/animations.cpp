#include "animations.h"
#include "sprites.h"
#include "../graphics/animation.h"



namespace Resources {
    using std::vector;

    using Graphics::SpriteDefinition;

    vector<SpriteDefinition*> AnimationIndex::DEFAULT = { &SpriteIndex::KID_SOUTH_0 };
    vector<SpriteDefinition*> AnimationIndex::KID_NORTH = { &SpriteIndex::KID_NORTH_0, &SpriteIndex::KID_NORTH_1, &SpriteIndex::KID_NORTH_2, &SpriteIndex::KID_NORTH_0 }; 
    vector<SpriteDefinition*> AnimationIndex::KID_SOUTH = { &SpriteIndex::KID_SOUTH_0, &SpriteIndex::KID_SOUTH_1, &SpriteIndex::KID_SOUTH_2, &SpriteIndex::KID_SOUTH_0 }; 
    vector<SpriteDefinition*> AnimationIndex::KID_EAST = { &SpriteIndex::KID_EAST_0, &SpriteIndex::KID_EAST_1, &SpriteIndex::KID_EAST_2, &SpriteIndex::KID_EAST_0 }; 
    vector<SpriteDefinition*> AnimationIndex::KID_WEST = { &SpriteIndex::KID_WEST_0, &SpriteIndex::KID_WEST_1, &SpriteIndex::KID_WEST_2, &SpriteIndex::KID_WEST_0 }; 
}