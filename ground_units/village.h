#include "specified_ground_unit.h"


namespace ground_units
{
/// <summary> Obec. </summary>
class Village : public SpecifiedGroudUnit
{
public:
    Village(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note);
};

inline Village::Village(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note) :
    SpecifiedGroudUnit("village", officialName, mediumName, shortName, code, note)
{
}
}
