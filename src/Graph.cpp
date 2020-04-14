#include "Graph.h"
#include<iostream>

Graph::Graph(int gw,int gh,sf::Vector2f pos):
	width(gw),height(gh),position(pos)
{

}
void Graph::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(&vertices[0],vertices.size(),sf::Lines);
}


void Graph::setData(float*samples,int numSamples){
	float sample_distance=(float)width/(float)(numSamples-1);
	vertices.clear();

	if(numSamples==0)
		return;

	for(int i=0;i<numSamples;i++){
		float y=20-samples[i]/20.f;
		sf::Vertex to_add;
		to_add.position=sf::Vector2f(i*sample_distance,position.y+y*10);
		if(i>1){
			vertices.push_back(vertices[vertices.size()-1]);
		}

		vertices.push_back(to_add);
	}
}
