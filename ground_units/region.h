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
    Region(identifications::Identification* newID, identifications::Tag* newTag);

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
    structures::SortedSequenceTable<std::string, ground_units::GroundUnit*>* districts_;
    ground_units::GroundUnit* superiorGroundUnit_;
};

inline Region::Region(identifications::Identification* newID, identifications::Tag* newTag) :
    GroundUnit(region, newID, newTag),
    districts_(new structures::SortedSequenceTable<std::string, ground_units::GroundUnit*>()),
    superiorGroundUnit_(nullptr)
{
}

inline void Region::addInferiorGroundUnit(ground_units::GroundUnit* groundUnitToAdd)
{
    int index = 1;
    std::string nameToAdd = groundUnitToAdd->getName();
    while (true) {
        try {
            districts_->insert(nameToAdd, groundUnitToAdd);
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
