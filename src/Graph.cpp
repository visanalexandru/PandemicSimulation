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


	float min_val=samples[0],max_val=samples[0];
	for(int i=0;i<numSamples;i++){
		min_val=std::min(min_val,samples[i]);
		max_val=std::max(max_val,samples[i]);
	}


	float sample_height=(float)(height)/(max_val-min_val);

	for(int i=0;i<numSamples;i++){
		float y=samples[i];
		sf::Vertex to_add;
		to_add.position=sf::Vector2f(i*sample_distance,(y-min_val)*sample_height)+position;
		if(i>1){
			vertices.push_back(vertices[vertices.size()-1]);
		}

		vertices.push_back(to_add);
	}
}
