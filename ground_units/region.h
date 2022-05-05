#include "specified_ground_unit.h"


namespace ground_units
{
    /// <summary> Kraj. </summary>
    class Region : public SpecifiedGroudUnit
    {
    public:
        Region(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note);
    };

    inline Region::Region(std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note) :
        SpecifiedGroudUnit("region", officialName, mediumName, shortName, code, note)
    {
    }
}
