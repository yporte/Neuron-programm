#include "Network.hpp"

//constructor
Network::Network()
{
	network={nullptr};
	bool isExcitator;
	
	for(int i=0;  i<NB_TOT; ++i){
		if(i<NB_EXCITATOR){
			bool isExcitator=true;
		}else{
			bool isExcitator=false;
		}
		network.push_back(new Neuron(isExcitator));
	}
	
	
	//choose random connexions 
	
	std::vector<int> table;
	for(size_t i(0); i < network.size(); ++i){
		table = chooseRandomly(0,NB_EXCITATOR,CE,i);
		for (auto t : table){
			network[i]->addConnexions(t);
		}
		table.clear();
		table=chooseRandomly(0+NB_EXCITATOR,NB_EXCITATOR+NB_INHIBITOR, CI, i);
		for(auto t : table){
			network[i]->addConnexions(t);
		}
		table.clear();
	}
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


void Network::update(int steps, double intensity)		
{
	//We update all the Neurons and check if they are connected or not
	std::vector<int> targets;
	for(auto n : network){
		targets = n->getConnexions();
		for(auto t : targets){
			n->sendingMessage(network[t]);
		}
	}
}


std::vector<int> Network::chooseRandomly(int a, int b, int connexion, int x){
	std::default_random_engine randomGenerator; 
    std::uniform_int_distribution<int> disNeuron(a, b);
    std::vector<int> connect;
    connect.clear(); //make sure there is nothing inside
	int i(0);
	do{
		int aleatory(0);
		aleatory = disNeuron(randomGenerator);
		if(aleatory != x){
			connect.push_back(aleatory);
			++i;
		}
	} while (i < connexion);
	
	return connect;
   
}

int Network::getNbConnexions(){
	int c;
	for (size_t i(0); i< network.size(); ++i){
				c += (int)network[i]->getConnexions().size();
	}
	return c;
}
