#pragma once

#include "../../engine/layer.h"
#include "earth.h"
#include "../building/building.h"
#include "buildingContainer.h"

class GameplayLayer :public Layer
{
    public:
        GameplayLayer();
        ~GameplayLayer();

        virtual void events();
        virtual void update();
        virtual inline void drawWithoutView();

        Earth earth;
        BuildingContainer buildingContainer;
        float r;

};

