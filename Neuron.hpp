#pragma once
#include <iostream>
#include "Constant.hpp"
#include <list>
#include <array>
#include <random>

class Neuron
{
	public:
	
		//Constructor
		Neuron(bool type);
		
		//Destructor
		~Neuron();
		
		//Getter
		double getPotential() const;
		int getNbSpikes() const;
		std::list<double>  getTime() const;
		std::vector<int> getConnexions() const;
		bool isSpiking() const;
		
		//Setter
		std::array<double, 29> setBuffer(int i, double potential);
		
		bool isExcitatory();
		bool isRefractory();
		double backgroundNoise();
		bool updateNeuronState(int steps, double I);
		void updateNeuronPotential(double I);
		bool isReceivingSignal(Neuron neuron);
		void sendingMessage(Neuron* n);
		void simulation(int simulation_time, int i_ext);
		void addConnexions(int idx);
		
	private:
		double mb_potential;
		int nb_spikes;
		std::list<double> time_spikes;
		int clock_;
		double refractory_time;
		bool state; //if the neuron is spiking it's state is "1", else it is "0"
		bool type;
		std::array <double, 29> buffer;
		std::vector<int> connexions;
		
};
