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
    ~Region();
    Region(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);
    Region(ground_units::Region& other);

    void addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd) override;
    void addSuperiorGroundUnit(ground_units::GroundUnit* superiorGroundUnit) override { superiorGroundUnit_ = superiorGroundUnit; }
    ground_units::GroundUnit* getSuperiorGroundUnit() const override { return superiorGroundUnit_; }
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
    structures::SortedSequenceTable<std::string, ground_units::District*>* districts_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline Region::Region(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(region, newID, newTag, newEducation),
    districts_(new structures::SortedSequenceTable<std::string, ground_units::District*>()),
    superiorGroundUnit_(nullptr)
{
}

inline Region::Region(ground_units::Region& other) :
    GroundUnit(region, new identifications::Identification(*other.ID_), new identifications::Tag(*other.tag_), new identifications::Education(*other.education_)),
    districts_(new structures::SortedSequenceTable<std::string, ground_units::District*>()),
    superiorGroundUnit_(nullptr)
{
    for (auto item : *other.districts_)
    {
        districts_->insert(item->getKey(), new District(*item->accessData()));
    }
}

inline Region::~Region()
{
    delete districts_;
    districts_ = nullptr;
}

inline void Region::addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd)
{
    int index = 1;
    std::string nameToAdd = groundUnitToAdd->getName();
    ground_units::District* district = dynamic_cast<ground_units::District*>(groundUnitToAdd);
    ground_units::District* districtToAdd = new District(*district);;
    districtToAdd->addSuperiorGroundUnit(this);
    while (true) {
        try {
            districts_->insert(nameToAdd, districtToAdd);
            break;
        } catch (std::logic_error&) {
            index++;
            nameToAdd = groundUnitToAdd->getName() + " " + std::to_string(index);
        }
    }
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
