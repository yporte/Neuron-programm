#pragma once
#include <iostream>
#include "Constant.hpp"
#include <list>


class Neuron
{
	public:
		Neuron();
		double getPotential() const;
		int getNbSpikes() const;
		std::list<double>  getTime();
		bool isSpiking() const;
		
		void updateNeuronState(double t, double I, Neuron n);
		bool isReceivingSignal(Neuron neuron);
		
	private:
		double mb_potential;
		int nb_spikes;
		std::list<double> time_spikes;
		double clock_;
		double refractory_time;
		bool state; //if the neuron is spiking it's state is "1", else it is "0"
	
	
};
