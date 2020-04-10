#include "Cell.h"
#include <iostream>
#include <time.h>
#include "PerlinNoise.h"

Cell::Cell(){

}
Cell::Cell(float _speed,float _infectProb){
    speed = _speed;
    infectionProb = _infectProb;
}

sf::Vector2f Cell::RandomDirection(){
    PerlinNoise noise(time(NULL));
    double randomX = noise.noise(10,10,0.8);
    double randomY = noise.noise(10,10,0.8);

    return sf::Vector2f(randomX,randomY);
}


