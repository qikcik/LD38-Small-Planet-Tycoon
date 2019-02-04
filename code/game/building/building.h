#pragma once

#include <SFML/Graphics.hpp>
#include "../../engine/sObject.h"


struct buildingParameters
{
    std::string name = "blank";
    std::string description = "blank obj";
    std::string category = "none";
    int minCityLvl = 0;
        int cost = 0;

    float increasePeople = 0;
        int addCapacityPeople = 0;
    float increaseAgriculture = 0;
        int addCapacityAgriculture = 0;
    float increaseIndustry = 0;
        int addCapacityIndustry = 0;

    float increaseEcology = 0;
    float increaseSatisfaction = 0;
    float increaseMoney = 0;

    float position = 0;
};

class Building :public Sobject
{
    public:
        Building(buildingParameters param);
        ~Building();

        virtual void draw();
        virtual void update();
        void rotate(float x);

        void reload(buildingParameters param);

        buildingParameters Parameters;
        sf::Sprite sprite;

};
