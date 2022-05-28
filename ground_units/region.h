#pragma once

#include "ground_unit.h"

#include "../attributes/identification.h"
#include "../attributes/tag.h"
#include "../attributes/education.h"

#include "../ground_units/district.h"


namespace ground_units
{
/// <summary> Kraj. </summary>
class Region : public GroundUnit
{
public:
    Region();
    Region(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);
    Region(ground_units::Region& other);

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
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline Region::Region(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(region, newID, newTag, newEducation),
    superiorGroundUnit_(nullptr)
{
}

inline Region::Region(ground_units::Region& other) :
    GroundUnit(region, new identifications::Identification(*other.ID_), new identifications::Tag(*other.tag_), new identifications::Education(*other.education_)),
    superiorGroundUnit_(nullptr)
{
}

inline std::string Region::getDownComparisonID()
{
    return GroundUnit::tag_->getNote().substr(5, 5);
}

inline std::string Region::getUpComparisonID()
{
    return GroundUnit::tag_->getNote().substr(5, 2);
}
}
