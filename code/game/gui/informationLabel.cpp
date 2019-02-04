#include "informationLabel.h"

InformationLabel::InformationLabel()
{
    shape.setPosition(sf::Vector2f(10 ,10));

    textTop.setFont(TextureMenager::get().font);
    textTop.setCharacterSize(25);
    textTop.setPosition(sf::Vector2f(90 ,20));
    textBot.setFont(TextureMenager::get().font);
    textBot.setCharacterSize(18);
    textBot.setPosition(sf::Vector2f(90 ,55));

    textTop.setFillColor(sf::Color::Black);
    textBot.setFillColor(sf::Color::Black);

    textTop.setString("+ 12,565");
    textBot.setString("9999999");
}

InformationLabel::~InformationLabel()
{

}

void InformationLabel::update()
{

}

void InformationLabel::draw()
{
    engine.window.draw(shape);
    engine.window.draw(textTop);
    engine.window.draw(textBot);
}

void InformationLabel::setPosition(sf::Vector2f vec)
{
    shape.setPosition(vec);
    textTop.setPosition(vec + sf::Vector2f(90 ,20));
    textBot.setPosition(vec + sf::Vector2f(90 ,55));
}

void InformationLabel::setTexture(std::string name)
{
    shape.setTexture(*TextureMenager::get().getTexture("frame/frame" + name));
}

void InformationLabel::setValue(std::string top, std::string bot)
{
    textTop.setString(top);
    textBot.setString(bot);
}

void  InformationLabel::setValue(float top, std::string bot)
{
    if(top > 0)
    {
        textTop.setColor(sf::Color::Green);
        textTop.setString("+" + engine.toString(top));
    }
    else
    {
        textTop.setColor(sf::Color::Red);
        textTop.setString(engine.toString(top));
    }

    textBot.setString(bot);

}

