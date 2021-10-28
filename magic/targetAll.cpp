#include "targetAll.h"

namespace Magic {
    using std::vector;

    // Lifecycle

    /**
     * Constructor
     */
    TargetAll::TargetAll(std::vector<Combatable*> all_)
     :Combatable() {
        _all = all_;
    }


    // Methods

    /**
     * Equally distributes effect across each obj.
     */
    int TargetAll::changeStamina(int delta) {
        int change = ceil(getDistribution(delta));
        for (Combatable* obj : _all) {
            obj->changeStamina(change);
        }

        return stamina();
    }

    /**
     *
     */
    float TargetAll::changeSpeed(float delta) {
        int change = ceil(getDistribution(delta));
        for (Combatable* obj : _all) {
            obj->changeSpeed(change);
        }
        return speed();
    }

    /**
     *
     */
    float TargetAll::changeDefence(float delta) {
        int change = ceil(getDistribution(delta));
        for (Combatable* obj : _all) {
            obj->changeDefence(change);
        }
        return defence();
    }

    /**
     *
     */
    float TargetAll::changeResistance(float delta) {
        int change = ceil(getDistribution(delta));
        for (Combatable* obj : _all) {
            obj->changeResistance(change);
        }
        return resistance();
    }

    float TargetAll::changeSkill(float delta) {
        int change = ceil(getDistribution(delta));
        for (Combatable* obj : _all) {
            obj->changeSkill(change);
        }
        return skill();
    }

    int TargetAll::stamina(void) const {
        vector<int> elements = std::vector<int>(0);
        for (Combatable* obj : _all) {
            elements.push_back(obj->stamina());
        }
        return calculateMean(elements);
    }

    float TargetAll::speed(void) const {
        vector<float> elements = vector<float>(0);
        for (Combatable* obj : _all) {
            elements.push_back(obj->speed());
        }
        return calculateMean(elements);
    }

    float TargetAll::resistance(void) const {
        vector<float> elements = vector<float>(0);
        for (Combatable* obj : _all) {
            elements.push_back(obj->resistance());
        }
        return calculateMean(elements);
    }

    float TargetAll::defence(void) const {
        vector<float> elements = vector<float>(0);
        for (Combatable* obj : _all) {
            elements.push_back(obj->defence());
        }
        return calculateMean(elements);
    }

    float TargetAll::skill(void) const {
        vector<float> elements = vector<float>(0);
        for (Combatable* obj : _all) {
            elements.push_back(obj->skill());
        }
        return calculateMean(elements);
    }

    float TargetAll::calculateMean(vector<float> elements) const {
        float total = 0;
        for (float x : elements) {
            total += x;
        }

        return total / elements.size();
    }

    float TargetAll::calculateMean(vector<int> elements) const {
        int total = 0;
        for (int x : elements) {
            total += x;
        }

        return total / float(elements.size());
    }

    /**
     *
     */
    float TargetAll::getDistribution(float amount) const {
        if (_all.size() <= 0) {
            return 0;
        }
        return amount / float(_all.size());
    }

    unsigned short TargetAll::maxStamina(void) const {
        return 0;
    }

    void TargetAll::endCombat(void) {
        return;
    }
}

