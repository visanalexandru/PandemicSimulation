#include "Cell.h"
#include <iostream>

using namespace std;


Cell::Cell(sf::Vector2f position,sf::Vector2f speed,float cell_size,bool is_infected): 
	Transformable(position,speed),
	cellSize(cell_size)
{
	setInfected(is_infected);
	circle.setRadius(cellSize);

}
void Cell::setInfected(bool is_infected){
	infected=is_infected;
	if(infected)
		ChangeColor(sf::Color::Red);
	else ChangeColor(sf::Color::Green);
}

void Cell::setPosition(sf::Vector2f other){
	circle.setPosition(other-sf::Vector2f(cellSize,cellSize));
	position=other;
}
void Cell::draw(sf::RenderTarget &target, sf::RenderStates states) const{
	target.draw(circle);
}
void Cell::ChangeColor(sf::Color color){
	circle.setFillColor(color);
}


bool Cell::isInfected() const{
	return infected;
}

float Cell::getRadius() const{
	return circle.getRadius();
}


