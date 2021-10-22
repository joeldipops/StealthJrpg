#ifndef SPRITEDEFINITION_H_INCLUDED
#define SPRITEDEFINITION_H_INCLUDED

#include <string>

namespace Graphics {
    class SpriteDefinition {
        public:
            SpriteDefinition(std::string sheet, int index);
            const std::string sheet() const;
            const int index() const;
        private:
            std::string _sheet;
            int _index;
    };
}

#endif