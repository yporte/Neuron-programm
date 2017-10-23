#pragma once
#include "Neuron.hpp"
#include <memory>
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
		void update(double dt, double intensity);
		
	private:
		std::vector <Neuron*> network;
		std::vector<std::vector<int>> connexions;

		
		
}; 
