#include "logic.h"
#include "gameScene.h"
#include "../menu/gameoverScene.h"
#include <iostream>

Logic::Logic()
{

}

Logic::~Logic()
{

}

void Logic::update()
{
    GameScene* scene = dynamic_cast<GameScene*>(engine.getScene());

    // getallparam
    setDefault();
    for (auto it : scene->gameplayLayer.buildingContainer.buildingList)
    {
        increasePeople += it->Parameters.increasePeople;
        increaseAgriculture += it->Parameters.increaseAgriculture;
        increaseIndustry += it->Parameters.increaseIndustry;
        increaseEcology += it->Parameters.increaseEcology;
        increaseSatisfaction += it->Parameters.increaseSatisfaction;
        increaseMoney += it->Parameters.increaseMoney;

        CapacityPeople += it->Parameters.addCapacityPeople;
        CapacityAgriculture += it->Parameters.addCapacityAgriculture;
        CapacityIndustry += it->Parameters.addCapacityIndustry;
    }
        amountPeople += increasePeople * engine.delta;
        amountAgriculture += increaseAgriculture * engine.delta;
        amountIndustry += increaseIndustry * engine.delta;
        amountEcology += increaseEcology * engine.delta;
        amountSatisfaction += increaseSatisfaction * engine.delta;
        amountMoney += increaseMoney * engine.delta;

        if(amountPeople > CapacityPeople)
            amountPeople = CapacityPeople;
        if(amountAgriculture > CapacityAgriculture)
            amountAgriculture = CapacityAgriculture;
        if(amountIndustry > CapacityIndustry)
            amountIndustry = CapacityIndustry;

        if(amountEcology > 100)
            amountEcology = 100;
        if(amountSatisfaction > 100)
            amountSatisfaction = 100;
        if(amountMoney > 999999)
            amountMoney = 999999;

    // update stats
    scene->guiLeftLayer.infoLabel[0].setValue("City"," ");
    scene->guiLeftLayer.infoLabel[1].setValue(increaseMoney,engine.toString((int) amountMoney));
    scene->guiLeftLayer.infoLabel[2].setValue(increasePeople,engine.toString((int)amountPeople)+"/"+engine.toString((int)CapacityPeople) );
    scene->guiLeftLayer.infoLabel[3].setValue(increaseAgriculture,engine.toString((int)amountAgriculture)+"/"+engine.toString((int)CapacityAgriculture) );
    scene->guiLeftLayer.infoLabel[4].setValue(increaseIndustry,engine.toString((int)amountIndustry) +"/"+engine.toString((int)CapacityIndustry));
    scene->guiLeftLayer.infoLabel[5].setValue(increaseEcology,engine.toString((int)amountEcology) + "%");
    scene->guiLeftLayer.infoLabel[6].setValue(increaseSatisfaction,engine.toString((int)amountSatisfaction) + "%" );

    if( ( amountPeople < 0) or
        (amountAgriculture < 0) or
        (amountIndustry < 0) or
        (amountEcology < 0) or
        (amountSatisfaction < 0) or
        (amountMoney < 0) )
            engine.setScene(new GameoverScene );
}

void Logic::draw()
{

}

void Logic::setDefault()
{
    increasePeople = 0;
    increaseAgriculture = 0;
    increaseIndustry = 0;
    increaseEcology = 0;
    increaseSatisfaction = 0;
    increaseMoney = 0;

    CapacityPeople = 0;
    CapacityAgriculture = 0;
    CapacityIndustry = 0;
}



