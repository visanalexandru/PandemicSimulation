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

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        Cell();
        Cell(float _size,float _speed = 1,float _infectProb = 1);
        void Move();
        sf::Vector2f RandomDirection();
    private:

        bool startMoving = false;
        float width = 600,height = 600; /// trebuie sa vad cum iau width,height din window,e aiurea sa pun ca parametru la constructor
        int randomTimer = rand() % 10 + 1;
        sf::CircleShape circle;
        sf::Vector2f direction;
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();


};

#endif // CELL_H
