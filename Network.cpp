#include "Network.hpp"

Network::Network()
{
	//we clear the vector before completing the table
	network.clear();
	
	//complete the vector with new neuron
	network.push_back(new Neuron());
	network.push_back(new Neuron());
	
	//choose the connexions randomly
	
	/*for (size_t i(0), i<connexions:size(), ++i){
		for (size_t j(0), j< connexions[i].size(), ++j){
			if (i==j){
				connexions[i][j]==false;
			}else{
			*/	
				 
	connexions[0][0]==false;
	connexions[0][1]==true;
	connexions[1][0]==false;
	connexions[1][1]==false;
	
}

Network::~Network()
{
	for (auto& neuron: network)
	{
		delete neuron;
		neuron=nullptr;
	}
}


		
	
