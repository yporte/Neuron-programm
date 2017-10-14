#pragma once
#include "Neuron.hpp"
#include <cmath>
#include <iostream>
#include "Constant.hpp"
#include <list>
#include <vector>

class Network 
{
	public :
		Network();
		~Network();
	private:
		std::vector <Neuron*> network;
		std::vector<std::vector<int>> connexions;
		
		
}; 
