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
    District(identifications::Identification* newID, identifications::Tag* newTag);

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
    structures::SortedSequenceTable<std::string, ground_units::GroundUnit*>* villages_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline District::District(identifications::Identification* newID, identifications::Tag* newTag) :
    GroundUnit(district, newID, newTag),
    villages_(new structures::SortedSequenceTable<std::string, ground_units::GroundUnit*>()),
    superiorGroundUnit_(nullptr)
{
}

inline void District::addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd)
{
    int index = 1;
    std::string nameToAdd = groundUnitToAdd->getName();
    while (true) {
        try {
            villages_->insert(nameToAdd, groundUnitToAdd);
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
