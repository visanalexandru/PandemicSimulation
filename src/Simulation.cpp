#include "Simulation.h"

Simulation::Simulation(sf::RenderWindow &win,int numberCells,int nrInfected,float cellSize,float cellSpeed) : displayWindow(win){
    int cnt = 0;
    for(int i = 1; i <= numberCells; i++){
        if(cnt < nrInfected){
            cells.push_back(Cell(cellSize,cellSpeed,1,true));
            cnt++;
        }else{
            cells.push_back(Cell(cellSize,cellSpeed,1,false));
        }
    }
}

void Simulation::Update(){
    for(int i = 0; i < cells.size(); i++){
        cells[i].Move();
        if(cells[i].infected == true)
            cells[i].ChangeColor(sf::Color::Red);
        displayWindow.draw(cells[i]);
    }
}

