#include "criterion_specified_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre nazvy. </summary>
class CriterionSpecifiedGroundUnitName : public CriterionSpecifiedGroundUnit<std::string>
{
public:
    std::string evaluate(ground_units::SpecifiedGroundUnit& unit) override;
};

inline std::string CriterionSpecifiedGroundUnitName::evaluate(ground_units::SpecifiedGroundUnit& unit)
{
    return unit.getName();
}
}
