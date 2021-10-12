#ifndef SPRITES_H_INCLUDED
#define SPRITES_H_INCLUDED

#include <string>
#include <map>

namespace Resources {
    struct Sprite {
        public:
            Sprite(std::string sheet, int index);
            std::string Sheet();
            int Index();
        private:
            std::string _sheet;
            int _index;
    };

    class SpriteIndex {
        public:
            static const std::map<std::string, int> SheetWidths;
            static const Sprite KID_NORTH_0;
            static const Sprite KID_NORTH_1;
            static const Sprite KID_NORTH_2;
            static const Sprite KID_SOUTH_0;
            static const Sprite KID_SOUTH_1;
            static const Sprite KID_SOUTH_2;
            static const Sprite KID_EAST_0;
            static const Sprite KID_EAST_1;
            static const Sprite KID_EAST_2;
            static const Sprite KID_WEST_0;
            static const Sprite KID_WEST_1;
            static const Sprite KID_WEST_2;
    };
}

#endif