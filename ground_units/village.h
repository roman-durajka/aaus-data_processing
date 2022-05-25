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
    Village(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation);

    identifications::Education& getEducation() { return *education_; }
    void addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd) override;
    void addSuperiorGroundUnit(ground_units::GroundUnit* superiorGroundUnit) override { superiorGroundUnit_ = superiorGroundUnit; }

    /*
    Ziska kod, ktory sluzi na porovnanie s nizsimi uzemnymi jednotkami.
    */
    std::string getDownComparisonID() override;

    /*
    Ziska kod, ktory sluzi na porovnanie s vyssimi uzemnymi jednotkami.
    */
    std::string getUpComparisonID() override;
private:
    identifications::Education* education_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline Village::Village(identifications::Identification* newID, identifications::Tag* newTag, identifications::Education* newEducation) :
    GroundUnit(village, newID, newTag),
    education_(newEducation),
    superiorGroundUnit_(nullptr)
{
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
