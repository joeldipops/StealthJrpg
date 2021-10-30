#include "party.h"
#include "enemy.h"
#include "../res/sprites.h"

namespace Play {
    using std::vector;

    using Graphics::SpriteDefinition;
    using Magic::Rune;
    using Magic::Spell;
    using Resources::AnimationTrigger;
    using Resources::MapObjectTemplate;
    using Resources::PCTemplate;

    // STATIC HELPERS

    MapObjectTemplate getPCDefaultTemplate(void) {
        MapObjectTemplate result;
        result.ImagePath = "";
        result.IsDense = true;
        return result;
    }

    // LIFECYCLE

    /**
     * Constructor
     */
    Party::Party(void)
     : MapObject(getPCDefaultTemplate()) {
        _members = vector<PC*>(0);
        _bench = vector<PC*>(0);
        x(-1);
        y(-1);
        facing(Direction::SOUTH);
    }

    /**
     * Constructor takes list of members.
     */
    Party::Party(vector<PC*> members_)
     : MapObject(getPCDefaultTemplate()) {
        _members = members_;
    }

    /**
     * Destructor
     */
    Party::~Party(void) {
        for(natural i = 0; i < _members.size(); i++) {
            delete _members.at(i);
        }

        _members = vector<PC*>(0);

        for(Rune* r : _runeCollection) {
            delete r;
        }

        _runeCollection = vector<Rune*>(0);
    }

    // PROPERTIES

    const vector<PC*> Party::members(void) const { return _members; }
    const vector<Rune*> Party::runeCollection(void) const { return _runeCollection; }

    Direction Party::facing() const { 
        if (_members.size() > 0) {
            return leader()->facing();
        }
        return MapObject::facing();
    }

    Direction Party::facing(Direction dir) {
        if (_members.size() > 0) {
            leader()->facing(dir);
        }
        return MapObject::facing(dir);
    }

    int Party::x(int x_) {
        if (_members.size() > 0) {
            leader()->x(x_);
        }
        return MapObject::x(x_);
    }

    int Party::y(int y_) {
        if (_members.size() > 0) {
            leader()->y(y_);
        }
        return MapObject::y(y_);
    }

    // METHODS

    PlayStateContainer& Party::onInspect(PlayStateContainer& data) {
        return data;
    }

    /**
     * After an enemy is defeated, apportion experience points (and any other spoils) amongst party members
     * @param field The battlefield where the corpses of defeated enemies lie.
     */
    void Party::getSpoils(BattleField& field) {
        for(Mob* m : field.hostiles()) {
            if (m->stamina() > 0) {
                continue;
            }

            Enemy* e = (Enemy*) m;
            for (PC* pc : _members) {
                if (pc->stamina() <= 0) {
                    continue;
                }

                pc->getSpoils(e->rewardForDefeat());
            }
        }
    }

    void Party::buryTheDead(void) {
        for (natural i = 0; i < _members.size(); i++) {
            PC* member = _members.at(i);
            if (member->stamina() <= 0) {
                _bench.push_back(member);
                _members.erase(_members.begin() + i);
                i--;
            }
        }
        // set any new leader's loc
        x(x());
        y(y());
    }

    PC* Party::leader(void) const {
        if (_members.size() >= 1) {
            return _members.at(0);
        }

        return nullptr;
    }

    PC* Party::memberAt(natural index) const {
        if (index < 0 || index >= _members.size()) {
            return nullptr;
        }

        return _members.at(index);
    }

    PC* Party::addLeader(const PCTemplate& tmpl) {
        PC* pc = new PC(tmpl);
        if (_members.size() >= 1) {
            delete _members.at(0);
            _members[0] = pc;
        } else {
            _members.push_back(pc);
        }

        pc->location(x(), y());
        return pc;
    }

    PC* Party::addMember(const PCTemplate& tmpl) {

        if (_members.size() <= 0) {
            return addLeader(tmpl);
        }

        PC* pc = new PC(tmpl);
        _members.push_back(pc);
        return pc;
    }

    /**
     * Finds the position of a specific pc in the party.
     * pc The pc to look for.
     */
     int Party::getIndexOf(const Mob* pc) const {
        for(natural i = 0; i < _members.size(); i++) {
            if (pc == _members.at(i)) {
                return i;
            }
        }
        return -1;
    }

    /**
     * Move the member at oldPosition to newPosition in the lineup.
     */
    void Party::reorder(int oldPosition, int newPosition) {
        PC* member = _members.at(oldPosition);
        _members.erase(_members.begin() + oldPosition);
        _members.insert(_members.begin() + newPosition, member);
        leader()->facing(facing());
        leader()->location(x(), y());
    }

    bool Party::isPlayerParty(void) const {
        return true;
    }

    /**
     * Party is defeated if all members are out of stamina.
     */
    bool Party::isDefeated(void) const {
        if (_members.size() <= 0) {
            return true;
        }

        for(PC* pc : _members) {
            if (pc->stamina() > 0)
                return false;
        }
        return true;
    }

    /**
     * The sprite used to represent this mob at the current point in time - follows the party leader.
     */
    const SpriteDefinition* Party::currentSprite() const {
        return leader()->currentSprite();
    }

    /**
     * When combat ends, restore all "dead" party members to 1HP
     */
    void Party::endCombat(void) {
        for (natural i = 0; i < _bench.size(); i++) {
            PC* pc = _bench.at(i);
            pc->stamina(1);
            _members.push_back(pc);
        }

        _bench = vector<PC*>(0);
    }

    void Party::addRunes(Rune* rune) {
        if (rune == nullptr) {
            return;
        }
        for (Rune* r : _runeCollection) {
            if (rune->code() == r->code()) {
                return;
            }
        }
        _runeCollection.push_back(rune);
    }

    void Party::addRunes(vector<Rune*> runes) {
        for (Rune* rune : runes) {
            bool found = false;
            for (Rune* r : _runeCollection) {
                if (r->code() == rune->code()) {
                    found = true;
                }
            }

            if (!found) {
                _runeCollection.push_back(rune);
            }
        }
    }
}