#pragma once

#include "../engine/scene.h"
#include <SFML/Graphics.hpp>

class MenuScene :public Scene
{
    public:
        MenuScene();
        ~MenuScene();

        virtual void events();
        virtual void update();
        virtual void draw();

    private:
        sf::Sprite play;
        sf::Text text[3];

};
