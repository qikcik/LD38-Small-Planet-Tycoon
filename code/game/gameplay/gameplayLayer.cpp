#include "gameplayLayer.h"
#include "../../resurce/textureMenager.h"
#include "../gameScene.h"

GameplayLayer::GameplayLayer()
{
    view.reset(sf::FloatRect(0, 0, 1000, 1000)); // skad
    view.setSize(1.2f * engine.WinWidth, 1.2f * engine.WinHeight); // gdzie
    r = 0;
}

GameplayLayer::~GameplayLayer()
{

}


void GameplayLayer::events()
{

}

void GameplayLayer::update()
{
    r += 2 * engine.delta;
    if(r > 360)
        r = 0;
    view.setRotation( r );
    earth.update();
    buildingContainer.update();
}

void GameplayLayer::drawWithoutView()
{
    earth.draw();
    buildingContainer.draw();
}
