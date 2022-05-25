#pragma once

#include <string>

#include "../attributes/identification.h"
#include "../attributes/tag.h"

#include "../structures/table/sorted_sequence_table.h"


//obec, kraj, okres, stat
enum Type {village, region, district, state};


namespace ground_units
{
class GroundUnit
{
public:
    GroundUnit();
    GroundUnit(const GroundUnit& other);
    GroundUnit(Type type, identifications::Identification* id, identifications::Tag* tag);
    Type getType() { return type_; }
    std::string getName() { return ID_->getOfficialTitle(); }
    std::string getGroundId();
    std::string getGroundAbb();
    //bool isAffiliated(const GroundUnit& otherUnit) const;

    /*
    Ziska kod, ktory sluzi na porovnanie s nizsimi uzemnymi jednotkami.
    */
    virtual std::string getDownComparisonID() = 0;

    /*
    Ziska kod, ktory sluzi na porovnanie s vyssimi uzemnymi jednotkami.
    */
    virtual std::string getUpComparisonID() = 0;
    virtual void addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd) = 0;
    virtual void addSuperiorGroundUnit(ground_units::GroundUnit* superiorGroundUnit) = 0;

    //operators
    bool operator == (const GroundUnit& other) { return ID_ == other.ID_; }
    bool operator != (const GroundUnit& other) { return ID_ != other.ID_; }
protected:
    Type type_;
    identifications::Identification* ID_;
    identifications::Tag* tag_;
};

inline GroundUnit::GroundUnit(const GroundUnit& other) :
    type_(other.type_),
    tag_(other.tag_),
    ID_(other.ID_)
{
}

inline GroundUnit::GroundUnit(Type type, identifications::Identification* id, identifications::Tag* tag) :
    type_(type),
    tag_(tag),
    ID_(id)
{
}

inline std::string GroundUnit::getGroundId()
{
    std::string idString;
    switch(type_)
    {
        case village: case district:
            idString = tag_->getCode().substr(3, 3);
            break;
        case region:
            idString = tag_->getCode().substr(7, 3);
            break;
        case state:
            break;
    }

    return idString;
}

inline std::string GroundUnit::getGroundAbb()
{
    std::string codeString;
    codeString = tag_->getCode().substr(0, 2);

    return codeString;
}

/*
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
*/
}



