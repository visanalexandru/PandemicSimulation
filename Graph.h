#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include <SFML/Graphics.hpp>

class Graph:public sf::Drawable{
	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		std::vector<sf::Vertex> vertices;	
		int width;
		int height;
		sf::Vector2f position;
	public:
		Graph(int gw,int gh,sf::Vector2f pos);
		void setData(float*samples,int numSamples);
};

#endif
