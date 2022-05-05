#include "criterion.h"


namespace criteria
{
/// <summary> Kriterium pre prislusnost. </summary>
template <typename ObjectType>
class CriterionGroundUnitAffiliation : public Criterion<ObjectType, bool>
{
public:
    CriterionGroundUnitAffiliation(const ObjectType& higherGround);
    bool evaluate(const ObjectType& unit) override;
private:
    ObjectType& higherGround_;
};

template<typename ObjectType>
inline CriterionGroundUnitAffiliation<ObjectType>::CriterionGroundUnitAffiliation(const ObjectType& higherGround) :
higherGround_(higherGround)
{
}

template <typename ObjectType>
inline bool CriterionGroundUnitAffiliation<ObjectType>::evaluate(const ObjectType& unit)
{
    return unit.getType();
}
}
