#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
#include <chrono>


class Cell : public sf::Drawable
{
    public:

        float age;
        float socialDistancing;
        float infectionProb;
        float cellSize;
        float speed;

        bool infected = false;
        bool startMoving = false;

        sf::CircleShape circle;
        sf::Vector2f direction;

        Cell();
        Cell(float _size,float _speed = 1,float _infectProb = 1,bool alreadyInfected = false);
        void ChangeColor(sf::Color color);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


};

#endif // CELL_H
