#include "engine.h"

#include <iostream>
#include "scene.h"
#include "../game/gameScene.h"
#include "../menu/menuScene.h"
#include "../menu/gameoverScene.h"


Engine::Engine()
{

}

Engine::~Engine()
{

}

void Engine::run()
{
    initWindow();
    GameLoop();
}

void Engine::initWindow()
{
    using namespace std;
    cout << "Window width: ";
    cin >> engine.WinWidth;
    cout << "Window height: ";
    cin >> engine.WinHeight;

    engine.setScene(new MenuScene);
    engine.updateWindow();
}

void Engine::GameLoop()
{
    sf::RenderWindow &window = engine.window;
    float &delta = engine.delta;
    sf::Clock clock;
    sf::Time deltaTime;

    while (window.isOpen())
    {
        events();
        update();
        draw();

        deltaTime = clock.restart();
        delta = deltaTime.asSeconds();
        std::cout << engine.WinWidth << std::endl;
    }
}

void Engine::events()
{
        sf::Event &event = engine.event;
        sf::RenderWindow &window = engine.window;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            engine.getScene()->events();
        }
}

void Engine::update()
{
    engine.getScene()->update();
}

void Engine::draw()
{
    sf::RenderWindow &window = engine.window;

    window.clear(sf::Color(30,30,30));
        engine.getScene()->draw();
    window.display();
}
