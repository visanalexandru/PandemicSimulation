#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "PerlinNoise.h"
#include <chrono>
#include <iostream>
#include <cstdlib>


using namespace std;


class Simulation
{
    public:
        Simulation();
        Simulation(sf::RenderWindow &window,int numberCells = 200,int nrInfected = 1,float cellSize = 1,float cellSpeed = 1);
        void Update();

    private:
        vector<Cell>cells;
        sf::RenderWindow &displayWindow;


        chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now(); /// timpul initial
        int randomTimer = rand() % 10 + 1;

        float width,height;

        void Move(Cell &cell);
        sf::Vector2f RandomDirection(Cell &cell);
        bool Touches(Cell &a, Cell &b);


};

#endif // SIMULATION_H
