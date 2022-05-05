#include "ground_unit.h"


namespace ground_units
{
class SpecifiedGroudUnit : public GroudUnit
{
public:
    SpecifiedGroudUnit(std::string type, std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note);
    const std::wstring& getOfficialName() const { return officialName_; }

protected:
    std::wstring officialName_;
    std::wstring mediumName_;
    std::wstring shortName_;
    int code_;
    int note_;
};

inline SpecifiedGroudUnit::SpecifiedGroudUnit(std::string type, std::wstring officialName, std::wstring mediumName, std::wstring shortName, int code, int note) :
    GroudUnit(type),
    officialName_(officialName),
    mediumName_(mediumName),
    shortName_(shortName),
    code_(code),
    note_(note)
{
}
}
