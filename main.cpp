#include <iostream>

#include "workers/data_loader.h"

using namespace std;

int main()
{
    structures::SortedSequenceTable<std::string, ground_units::State*>* states = loadStates();
    structures::SortedSequenceTable<std::string, identifications::Education*>* education = loadEducation("/home/roman/CodeBlocks_projects/AUS_semester_work/data/vzdelanie.csv");
    structures::ArrayList<ground_units::GroundUnit*>* villages = loadVillages("/home/roman/CodeBlocks_projects/AUS_semester_work/data/obce.csv", education);
    structures::ArrayList<ground_units::GroundUnit*>* regions = loadRegions("/home/roman/CodeBlocks_projects/AUS_semester_work/data/kraje.csv");
    structures::ArrayList<ground_units::GroundUnit*>* districts = loadDistricts("/home/roman/CodeBlocks_projects/AUS_semester_work/data/okresy.csv");

    auto iteratorStart = districts->getBeginIterator();
    auto iteratorEnd = districts->getEndIterator();
    while (*iteratorStart != *iteratorEnd) {
        auto* district = *(*iteratorStart);
        ++(*iteratorStart);
        loadInferiorGroundUnits(district, villages);
    }

    iteratorStart = regions->getBeginIterator();
    iteratorEnd = regions->getEndIterator();
    while (*iteratorStart != *iteratorEnd) {
        auto* region = *(*iteratorStart);
        ++(*iteratorStart);
        loadInferiorGroundUnits(region, districts);
    }

    iteratorStart = regions->getBeginIterator();
    iteratorEnd = regions->getEndIterator();
    while (*iteratorStart != *iteratorEnd) {
        auto* state = *(*iteratorStart);
        ++(*iteratorStart);
        loadInferiorGroundUnits(state, regions);
    }


    /*
    for (int i = 0; i < 10; i++) {
        auto* asdfe = dynamic_cast<ground_units::State*>(states->at(i));
        std::cout << asdfe->getName();
        std::cout << '\n';
        std::cout << asdfe->villages_->size();
        std::cout << '\n';
    }
    */



    /*

    auto iteratorStart = table->getBeginIterator();
    auto iteratorEnd = table->getEndIterator();
    while (*iteratorStart != *iteratorEnd) {
        auto* newEd = *(*iteratorStart);
        ++(*iteratorStart);
        std::cout << newEd->accessData()->getCode();
        std::cout << '\n';
    }
    */

    return 0;
}
