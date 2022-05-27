#pragma once

#include "ground_unit.h"

#include "../attributes/identification.h"
#include "../attributes/tag.h"
#include "../attributes/education.h"


namespace ground_units
{
/// <summary> Obec. </summary>
class Village : public GroundUnit
{
public:
    Village();
    ~Village();
    Village(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);
    Village(ground_units::Village& other);

    identifications::Education& getEducation() { return *education_; }
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
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline Village::Village(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(village, newID, newTag, newEducation),
    superiorGroundUnit_(nullptr)
{
}

inline Village::Village(ground_units::Village& other) :
    GroundUnit(village, new identifications::Identification(*other.ID_), new identifications::Tag(*other.tag_), new identifications::Education(*other.education_)),
    superiorGroundUnit_(nullptr)
{
}

inline Village::~Village()
{
    superiorGroundUnit_ = nullptr;
}

inline std::string Village::getDownComparisonID()
{
    throw std::logic_error("Village does not have inferior ground unit!");
}

inline std::string Village::getUpComparisonID()
{
    return GroundUnit::tag_->getCode().substr(0, 6);
}

inline void Village::addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd)
{
    throw std::logic_error("Village does not have inferior ground unit!");
}
}
