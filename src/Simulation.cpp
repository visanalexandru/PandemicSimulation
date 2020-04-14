#include "Simulation.h"



Simulation::Simulation(sf::RenderWindow &win,int numberCells,int nrInfected,float cellSize,float cellSpeed) : displayWindow(win),num_infected(nrInfected){
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

	for(int i=0;i<cells.size();i++){
		sf::Vector2f force(0,0);
		for(int k=0;k<cells.size();k++){
			if(i!=k){
				if(Mathf::distance(cells[i].getPosition(),cells[k].getPosition()) < 80.f){
					if(cells[i].isInfected()){
						if(!cells[k].isInfected())
							force-=Physics::repulsion(cells[i],cells[k],4.f);  /// se atrag
						else force+=Physics::repulsion(cells[i],cells[k],2.f); /// se resping
					}
					else{
						if(cells[k].isInfected())
							force+=Physics::repulsion(cells[i],cells[k],4.f);
						else force+=Physics::repulsion(cells[i],cells[k],2.f);
					}
				}

			}

		}
		sf::Vector2f newvelocity=Mathf::normalize(cells[i].getVelocity()+force)*10.f;
		cells[i].setVelocity(newvelocity);

	}


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
int Simulation::getNumInfected() const{
	return num_infected;
}
bool Simulation::Touches(Cell &a, Cell &b){
	float dist = Mathf::distance(a.getPosition(),b.getPosition());
	if(a.getRadius() + b.getRadius() > dist){
		if(a.isInfected()){
			if(!b.isInfected())
				num_infected++;
			b.setInfected(true);
		}

		if(b.isInfected()){
			if(!a.isInfected())
				num_infected++;
			a.setInfected( true);
		}



//		sf::Vector2f aux=a.getVelocity();
//		a.setVelocity(b.getVelocity());
//		b.setVelocity(aux);
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

