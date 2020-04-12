#include "Cell.h"
#include <iostream>




const int dx[] = {-1,-1,0,1,1,1,0,-1};/// vector de directii
const int dy[] = {0,1,1,1,0,-1,-1,-1};

using namespace std;
using namespace chrono;

Cell::Cell(){

}
Cell::Cell(float _size,float _speed,float _infectProb,bool alreadyInfected){
    cellSize = _size;
    speed = _speed;
    infectionProb = _infectProb;
    infected = alreadyInfected;
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(cellSize);

}
void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(circle);
}
void Cell::ChangeColor(sf::Color color){
    circle.setFillColor(color);
}



