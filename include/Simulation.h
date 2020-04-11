#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"

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

};

#endif // SIMULATION_H
