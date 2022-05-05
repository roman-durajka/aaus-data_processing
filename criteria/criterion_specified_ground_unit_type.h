#include "criterion_specified_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre typy. </summary>
class CriterionSpecifiedGroundUnitType : public CriterionSpecifiedGroundUnit<std::string>
{
public:
    std::string evaluate(const ground_units::SpecifiedGroudUnit& unit) override;
};

inline std::string CriterionSpecifiedGroundUnitType::evaluate(const ground_units::SpecifiedGroudUnit& unit)
{
    return unit.getType();
}
}
