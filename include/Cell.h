#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
#include "Transformable.h"
#include <chrono>


class Cell : public sf::Drawable,public Transformable
{
	private:
		bool infected;
		float cell_speed;
		float cell_size;
        sf::Vector2f corner;
        sf::CircleShape circle;
    public:
        Cell();
        Cell(sf::Vector2f pos,sf::Vector2f vel,float cell_size,bool is_infected);
        void ChangeColor(sf::Color color);
        void setRadius(float radius);
        void setCorner(sf::Vector2f left_corner);
        void setSpeed(float speed);
        sf::Vector2f getCorner();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		virtual void setPosition(sf::Vector2f other) override;
		void setInfected(bool is_infected);
		bool isInfected() const;
		float getRadius() const;


};

#endif // CELL_H
