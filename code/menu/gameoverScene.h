#pragma once

#include "../engine/scene.h"
#include <SFML/Graphics.hpp>

class GameoverScene :public Scene
{
    public:
        GameoverScene();
        ~GameoverScene();

        virtual void events();
        virtual void update();
        virtual void draw();

    private:
        sf::Sprite play;
        sf::Text text;
        float x;

};
