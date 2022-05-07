#include "criterion_specified_ground_unit.h"
#include "../ground_units/superior_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre prislusnost do vyssieho celku. </summary>
class CriterionSpecifiedGroundUnitAffiliation : public CriterionSpecifiedGroundUnit<bool>
{
public:
    CriterionSpecifiedGroundUnitAffiliation(const ground_units::SuperiorGroundUnit& unit);
    bool evaluate(const ground_units::SpecifiedGroundUnit& unit) override;
private:
    const ground_units::SuperiorGroundUnit& superiorUnit_;
};

CriterionSpecifiedGroundUnitAffiliation::CriterionSpecifiedGroundUnitAffiliation(const ground_units::SuperiorGroundUnit& unit) :
superiorUnit_(unit)
{
}

inline bool CriterionSpecifiedGroundUnitAffiliation::evaluate(const ground_units::SpecifiedGroundUnit& unit)
{
    return unit.isAffiliated(superiorUnit_);
}
}
