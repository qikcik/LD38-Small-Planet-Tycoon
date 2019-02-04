#pragma once


#include <SFML/Graphics.hpp>
#include <sstream>

class Scene;

class EngineVariables // Singleton
{
    // class
    public:
        int WinWidth;
        int WinHeight;
        bool isFullscreen;
        bool isVsync;
        int antialiasingLevel;
        const std::string title = "LD38";

        sf::RenderWindow window;
        sf::Event event;
        float delta;

        Scene* setScene(Scene* newScene);
        Scene* getScene();
        void updateWindow();
        std::string toString(float number);

    private:
        Scene *scene;

      // singleton interface
    private:
        EngineVariables();
        EngineVariables( const EngineVariables & );
    public:
        static EngineVariables & get() { static EngineVariables s; return s; }
        ~EngineVariables();
};

class Eobject
{
    public:
        EngineVariables &engine = EngineVariables::get();
};
