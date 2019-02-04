#include "guiRightLayer.h"
#include "fstream"
#include "fstream"

#include <iostream>


GuiRightLayer::GuiRightLayer()
{
    view.reset(sf::FloatRect(0, 0, engine.WinWidth, engine.WinHeight)); // skad
    view.setSize(1.0f * engine.WinWidth, 1.0f * engine.WinHeight); // gdzie
    view.setViewport(sf::FloatRect(1.f - (450.f / engine.WinWidth) , 0, 1, 1));

    //buildingParameters param;
    //icons.push_back( BuildingIcon ( param , sf::Vector2f(0 ,10)) );
    //param.name = "test";
    //icons.push_back( BuildingIcon ( param , sf::Vector2f(0 ,120)) );

    loadFromFile();
}

GuiRightLayer::~GuiRightLayer()
{
    icons.clear();
}

void GuiRightLayer::events()
{
    if (engine.event.type == sf::Event::MouseWheelScrolled)
    {
        if(engine.event.mouseWheelScroll.delta > 0)
        {
            view.move(0, -10000 * engine.delta);
            std::cout << "up" << std::endl;
        }
        else if(engine.event.mouseWheelScroll.delta < 0)
        {
            view.move(0, 10000 * engine.delta);
            std::cout << "down" << std::endl;
        }
    }
}

void GuiRightLayer::update()
{
    for(auto it : icons)
        it.update();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        view.move(0, 500 * engine.delta);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        view.move(0, -500 * engine.delta);
    }
}

void GuiRightLayer::drawWithoutView()
{
    for(auto it : icons)
        it.draw();
}

void GuiRightLayer::loadFromFile()
{
    std::fstream file;
    file.open( "data/buildings.conf", std::ios::in);

    buildingParameters param;
    int i =0;
    while( !file.eof() )
    {
        std::getline( file,  param.name );
        std::getline( file,  param.description );
        std::getline( file,  param.category );
        file >>  param.minCityLvl;
        file >>  param.cost;
        file >>  param.increasePeople;
        file >> param.addCapacityPeople;
        file >>  param.increaseAgriculture;
        file >>  param.addCapacityAgriculture;
        file >>  param.increaseIndustry;
        file >>  param.addCapacityIndustry;
        file >>  param.increaseEcology;
        file >>  param.increaseSatisfaction;
        file >>  param.increaseMoney;
        std::string x;
        std::getline( file, x);
        icons.push_back( BuildingIcon ( param , sf::Vector2f(340 ,10 + i*110)) );
        i++;
    }


}
