#include "criterion_specified_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre vzdelanie. </summary>
class CriterionSpecifiedGroundUnitEducation : public CriterionSpecifiedGroundUnit<int>
{
public:
    std::wstring evaluate(const ground_units::SpecifiedGroundUnit& unit) override;
};

inline std::wstring CriterionSpecifiedGroundUnitName::evaluate(const ground_units::SpecifiedGroundUnit& unit)
{
    return unit.getName();
}
}
