#pragma once

#include <string>

//obec, kraj, okres, stat
enum Type {village, region, district, state};


namespace ground_units
{
class GroundUnit
{
public:
    GroundUnit(Type type, std::wstring name);
    GroundUnit(Type type, std::wstring name, std::string code, std::string note);
    const Type& getType() const { return type_; }
    const std::wstring& getName() const { return name_; }
    std::string getGroundId() const;
    std::string getGroundAbb() const;
    bool isAffiliated(const GroundUnit& otherUnit) const;
private:
    Type type_;
    std::wstring name_;
    std::string code_;
    std::string note_;
};

inline GroundUnit::GroundUnit(Type type, std::wstring name) :
    type_(type),
    name_(name),
    code_(""),
    note_("")
{
}

inline GroundUnit::GroundUnit(Type type, std::wstring name, std::string code, std::string note) :
    type_(type),
    name_(name),
    code_(code),
    note_(note)
{
}

inline std::string GroundUnit::getGroundId() const
{
    std::string idString;
    switch(type_)
    {
        case village: case district:
            idString = code_.substr(3, 3);
            break;
        case region:
            idString = code_.substr(7, 3);
            break;
        case state:
            break;
    }

    return idString;
}

inline std::string GroundUnit::getGroundAbb() const
{
    std::string codeString;
    codeString = code_.substr(0, 2);

    return codeString;
}

inline bool GroundUnit::isAffiliated(const GroundUnit& otherUnit) const
{
    if (getGroundAbb() != otherUnit.getGroundAbb())
    {
        return false;
    }
    if (otherUnit.getGroundId() != "")
    {
        if (getGroundId() != otherUnit.getGroundId())
        {
            return false;
        }
    }

    return true;
}
}



