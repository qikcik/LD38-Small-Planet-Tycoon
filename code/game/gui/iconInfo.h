#pragma once

#include "../../engine/layer.h"
#include "../building/building.h"

class IconInfo :public Layer
{
    public:
        IconInfo();
        ~IconInfo();

        bool isDraw;


        void setAcutalObject(buildingParameters param);

        virtual void events() {};
        virtual void update();
        virtual inline void drawWithoutView();

    private:
        sf::Sprite sprite;
        sf::Text text[11];


        sf::Sprite sDelete;


};
