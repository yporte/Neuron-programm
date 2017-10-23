#include "Network.hpp"

//constructor
Network::Network()
{
	//we clear the vector network before completing the table
	network.clear();
	for(int(i), i<2500; ++i){
		network.push_back(new Neuron(INHIBITORY));
	}
	
	for(int(i), i<10000; ++i){
		network.push_back(new Neuron(EXCITATORY));
	}
	
	//we clear the vector connexions before completing the table
	
	for (size_t i(0), i<connexions:size(), ++i){
		connexions[i].clear();
	}
	
	//choose the connexions randomly
	
	for (size_t i(0), i<connexions:size(), ++i){
		for (size_t j(0), j< connexions[i].size(), ++j){
			if (i==j){
				//can't connect itself
				connexions[i][j]==false;
			}else{
			
				 
	connexions[0][0]==false;
	connexions[0][1]==true;
	connexions[1][0]==false;
	connexions[1][1]==false;
	
}

//destructor

Network::~Network()
{
	for (auto& neuron: network)
	{
		delete neuron;
		neuron=nullptr;
	}
}


void Network::update(double dt, double intensity)		
{
	for (size_t i(0); i<connexions.size(); ++i){
		for (size_t j(0); j<connexions[i].size(); ++j){
			if(connexions[i][j]==1){
				network[j]->sendingMessage(network[i]);
			}
			network[i]->updateNeuronState(dt, intensity);
		}
	}
}
