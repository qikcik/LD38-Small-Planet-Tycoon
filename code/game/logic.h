#pragma once

#include "../engine/sObject.h"

class Logic : public Sobject
{
    public:
        Logic();
        ~Logic();

        // value

        float cityLvl = 1;

        float increasePeople = 0;
            float amountPeople = 0;
            float CapacityPeople = 0;

        float increaseAgriculture = 0;
            float amountAgriculture = 0;
            float CapacityAgriculture = 0;
        float increaseIndustry = 0;
            float amountIndustry = 0;
            float CapacityIndustry = 0;

        float increaseEcology = 0;
            float amountEcology = 100;
        float increaseSatisfaction = 0;
            float amountSatisfaction = 100;
        float increaseMoney = 0;
            float amountMoney = 100;


        virtual void update();
        virtual void draw();
    private:
        void setDefault();

};
