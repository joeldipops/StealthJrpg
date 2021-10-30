#include "jobClass.h"
#include "../core.h"

namespace Play {
    using std::string;

    using Persistence::SavedObjectCode;
    using Resources::JobTemplate;


    // Lifecycle

    /**
     * Constructor
     */
    JobClass::JobClass(const JobTemplate& tmpl) {
        _name = tmpl.Name;
        _code = tmpl.Code;
        _staminaGrowthCoefficient = tmpl.StaminaGrowth;
        _skillGrowthCoefficient = tmpl.SkillGrowth;
        _speedGrowthCoefficient = tmpl.SpeedGrowth;
        _resistanceGrowthCoefficient = tmpl.ResistanceGrowth;
        _defenceGrowthCoefficient = tmpl.DefenceGrowth;
    }

    /**
     * Destructor
     */
    JobClass::~JobClass(void) {}

    // Properties

    const string& JobClass::name(void) const { return _name; }
    SavedObjectCode JobClass::code(void) const { return _code; }
    float JobClass::staminaGrowthCoefficient(void) const { return _staminaGrowthCoefficient; }
    float JobClass::skillGrowthCoefficient(void) const { return _skillGrowthCoefficient; }
    float JobClass::speedGrowthCoefficient(void) const { return _speedGrowthCoefficient; }
    float JobClass::resistanceGrowthCoefficient(void) const { return _resistanceGrowthCoefficient; }
    float JobClass::defenceGrowthCoefficient(void) const { return _defenceGrowthCoefficient; }
}
