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
        ///vreau random intre [cellSize,width-cellSize]
        /// random intre [0,width-cellsize*2] + cellSize = Ok
        int positionx = rand() % (int)(width - cellSize * 2) + cellSize;
        int positiony = rand() % (int)(height - cellSize * 2) + cellSize;

        cells[i].circle.setPosition(positionx,positiony);
    }
}

void Simulation::Update(){
    for(int i = 0; i < cells.size(); i++){
        Move(cells[i]);
        for(int j = 0; j < cells.size(); j++){
            if(i != j && Touches(cells[i],cells[j])){
                //out<<"Touch";
            }
        }
        if(cells[i].infected == true)
            cells[i].ChangeColor(sf::Color::Red);
        displayWindow.draw(cells[i]);
    }
}
bool Simulation::Touches(Cell &a, Cell &b){
    float difx = a.circle.getPosition().x - b.circle.getPosition().x;
    float dify = a.circle.getPosition().y - b.circle.getPosition().y;
    float dist = sqrt(difx * difx + dify * dify);
    if(a.circle.getRadius() + b.circle.getRadius() > dist){
        if(a.infected)
            b.infected = true;
        if(b.infected)
            a.infected = true;
        swap(a.direction,b.direction);
        return true;
    }
    return false;
}

void Simulation::Move(Cell &cell){

    auto t2 = chrono::steady_clock::now();
    if(cell.startMoving == false ){///|| chrono::duration_cast<chrono::seconds>(t2 - t1).count() > randomTimer /// asa faci un timer in c++
        //randomTimer = 0.01;
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
    float randomVal = perlin.noise(cell.circle.getPosition().x / width,cell.circle.getPosition().y / height, rand()) * 2;
    randomVal -= 1;
    /// [-1,1]
    float randomX = randomVal;

    randomVal = perlin.noise(cell.circle.getPosition().x / width,cell.circle.getPosition().y / height, rand()) * 2;
    randomVal -= 1;
    float randomY = randomVal;
    sf::Vector2f direction(randomX,randomY);
    float magn = sqrt(direction.x * direction.x + direction.y * direction.y);
    direction.x /= magn * 100;
    direction.y /= magn * 100;
    direction.x *= cell.speed;
    direction.y *= cell.speed;
    return direction;
}
