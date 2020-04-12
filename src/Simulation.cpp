#include "Simulation.h"



Simulation::Simulation(sf::RenderWindow &win,int numberCells,int nrInfected,float cellSize,float cellSpeed) : displayWindow(win){
    width = displayWindow.getSize().x;
    height = displayWindow.getSize().y;

    int cnt = 0;
    for(int i = 0; i < numberCells; i++){
        if(cnt < nrInfected){
            cells.push_back(Cell(cellSize,cellSpeed,1,true));
            cnt++;
        }else{
            cells.push_back(Cell(cellSize,cellSpeed,1,false));
        }
        cells[i].circle.setPosition(rand() % (int)width,rand() % (int)height);
    }
}

void Simulation::Update(){
    for(int i = 0; i < cells.size(); i++){
        Move(cells[i]);
        if(cells[i].infected == true)
            cells[i].ChangeColor(sf::Color::Red);
        displayWindow.draw(cells[i]);
    }
}
void Simulation::Move(Cell &cell){

    auto t2 = chrono::steady_clock::now();
    if(cell.startMoving == false || chrono::duration_cast<chrono::seconds>(t2 - t1).count() > randomTimer){ /// asa faci un timer in c++
        randomTimer = rand() % 2 + 1;
        cell.direction = RandomDirection(cell);
        t1 = chrono::steady_clock::now();
        cell.startMoving = true;

    }
    sf::Vector2f nextPos = cell.circle.getPosition() + cell.direction;
    if(nextPos.x < cell.cellSize){
        cell.direction.x *= -1;
    }
    if(nextPos.x > width - cell.cellSize){
        cell.direction.x *= -1;
    }
    if(nextPos.y < cell.cellSize){
        cell.direction.y *= -1;
    }
    if(nextPos.y > height - cell.cellSize)
        cell.direction.y *= -1;

    nextPos = cell.circle.getPosition() + cell.direction;
    cell.circle.setPosition(nextPos);
}
sf::Vector2f Simulation::RandomDirection(Cell &cell){
    PerlinNoise perlin(cell.circle.getPosition().x / cell.circle.getPosition().y);
    float randomVal = perlin.noise(cell.circle.getPosition().x / width,cell.circle.getPosition().y / height, rand());
    float randomX = randomVal;
    float randomY = randomVal + 1;
    int val = rand() % 2;
    if(val == 0){/// sa schime directia, perlin-ul da doar valori pozitive intre [0,1]
        randomX *= -1;
        randomY *= -1;
    }
    return sf::Vector2f(randomX / 100 ,randomY / 100);
}
