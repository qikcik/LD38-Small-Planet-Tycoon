#pragma once

#include "../../engine/sObject.h"
#include "../building/building.h"

class BuildingIcon :public Sobject
{
    public:
        BuildingIcon();
        BuildingIcon(buildingParameters param , sf::Vector2f vec );
        ~BuildingIcon();

        void setParametr(buildingParameters param);
        void setPosition(sf::Vector2f vec);
        void refresh();

        virtual void update();
        virtual void draw();

    private:
        sf::Sprite sprite;
        sf::Sprite sback;
        buildingParameters parametr;
};
