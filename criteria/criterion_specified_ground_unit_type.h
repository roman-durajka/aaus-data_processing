#include "criterion_specified_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre typy. </summary>
class CriterionSpecifiedGroundUnitType : public CriterionSpecifiedGroundUnit<Type>
{
public:
    Type evaluate(ground_units::SpecifiedGroundUnit& unit) override;
};

inline Type CriterionSpecifiedGroundUnitType::evaluate(ground_units::SpecifiedGroundUnit& unit)
{
    return unit.getType();
}
}
