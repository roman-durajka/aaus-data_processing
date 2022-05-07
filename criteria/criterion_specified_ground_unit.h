#include "criterion.h"
#include "../ground_units/specified_ground_unit.h"


namespace criteria
{
/// <summary> Specificke kriterium pre SpecifiedGroundUnit-s. </summary>
template <typename ResultType>
class CriterionSpecifiedGroundUnit : public Criterion<ground_units::SpecifiedGroundUnit, ResultType>
{
};
}
