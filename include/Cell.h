#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>


class Cell
{
    public:
        float age;
        float socialDistancing;
        float infectionProb;
        float speed;

        Cell();
        Cell(float _speed,float _infectProb = 1); /// default pt probabilitate e 1
        sf::Vector2f RandomDirection();
    private:


};

#endif // CELL_H
