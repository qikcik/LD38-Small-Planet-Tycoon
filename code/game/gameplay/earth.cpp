#include "earth.h"
#include "../../resurce/textureMenager.h"

Earth::Earth()
{
    sprite.setTexture(*TextureMenager::get().getTexture("earth"));
    sprite.setOrigin(sf::Vector2f(250,250));
    sprite.setPosition(sf::Vector2f(500,500));
}

Earth::~Earth()
{

}

void Earth::update()
{

}

void Earth::draw()
{
    engine.window.draw(sprite);
}



