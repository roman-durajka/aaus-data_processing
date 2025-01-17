#pragma once


namespace criteria
{
/// <summary> Abstraktny predok pre kazde kriterium. </summary>
template <typename ObjectType, typename ResultType>
class Criterion
{
public:
    virtual ~Criterion() = default;
    virtual ResultType evaluate(const ObjectType& object) = 0;
};
}
