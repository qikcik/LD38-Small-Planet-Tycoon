#pragma once

#include "../../engine/layer.h"
#include "buildingIcon.h"
#include <vector>

class GuiRightLayer :public Layer
{
    public:
        GuiRightLayer();
        ~GuiRightLayer();

        virtual void events();
        virtual void update();
        virtual inline void drawWithoutView();

    private:
        std::vector <BuildingIcon> icons;
            void loadFromFile();
};
