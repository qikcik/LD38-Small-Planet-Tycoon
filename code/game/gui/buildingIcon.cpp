#include "buildingIcon.h"
#include "../gameScene.h"

BuildingIcon::BuildingIcon()
{
    sback.setTexture(*TextureMenager::get().getTexture("iconBack"));
}

BuildingIcon::~BuildingIcon()
{

}

BuildingIcon::BuildingIcon(buildingParameters param , sf::Vector2f vec )
{
    setParametr(param);
    setPosition(vec);
    sback.setTexture(*TextureMenager::get().getTexture("iconBack"));
    sback.setPosition(vec);
}

void BuildingIcon::setParametr(buildingParameters param)
{
    parametr = param;
    refresh();
}

void BuildingIcon::refresh()
{
    sprite.setTexture(*TextureMenager::get().getTexture(parametr.name));
    sprite.setScale(sf::Vector2f(0.4f , 0.4f));
}

void BuildingIcon::setPosition(sf::Vector2f vec)
{
    sprite.setPosition(sf::Vector2f(20 , 10) + vec);
    sback.setPosition(vec);
}


void BuildingIcon::update()
{
    GameScene* scene = dynamic_cast<GameScene*>(engine.getScene());
    sf::Vector2f mouse( engine.window.mapPixelToCoords(sf::Mouse::getPosition(engine.window) , scene->guiRightLayer.view));
    if(sback.getGlobalBounds().contains(mouse) )
    {
        scene->iconInfo.setAcutalObject(parametr);

        if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) && scene->gameplayLayer.buildingContainer.Delete == false)
        {
            scene->gameplayLayer.buildingContainer.create = true;
            scene->gameplayLayer.buildingContainer.setCreateParameters(parametr);
        }
   }
}

void BuildingIcon::draw()
{
    engine.window.draw(sback);
    engine.window.draw(sprite);
}
