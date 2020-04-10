#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cell.h"

using namespace std; /// lasa-ma sa folosesc std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }



    return 0;
}
