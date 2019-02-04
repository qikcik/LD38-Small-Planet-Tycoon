#include <SFML/Graphics.hpp>

class EngineVariables // Singleton
{
    // singleton interface

    public:
        sf::RenderWindow window;
        sf::Event event;
};



class Scene
{
    public:
        Scene();
        ~Scene();

        virtual void events();
        virtual void update();
        virtual void draw();
};

int main()
{

    sf::RenderWindow window(sf::VideoMode(1280, 720), "LD 38");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(30,30,30));

        window.display();
    }

    return EXIT_SUCCESS;
}
