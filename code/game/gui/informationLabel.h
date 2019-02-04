#pragma once

#include "../../engine/sObject.h"

class InformationLabel :public Sobject
{
    public:
        InformationLabel();
        ~InformationLabel();

        void setPosition(sf::Vector2f vec);
        void setTexture(std::string name);

        void setValue(std::string top, std::string bot);
            void setValue(float top, std::string bot);

        void update();
        void draw();
    private:
        sf::Sprite shape;

        sf::Text textTop;
        sf::Text textBot;
};
