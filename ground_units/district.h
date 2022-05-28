#pragma once

#include "ground_unit.h"

#include "../attributes/identification.h"
#include "../attributes/tag.h"
#include "../attributes/education.h"

#include "../ground_units/village.h"


namespace ground_units
{
/// <summary> Okres. </summary>
class District : public GroundUnit
{
public:
    District();
    District(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);
    District(ground_units::District& other);

    identifications::Education& getEducation() const override { return *education_; };
    void addEducationValues(identifications::Education& otherEducation) const { education_->addEducationValues(otherEducation); }

    /*
    Ziska kod, ktory sluzi na porovnanie s nizsimi uzemnymi jednotkami.
    */
    std::string getDownComparisonID() override;

    /*
    Ziska kod, ktory sluzi na porovnanie s vyssimi uzemnymi jednotkami.
    */
    std::string getUpComparisonID() override;
private:
    structures::SortedSequenceTable<std::string, ground_units::Village*>* villages_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline District::District(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(district, newID, newTag, newEducation),
    superiorGroundUnit_(nullptr)
{
}

inline District::District(ground_units::District& other) :
    GroundUnit(district, new identifications::Identification(*other.ID_), new identifications::Tag(*other.tag_), new identifications::Education(*other.education_)),
    superiorGroundUnit_(nullptr)
{
}

inline std::string District::getDownComparisonID()
{
    return GroundUnit::tag_->getCode().substr(0, 6);
}

inline std::string District::getUpComparisonID()
{
    return GroundUnit::tag_->getCode().substr(0, 5);
}
}
