#include "animations.h"
#include "sprites.h"
#include "../graphics/animation.h"



namespace Resources {
    using Graphics::Frame;

    std::vector<Frame*> AnimationIndex::DEFAULT = { new Frame(&SpriteIndex::KID_SOUTH_0) };
    std::vector<Frame*> AnimationIndex::KID_NORTH = { new Frame(&SpriteIndex::KID_NORTH_0), new Frame(&SpriteIndex::KID_NORTH_1), new Frame(&SpriteIndex::KID_NORTH_2), new Frame(&SpriteIndex::KID_NORTH_0) }; 
    std::vector<Frame*> AnimationIndex::KID_SOUTH = { new Frame(&SpriteIndex::KID_SOUTH_0), new Frame(&SpriteIndex::KID_SOUTH_1), new Frame(&SpriteIndex::KID_SOUTH_2), new Frame(&SpriteIndex::KID_SOUTH_0) }; 
    std::vector<Frame*> AnimationIndex::KID_EAST = { new Frame(&SpriteIndex::KID_EAST_0), new Frame(&SpriteIndex::KID_EAST_1), new Frame(&SpriteIndex::KID_EAST_2), new Frame(&SpriteIndex::KID_EAST_0) }; 
    std::vector<Frame*> AnimationIndex::KID_WEST = { new Frame(&SpriteIndex::KID_WEST_0), new Frame(&SpriteIndex::KID_WEST_1), new Frame(&SpriteIndex::KID_WEST_2), new Frame(&SpriteIndex::KID_WEST_0) }; 
}