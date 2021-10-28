#include "spellContext.h"
#include "../play/mob.h"
#include "../play/combatable.h"

namespace Magic {
    using Play::Combatable;
    using Play::Enemy;
    using Play::Mob;
    using Play::PC;
    using std::vector;

    //  Lifecycle

    SpellContext::SpellContext(const vector<Mob*>& pcs_, const vector<Mob*>& hostiles_) {
        _pcs.insert(_pcs.end(), pcs_.begin(), pcs_.end());
        _hostiles.insert(_pcs.end(), hostiles_.begin(), hostiles_.end());
    }

    SpellContext::SpellContext(const vector<PC*>& pcs_, const vector<Enemy*>& hostiles_) {
        vector<Mob*> pcMobs = Util::castVector<PC*, Mob*>(pcs_);
        vector<Mob*> enemyMobs = Util::castVector<Enemy*, Mob*>(hostiles_);

        _pcs.insert(_pcs.end(), pcMobs.begin(), pcMobs.end());
        _hostiles.insert(_hostiles.end(), enemyMobs.begin(), enemyMobs.end());

    }


    /**
     * Garbage collects any memory that was allocated during combat.
     */
    SpellContext::~SpellContext(void) {
        for(Combatable* item : _rubbishBin)
            delete item;

        _rubbishBin = vector<Combatable*>(0);
    }

    //{ Properties
    /**
     * List of mobs in the combat who are hostile to the player.
     */
    vector<Mob*>& SpellContext::hostiles(void) { return _hostiles; }
    vector<Mob*> SpellContext::hostiles(void) const { return _hostiles; }

    /**
     * List of mobs who are controlled by the player.
     */
    vector<Mob*>& SpellContext::pcs(void) { return _pcs; }
    vector<Mob*> SpellContext::pcs(void) const { return _pcs; }

    /**
     * Gets or sets the status of the battlefield.
     */
    bool SpellContext::isInCombat(void) const { return _isInCombat; }
    bool SpellContext::isInCombat(bool isInCombat_) {
        _isInCombat = isInCombat_;
        return _isInCombat;
    }

    // Methods

    /**
     * Keep track of an obj that was allocated during combat.
     */
    void SpellContext::addToField(Combatable* mob, bool isPlayerAllied) {
        _rubbishBin.push_back(mob);

        if (isPlayerAllied) {
            _playerAllied.push_back(mob);
        } else {
            _nonPlayerAllied.push_back(mob);
        }
    }

    /**
     * Returns true if two mobs are on the same side.
     * @param one One of two mobs.
     * @param other Two of two mobs.
     */
    bool SpellContext::areAllied(const Combatable* one, const Combatable* other) const {
        int found = 0;
        for(Combatable* mob : hostiles()) {
            if (mob == one) {
                found++;
            }
            if (mob == other) {
                found++;
            }
        }

        if (found == 2) {
            return true;
        }

        for (Combatable* mob : _nonPlayerAllied) {
            if (mob == one)
                found++;
            if (mob == other)
                found++;
        }

        return found % 2 == 0;
    }

    /**
     * List of all combatable mobs and anything else participating in the battle.
     */
    vector<Combatable*> SpellContext::participants(void) {
        vector<Combatable*> result = vector<Combatable*>();

        for (Mob* m : hostiles()) {
            result.push_back(m);
        }
        for (Mob* m : pcs()) {
            result.push_back(m);
        }
        return result;
    }
}
