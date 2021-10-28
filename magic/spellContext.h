#ifndef SPELLCONTEXT_H_INCLUDED
#define SPELLCONTEXT_H_INCLUDED

#include <vector>

namespace Play { class Mob; class Combatable; class Enemy; class PC;}

namespace Magic {
    class SpellContext {
        public:
            SpellContext(void) {};
            SpellContext(const std::vector<Play::Mob*>&, const std::vector<Play::Mob*>&);
            SpellContext(const std::vector<Play::PC*>&, const std::vector<Play::Enemy*>&);
            ~SpellContext(void);

            std::vector<Play::Mob*>& pcs(void);
            std::vector<Play::Mob*> pcs(void) const;

            std::vector<Play::Mob*>& hostiles(void);
            std::vector<Play::Mob*> hostiles(void) const;

            virtual void addToField(Play::Combatable*, bool isPlayerAllied);

            bool isInCombat(bool);
            bool isInCombat(void) const;

            std::vector<Play::Combatable*> participants(void);

            virtual bool areAllied(const Play::Combatable* one, const Play::Combatable* other) const;

        protected:
            std::vector<Play::Mob*> addPC(Play::Mob*);
            std::vector<Play::Mob*> addHostile(Play::Mob*);

        private:
            std::vector<Play::Mob*> _pcs;
            std::vector<Play::Mob*> _hostiles;

            std::vector<Play::Combatable*> _playerAllied = std::vector<Play::Combatable*>(0);
            std::vector<Play::Combatable*> _nonPlayerAllied = std::vector<Play::Combatable*>(0);
            std::vector<Play::Combatable*> _rubbishBin = std::vector<Play::Combatable*>(0);
            bool _isInCombat = false;

    };
}
#endif
