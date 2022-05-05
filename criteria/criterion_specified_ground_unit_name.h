#include "criterion_specified_ground_unit.h"


namespace criteria
{
/// <summary> Kriterium pre nazvy. </summary>
class CriterionSpecifiedGroundUnitName : public CriterionSpecifiedGroundUnit<std::wstring>
{
public:
    std::wstring evaluate(const ground_units::SpecifiedGroudUnit& unit) override;
};

inline std::wstring CriterionSpecifiedGroundUnitName::evaluate(const ground_units::SpecifiedGroudUnit& unit)
{
    return unit.getOfficialName();
}
}
