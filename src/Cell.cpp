#include "Cell.h"
#include <iostream>

using namespace std;


Cell::Cell(){
    circle.setFillColor(sf::Color::Green);
}
Cell::Cell(sf::Vector2f position,sf::Vector2f speed,float cell_size,bool is_infected):
	Transformable(position,speed),
	cell_size(cell_size)
{
	setInfected(is_infected);
	circle.setRadius(cell_size);
    circle.setFillColor(sf::Color::Green);

}
void Cell::setInfected(bool is_infected){
	infected=is_infected;
	if(infected == true)
        ChangeColor(sf::Color::Red);
    else
        circle.setFillColor(sf::Color::Green);
}

void Cell::setCorner(sf::Vector2f left_corner){
    corner = left_corner;
}
sf::Vector2f Cell::getCorner(){
    return corner;
}
void Cell::setRadius(float radius){
    circle.setRadius(radius);
}
void Cell::setSpeed(float speed){
    cell_speed = speed;
}
void Cell::setPosition(sf::Vector2f other){
	circle.setPosition(other-sf::Vector2f(cell_size,cell_size));
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


