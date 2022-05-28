#pragma once

#include <iostream>

#include "workers/data_loader.h"
#include "workers/startup_dialog.h"
#include "workers/point_search.h"
#include "workers/filtering.h"

using namespace std;

int main()
{
    structures::SortedSequenceTable<std::string, identifications::Education*>* education = loadEducation("/home/roman/CodeBlocks_projects/AUS_semester_work/data/vzdelanie.csv");
    structures::SortedSequenceTable<std::string, ground_units::State*>* states = loadStates();
    structures::SortedSequenceTable<std::string, ground_units::Village*>* villages = loadVillages("/home/roman/CodeBlocks_projects/AUS_semester_work/data/obce.csv", education);
    structures::SortedSequenceTable<std::string, ground_units::Region*>* regions = loadRegions("/home/roman/CodeBlocks_projects/AUS_semester_work/data/kraje.csv");
    structures::SortedSequenceTable<std::string, ground_units::District*>* districts = loadDistricts("/home/roman/CodeBlocks_projects/AUS_semester_work/data/okresy.csv");

    for (auto district : *districts)
    {
        districtLoadInferiorGroundUnits(district->accessData(), villages);
    }

    for (auto region : *regions)
    {
        regionLoadInferiorGroundUnits(region->accessData(), districts);
    }

    for (auto state : *states)
    {
        stateLoadInferiorGroundUnits(state->accessData(), regions);
    }

    while (true) {
        workers::StartupDialog dialog = workers::StartupDialog();
        int choice = dialog.process();

        switch (choice)
        {
            case 1:
            {
                workers::PointSearch pointSearch = workers::PointSearch(*villages, *districts, *regions);
                pointSearch.process();
                continue;
            }
            case 2:
            {
                workers::Filtering filtering = workers::Filtering(*states, *regions, *districts, *villages, new workers::StartupDialog());
                filtering.process();
                continue;
            }
            case 0:
                break;
        }
        break;
    }

    delete states;
    delete regions;
    delete districts;
    delete education;
    delete villages;

    return 0;
}
