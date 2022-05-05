#include "specified_ground_unit.h"


namespace ground_units
{
/// <summary> Okres. </summary>
class District : public SpecifiedGroudUnit
{
public:
    District(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note);
};

inline District::District(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note) :
    SpecifiedGroudUnit("district", officialName, mediumName, shortName, code, note)
{
}
}
