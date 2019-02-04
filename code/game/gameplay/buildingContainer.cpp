#include "BuildingContainer.h"
#include "../gameScene.h"
#include <iostream>

using namespace std;


BuildingContainer::BuildingContainer() :
    mouse ( buildingParameters() )
{
    mouse.reload( buildingParameters() );
    create = false;
    Delete = false;
    mouse.sprite.setColor(sf::Color(255, 255, 255, 128));
}

BuildingContainer::~BuildingContainer()
{
    deleteAllBuilding();
}

void BuildingContainer::update()
{
    for(auto it : buildingList)
        it->update();


    GameScene* scene = dynamic_cast<GameScene*>(engine.getScene());
    sf::Vector2i m = sf::Mouse::getPosition( engine.window );
    sf::Vector2f i= engine.window.mapPixelToCoords( m , scene->gameplayLayer.view);
    sf::Vector2f j(500,500);

    if( sf::Mouse::isButtonPressed( sf::Mouse::Right ))
    {
        Delete = false;
        create = false;
    }

    if(Delete && ( m.x < engine.WinWidth - 200) )
    {
        param.position = atan2((  i.y  - j.y  ),(  i.x - j.x) ) * 180 / 3.14 + 95;
        mouse.rotate(param.position);
        param.name = "cursor";
        scene->gameplayLayer.buildingContainer.setCreateParameters(param);
        float x = param.position;

        mouse.sprite.setColor(sf::Color(255, 0, 0, 128));
        for(int i = 0; i != buildingList.size() ; i++)
        {
            cout << engine.toString(x) + " | " + engine.toString(buildingList[i]->Parameters.position) << endl;
            if ( (x > buildingList[i]->Parameters.position && (x - buildingList[i]->Parameters.position) <= 15) or
                (x < buildingList[i]->Parameters.position && (x - buildingList[i]->Parameters.position) >= -15) )
            {
                mouse.sprite.setColor(sf::Color(255, 255, 255, 128));
                if( sf::Mouse::isButtonPressed( sf::Mouse::Left ))
                {
                    deleteBuilding( i );
                    Delete= false;
                }
                break;
            }
        }



    }

    if(create && ( m.x < engine.WinWidth - 120)  )
    {
        param.position =  atan2((  i.y  - j.y  ),(  i.x - j.y ) ) * 180 / 3.14 + 95;
        mouse.rotate(param.position);


        float pos = param.position;
        bool is = true;
        mouse.sprite.setColor(sf::Color(255, 255, 255, 128));
        for(auto it : buildingList)
        {
            cout << engine.toString(pos) + " | " + engine.toString(it->Parameters.position) << endl;
            if (pos > it->Parameters.position && (pos - it->Parameters.position) <= 35)
                {
                   mouse.sprite.setColor(sf::Color(255, 0, 0, 128));
                    is = false;
                }
            if (pos < it->Parameters.position && (pos - it->Parameters.position) >= -35)
            {
                mouse.sprite.setColor(sf::Color(255, 0, 0, 128));
                is = false;
            }
        }

        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && is )
        {
            create= false;
            addBuilding(new Building ( param ));
        }
    }
}

void BuildingContainer::draw()
{
    for(auto it : buildingList)
        it->draw();

        if(create || Delete)
            mouse.draw();
}


Building* BuildingContainer::addBuilding(Building* newBuilding)
{
    if ( dynamic_cast<GameScene*>(engine.getScene())->logic.amountMoney - newBuilding->Parameters.cost >= 0 )
    {
        dynamic_cast<GameScene*>(engine.getScene())->logic.amountMoney -= newBuilding->Parameters.cost;
        buildingList.push_back(newBuilding);
    }
}

Building* BuildingContainer::getBuilding()
{
    //...
    return nullptr;
}

void BuildingContainer::deleteBuilding(int i)
{
    delete buildingList[i];
    buildingList.erase(buildingList.begin() + i);
}

void BuildingContainer::deleteAllBuilding()
{
     for(auto it : buildingList)
        delete &it;

    buildingList.clear();
}

void BuildingContainer::setCreateParameters (buildingParameters newParam)
{
    this->param = newParam;
    mouse.reload(param);
}
