#include "Cell.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "PerlinNoise.h"
#include <cmath>
#include <chrono>

const int dx[] = {-1,-1,0,1,1,1,0,-1};/// vector de directii
const int dy[] = {0,1,1,1,0,-1,-1,-1};

using namespace std;
using namespace chrono;

Cell::Cell(){

}
Cell::Cell(float _size,float _speed,float _infectProb){
    cellSize = _size;
    speed = _speed;
    infectionProb = _infectProb;
    circle.setFillColor(sf::Color::Red);
    circle.setRadius(cellSize);
    circle.setPosition(rand() % (int)width,rand() % (int)height);
}
void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(circle);
}

sf::Vector2f Cell::RandomDirection(){
    PerlinNoise perlin;
    float randomVal = perlin.noise(circle.getPosition().x / width,circle.getPosition().y / height, 0.8);
    float randomX = randomVal;
    float randomY = randomVal + 1;
    int val = rand() % 2;
    if(val == 0){/// sa schime directia, perlin-ul da doar valori pozitive intre [0,1]
        randomX *= -1;
        randomY *= -1;
    }
    return sf::Vector2f(randomX / 100 * speed,randomY / 100 * speed);
}

void Cell::Move(){

    auto t2 = chrono::steady_clock::now();

    if(startMoving == false || chrono::duration_cast<chrono::seconds>(t2 - t1).count() > randomTimer){ /// asa faci un timer in c++
        randomTimer = rand() % 10 + 1;
        direction = RandomDirection();
        t1 = chrono::steady_clock::now();
        startMoving = true;
    }

    sf::Vector2f nextPos = circle.getPosition() + direction;
    if(nextPos.x < cellSize){
        direction.x *= -1;
    }
    if(nextPos.x > width - cellSize){
        direction.x *= -1;
    }
    if(nextPos.y < cellSize){
        direction.y *= -1;
    }
    if(nextPos.y > height - cellSize)
        direction.y *= -1;
    nextPos = circle.getPosition() + direction;
    circle.setPosition(nextPos);


}
