#pragma once

#include "../../engine/sObject.h"

class Earth :public Sobject
{
    public:
        Earth();
        ~Earth();

        virtual void update();
        virtual void draw();

    private:
        sf::Sprite sprite;
};


