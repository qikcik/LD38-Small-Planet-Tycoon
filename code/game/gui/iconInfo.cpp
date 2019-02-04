#include "iconInfo.h"
#include "../gameScene.h"



IconInfo::IconInfo()
{
    view.reset(sf::FloatRect(0, 0, engine.WinWidth, engine.WinHeight)); // skad
    view.setSize(1.0f * engine.WinWidth, 1.0f * engine.WinHeight); // gdzie
    view.setViewport(sf::FloatRect(1.f - (400.f / engine.WinWidth) , 0, 1, 1));

    sprite.setTexture(*TextureMenager::get().getTexture("iconInfo"));
    sprite.setPosition(sf::Vector2f(0,10));

    for (int i = 0 ; i!= 10 ; i++)
    {
        text[i].setFont(TextureMenager::get().font);
        text[i].setCharacterSize(22);
        text[i].setColor(sf::Color::Black);

        text[i].setPosition(sf::Vector2f (  80 + i/5 * 120  ,i/5 * -200 + 65 + (i * 40) ));
        text[i].setString("+0.0");
    }

    text[10].setFont(TextureMenager::get().font);
    text[10].setCharacterSize(22);
    text[10].setColor(sf::Color::Black);
    text[10].setPosition(sf::Vector2f (  90 , 25 ));

    setAcutalObject( buildingParameters () );
    isDraw = false;


    sDelete.setTexture(*TextureMenager::get().getTexture("delete"));
    sDelete.setPosition(sf::Vector2f( 240 , engine.WinHeight - 60));
}

IconInfo::~IconInfo()
{

}

void IconInfo::setAcutalObject(buildingParameters param)
{
    isDraw = true ;
    text[0].setString( engine.toString(param.cost) );
    text[1].setString( engine.toString(param.increasePeople) );
    text[2].setString( engine.toString(param.addCapacityPeople) );
    text[3].setString( engine.toString(param.increaseAgriculture) );
    text[4].setString( engine.toString(param.addCapacityAgriculture) );
    text[5].setString( engine.toString(param.increaseIndustry) );
    text[6].setString( engine.toString(param.addCapacityIndustry) );
    text[7].setString( engine.toString(param.increaseEcology) );
    text[8].setString( engine.toString(param.increaseSatisfaction) );
    text[9].setString( engine.toString(param.increaseMoney) );
    text[10].setString( param.name );
}

void IconInfo::update()
{
    GameScene* scene = dynamic_cast<GameScene*>(engine.getScene());
    sf::Vector2f mouse( engine.window.mapPixelToCoords(sf::Mouse::getPosition(engine.window) , scene->iconInfo.view));

    if(sDelete.getGlobalBounds().contains(mouse) && sf::Mouse::isButtonPressed( sf::Mouse::Left ) && scene->gameplayLayer.buildingContainer.create == false)
    {
        scene->gameplayLayer.buildingContainer.Delete = true;
    }
}

void IconInfo::drawWithoutView()
{
    if(isDraw)
    {
        engine.window.draw(sprite);

        for (int i = 0 ; i!= 11 ; i++)
            engine.window.draw(text[i]);
        isDraw = false;
    }

    engine.window.draw(sDelete);
}
