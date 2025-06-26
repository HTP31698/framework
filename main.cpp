#include <SFML/Graphics.hpp>
#include "InputMgr.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        InputMgr::Clear();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }
        

        //Update
        InputMgr::Update(0.f);

        if (InputMgr::GetKeyDown(sf::Keyboard::A))
        {
            std::cout << "Key Down: A" << std::endl;
        } 
        if (InputMgr::GetKeyUp(sf::Keyboard::A))
        {
            std::cout << "Key Up: A" << std::endl;
        }
        if (InputMgr::GetKey(sf::Keyboard::A))
        {
            std::cout << "Key held: A" << std::endl;
        }

        //Draw
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}