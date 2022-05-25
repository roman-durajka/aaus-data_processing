#include "criterion_specified_ground_unit.h"
#include "../ground_units/superior_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre prislusnost do vyssieho celku. </summary>
class CriterionSpecifiedGroundUnitAffiliation : public CriterionSpecifiedGroundUnit<bool>
{
public:
    CriterionSpecifiedGroundUnitAffiliation(ground_units::SuperiorGroundUnit& unit);
    bool evaluate(ground_units::SpecifiedGroundUnit& unit) override;
private:
    ground_units::SuperiorGroundUnit& superiorUnit_;
};

CriterionSpecifiedGroundUnitAffiliation::CriterionSpecifiedGroundUnitAffiliation(ground_units::SuperiorGroundUnit& unit) :
superiorUnit_(unit)
{
}

inline bool CriterionSpecifiedGroundUnitAffiliation::evaluate(ground_units::SpecifiedGroundUnit& unit)
{
    //return unit.isAffiliated(superiorUnit_);
    return true;
}
}
