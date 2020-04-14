#include "Simulation.h"



Simulation::Simulation(sf::RenderWindow &win,int numberCells,int nrInfected,float cellSize,float cellSpeed) : displayWindow(win),num_infected(nrInfected){
	width = displayWindow.getSize().x;
	height = displayWindow.getSize().y;
    cell_size = cellSize;
    number_cells = numberCells;
    number_rows = number_columns = 1;

	int cnt = 0;
	for(int i = 0; i < numberCells; i++){
		Cell cell;
		float randvelx=(rand()%100-50)/10.f;
		float randvely=(rand()%100-50)/10.f;
        int positionx = rand() % (int)(width - cell_size * 2) + cell_size;
		int positiony = rand() % (int)(height - cell_size * 2) + cell_size;

        cell.setPosition(sf::Vector2f(positionx,positiony));
        cell.setRadius(cellSize);
        cell.setSpeed(cellSpeed);
        cell.setVelocity(Mathf::normalize(sf::Vector2f(randvelx,randvely)) * cellSpeed);
        cell.setCorner(sf::Vector2f(0,0));/// initial e (0,0) coltul
        if(cnt < nrInfected){
            cell.setInfected(true);
            cnt++;
        }
        cells.push_back(cell);
	}

}
void Simulation::SetCommunities(int row,int column){
    number_rows = row;
    number_columns = column;

    int cell_per_room = number_cells / (row * column);
    int current_cells = 0;
    int offset = 10;
    int cornerx = offset,cornery = offset;

    width = (displayWindow.getSize().x - offset * (column + 1)) / column;
    height = (displayWindow.getSize().y - offset * (row + 1)) / row;

    for(int i = 0; i < cells.size(); i++){
        int positionx =  cornerx + rand() % (int)(width - cell_size * 2) + cell_size;
		int positiony =  cornery + rand() % (int)(height - cell_size * 2) + cell_size;
		cells[i].setPosition(sf::Vector2f(positionx,positiony));
		cells[i].setCorner(sf::Vector2f(cornerx,cornery)); /// modific coltul
		current_cells++;
        if(current_cells == cell_per_room){

            sf::VertexArray patrat(sf::LineStrip);
            patrat.append(sf::Vertex(sf::Vector2f(cornerx,cornery)));
            patrat.append(sf::Vertex(sf::Vector2f(cornerx + width,cornery)));
            patrat.append(sf::Vertex(sf::Vector2f(cornerx + width,cornery + height)));
            patrat.append(sf::Vertex(sf::Vector2f(cornerx,cornery + height)));
            patrat.append(sf::Vertex(sf::Vector2f(cornerx,cornery)));
            verticies.push_back(patrat);

            cornerx += width + offset;
            if(cornerx + width > displayWindow.getSize().x - offset){
                cornerx = offset;
                cornery += height + offset;
            }
            current_cells = 0;
        }
    }
}

void Simulation::Update(){

	for(int i=0;i<cells.size();i++){
		sf::Vector2f force(0,0);
		for(int k=0;k<cells.size();k++){
			if(i!=k && cells[i].getCorner() == cells[k].getCorner()){
				if(Mathf::distance(cells[i].getPosition(),cells[k].getPosition()) < 100){
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
		sf::Vector2f newvelocity=Mathf::normalize(cells[i].getVelocity()+force)*20.f;
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

    for(auto const &vertexArray : verticies)
        displayWindow.draw(vertexArray);

    for(auto const &cell : cells)
        displayWindow.draw(cell);

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
    sf::Vector2f left_corner = cell.getCorner();


	if(nextPos.x < left_corner.x + cell.getRadius() || nextPos.x>(left_corner.x + width-cell.getRadius())){
        //cout<<"HIT X";
		cell.setVelocity(sf::Vector2f(-vel.x,vel.y));
	}
	if(nextPos.y < left_corner.y + cell.getRadius() || nextPos.y >(left_corner.y + height-cell.getRadius())){
		cell.setVelocity(sf::Vector2f(vel.x,-vel.y));
        //cout<<"HIT Y";
	}
	cell.UpdatePhysics(deltatime);

}

