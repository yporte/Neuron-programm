#pragma once
#include <iostream>
#include <list>

double const TAU(20.0);
double const R(1.0);

class Neuron
{
	public:
		double getPotential();
		int getNbSpikes();
		std::list<double> getTime();
		
		void updateNeuronState(double t, double I);
		
		
	private:
		double mb_potential;
		int nb_spikes;
		std::list<double> time_spikes;
	
	
};
