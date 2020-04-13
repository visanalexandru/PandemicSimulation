#include "Simulation.h"



Simulation::Simulation(sf::RenderWindow &win,int numberCells,int nrInfected,float cellSize,float cellSpeed) : displayWindow(win){
	width = displayWindow.getSize().x;
	height = displayWindow.getSize().y;

	int cnt = 0;
	for(int i = 0; i < numberCells; i++){
		///vreau random intre [cellSize,width-cellSize]
		/// random intre [0,width-cellsize*2] + cellSize = Ok

		int positionx = rand() % (int)(width - cellSize * 2) + cellSize;
		int positiony = rand() % (int)(height - cellSize * 2) + cellSize;
		float randvelx=(rand()%100-50)/10.f;
		float randvely=(rand()%100-50)/10.f;


		if(cnt < nrInfected){
			cells.push_back(Cell(sf::Vector2f(positionx,positiony),sf::Vector2f(randvelx,randvely),cellSize,true));
			cnt++;
		}else{
			cells.push_back(Cell(sf::Vector2f(positionx,positiony),sf::Vector2f(randvelx,randvely),cellSize,false));
		}

	}
}

void Simulation::Update(){
	for(Cell&a:cells){
		Move(a,0.01);
	}
	for(int i=0;i<cells.size()-1;i++){
		for(int k=i+1;k<cells.size();k++){
			Touches(cells[i],cells[k]);
		}
	}


	for (const Cell& a:cells)
		displayWindow.draw(a);

}
bool Simulation::Touches(Cell &a, Cell &b){
	float dist = Physics::distance(a.getPosition(),b.getPosition());
	if(a.getRadius() + b.getRadius() > dist){
		if(a.isInfected())
			b.setInfected(true);
		if(b.isInfected())
			a.setInfected( true);


		sf::Vector2f aux=a.getVelocity();
		a.setVelocity(b.getVelocity());
		b.setVelocity(aux);
		return true;
	}
	return false;
}

void Simulation::Move(Cell &cell,float deltatime){

	sf::Vector2f nextPos = cell.getPosition() + cell.getVelocity()*deltatime;
	sf::Vector2f vel=cell.getVelocity();
	if(nextPos.x < cell.getRadius() || nextPos.x>(width-cell.getRadius())){
		cell.setVelocity(sf::Vector2f(-vel.x,vel.y));
	}
	if(nextPos.y < cell.getRadius() || nextPos.y >(height-cell.getRadius())){
		cell.setVelocity(sf::Vector2f(vel.x,-vel.y));
	}
	cell.UpdatePhysics(deltatime);

}

