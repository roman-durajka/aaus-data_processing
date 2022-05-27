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
    ~District();
    District(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);
    District(ground_units::District& other);

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
    structures::SortedSequenceTable<std::string, ground_units::Village*>* villages_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline District::~District()
{
    delete villages_;
    villages_ = nullptr;
}

inline District::District(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(district, newID, newTag, newEducation),
    villages_(new structures::SortedSequenceTable<std::string, ground_units::Village*>()),
    superiorGroundUnit_(nullptr)
{
}

inline District::District(ground_units::District& other) :
    GroundUnit(district, new identifications::Identification(*other.ID_), new identifications::Tag(*other.tag_), new identifications::Education(*other.education_)),
    villages_(new structures::SortedSequenceTable<std::string, ground_units::Village*>()),
    superiorGroundUnit_(nullptr)
{
    for (auto item : *other.villages_)
    {
        villages_->insert(item->getKey(), new Village(*item->accessData()));
    }
}

inline void District::addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd)
{
    int index = 1;
    std::string nameToAdd = groundUnitToAdd->getName();
    ground_units::Village* village = dynamic_cast<ground_units::Village*>(groundUnitToAdd);
    ground_units::Village* villageToAdd = new ground_units::Village(*village);
    villageToAdd->addSuperiorGroundUnit(this);
    while (true) {
        try {
            villages_->insert(nameToAdd, villageToAdd);
            break;
        } catch (std::logic_error&) {
            index++;
            nameToAdd = groundUnitToAdd->getName() + " " + std::to_string(index);
        }
    }
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
