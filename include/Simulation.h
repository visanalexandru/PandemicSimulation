#ifndef SIMULATION_H
#define SIMULATION_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Cell.h"
#include "PerlinNoise.h"
#include <chrono>
#include <iostream>
#include <cstdlib>
#include<cmath>
#include"Physics.h"
using namespace std;


class Simulation
{
    public:
        Simulation();
        Simulation(sf::RenderWindow &window,int numberCells = 200,int nrInfected = 1,float cellSize = 1,float cellSpeed = 1);
        void SetCommunities(int row,int column);
        void Update();
		int getNumInfected() const;

    private:
        int cell_size;
        int number_cells;
        int number_rows,number_columns;
        vector<Cell>cells;
        sf::RenderWindow &displayWindow;

        vector<sf::VertexArray> verticies;
        void Move(Cell &cell,float deltatime);
        sf::Vector2f RandomDirection(Cell &cell);
        bool Touches(Cell &a, Cell &b);
		int num_infected;
		float width,height;


};

#endif // SIMULATION_H
