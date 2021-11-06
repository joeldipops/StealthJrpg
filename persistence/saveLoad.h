#ifndef SAVELOAD_H_INCLUDED
#define SAVELOAD_H_INCLUDED

#include <string>

#include "../play/pc.h"
#include "../play/party.h"
#include "../util/assetCache.h"

namespace Persistence {
    class SaveLoad {
        public:
            SaveLoad(const std::string&);
            void save(const Play::Party& party);
            void load(Play::Party& party, Util::AssetCache* cache) const;

        private:
            std::string _path;
            std::vector<byte> getSpellBytes(const Play::PC& pc) const;
            void pushNumeric(std::vector<byte>&, unsigned short);
    };
}

#endif
