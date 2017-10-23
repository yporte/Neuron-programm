#pragma once
#include <iostream>
#include "Constant.hpp"
#include <list>
#include <array>


enum Kind{EXCITATORY, INHIBITORY};

class Neuron
{
	public:
		Neuron();
		~Neuron();
		double getPotential() const;
		int getNbSpikes() const;
		std::list<double>  getTime();
		bool isSpiking() const;
		std::array<double, 29> setBuffer(int i, double potential);
		void updateNeuronState(double t, double I);
		bool isReceivingSignal(Neuron neuron);
		void sendingMessage(Neuron* n);
		
	private:
		double mb_potential;
		int nb_spikes;
		std::list<double> time_spikes;
		int clock_;
		double refractory_time;
		bool state; //if the neuron is spiking it's state is "1", else it is "0"
		Kind kind;
		std::array <double, 29> buffer;
};
