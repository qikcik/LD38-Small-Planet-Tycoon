#pragma once

#include "../../engine/layer.h"
#include "informationLabel.h"

const int infoLabelSize = 7;

class GuiLeftLayer :public Layer
{
    public:
        GuiLeftLayer();
        ~GuiLeftLayer();

        virtual void events();
        virtual void update();
        virtual inline void drawWithoutView();

        InformationLabel infoLabel[infoLabelSize];

};

