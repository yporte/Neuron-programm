#include "Neuron.hpp"
#include <cmath>

double Neuron::getPotential()
{
	return mb_potential;
}

int Neuron::getNbSpikes()
{
	return nb_spikes;
}

std::list <double> Neuron::getTime()
{
	return time_spikes;
}

void Neuron::updateNeuronState(double dt, double I)
{
	mb_potential=exp(-dt/TAU)*mb_potential+ I*R*(1-exp(-dt/TAU));
}
