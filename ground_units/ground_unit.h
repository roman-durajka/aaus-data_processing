#pragma once

#include <string>

#include "../attributes/identification.h"
#include "../attributes/tag.h"
#include "../attributes/education.h"

#include "../structures/table/sorted_sequence_table.h"


namespace ground_units
{
class GroundUnit
{
public:
    GroundUnit();
    ~GroundUnit();
    GroundUnit(const GroundUnit& other);
    GroundUnit(Type type, identifications::Identification* id, identifications::Tag* tag, identifications::Education* newEducation);
    Type getType() const { return type_; }
    std::string getName() const { return ID_->getOfficialTitle(); }

    ground_units::GroundUnit* getSuperiorGroundUnit() const;
    void addSuperiorGroundUnit(ground_units::GroundUnit* unitToAdd);

    /*
    Ziska kod, ktory sluzi na porovnanie s nizsimi uzemnymi jednotkami.
    */
    virtual std::string getDownComparisonID() = 0;

    /*
    Ziska kod, ktory sluzi na porovnanie s vyssimi uzemnymi jednotkami.
    */
    virtual std::string getUpComparisonID() = 0;
    virtual identifications::Education& getEducation() const = 0;
    virtual void addEducationValues(identifications::Education& otherEducation) const = 0;

    //operators
    bool operator == (const GroundUnit& other) { return ID_ == other.ID_; }
    bool operator != (const GroundUnit& other) { return ID_ != other.ID_; }
protected:
    Type type_;
    identifications::Identification* ID_;
    identifications::Tag* tag_;
    identifications::Education* education_;

    ground_units::GroundUnit* superiorGroundUnit_;
};

inline GroundUnit::GroundUnit(const GroundUnit& other) :
    type_(other.type_),
    tag_(other.tag_),
    ID_(other.ID_),
    education_(other.education_),
    superiorGroundUnit_(nullptr)
{
}

inline GroundUnit::GroundUnit(Type type, identifications::Identification* id, identifications::Tag* tag, identifications::Education* newEducation) :
    type_(type),
    tag_(tag),
    ID_(id),
    education_(newEducation),
    superiorGroundUnit_(nullptr)
{
}

inline GroundUnit::~GroundUnit()
{
    delete ID_;
    ID_ = nullptr;
    delete tag_;
    tag_ = nullptr;
    delete education_;
    education_ = nullptr;
}

inline void GroundUnit::addSuperiorGroundUnit(ground_units::GroundUnit* unitToAdd)
{
    superiorGroundUnit_ = unitToAdd;
}

inline ground_units::GroundUnit* GroundUnit::getSuperiorGroundUnit() const
{
    if (superiorGroundUnit_ != nullptr)
    {
        return superiorGroundUnit_;
    }
    throw std::logic_error("This ground unit does not have superior unit!");
}
}



