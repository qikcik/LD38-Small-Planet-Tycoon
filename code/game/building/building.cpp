#include "building.h"

Building::Building(buildingParameters param)
{
    reload(param);
}

Building::~Building()
{

}

void Building::draw()
{
    engine.window.draw(sprite);
}

void Building::update()
{

}

void Building::rotate(float x)
{
    sprite.setRotation(x);
}

void Building::reload(buildingParameters param)
{
    sprite.setTexture(*TextureMenager::get().getTexture(param.name));
    sprite.setOrigin(sf::Vector2f(100,430));
    sprite.setPosition(sf::Vector2f(500,500));
    sprite.setRotation(param.position);

    Parameters = param;
}
