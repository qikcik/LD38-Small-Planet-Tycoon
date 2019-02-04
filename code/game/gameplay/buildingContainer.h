#pragma once

#include "../../engine/sObject.h"
#include "../building/building.h"
#include <vector>

class BuildingContainer :Sobject
{
    public:
        BuildingContainer();
        ~BuildingContainer();

        virtual void update();
        virtual void draw();

        bool create;
        bool Delete;
        void setCreateParameters (buildingParameters newParam);


        buildingParameters param;

        Building mouse;
        std::vector<Building*> buildingList;
    private:
        Building* addBuilding(Building* newBuilding);
        Building* getBuilding();
        void deleteBuilding(int i);
        void deleteAllBuilding();


};
