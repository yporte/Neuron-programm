#include "Neuron.hpp"
#include <cmath>

Neuron::Neuron() : state(false)
{
	time_spikes.clear();
	nb_spikes=0;
}

//give the neuron's membrane potential
double Neuron::getPotential() const
{
	return mb_potential;
}

//give the number of spikes
int Neuron::getNbSpikes() const
{
	return nb_spikes;
}

//give the time
std::list<double>  Neuron::getTime()
{
	return time_spikes;
}

bool Neuron::isSpiking() const
{
	return state;
}

void Neuron::updateNeuronState(double dt, double I, Neuron n)
{
	//after a spike, the neuron stays inactive during a given refractory time and it's potential is 0
	if (refractory_time >= 0){
		mb_potential= 0.0;
		refractory_time-=dt;
		return;
	}
	
	//calcul du potentiel de membrane
	mb_potential=exp(-dt/TAU)*mb_potential+ I*R*(1-exp(-dt/TAU));
	
	//si le neurone recoit un message, on ajoute la constante J
	if(isReceivingSignal(n))
	{
		mb_potential+=J;
	}
	//if the membrane potential recheases the threshold, the potential goes back to zero
	if(mb_potential>=V_TH){
		mb_potential=POT_RESET;
		time_spikes.push_back(clock_);
		++nb_spikes;
		state=1; //the neuron is spiking
		
		//we initiate the time to the refractory time after each spike
		refractory_time=REFRACT_TIME;
		return;
	}
	
	clock_+=dt;
	state=0; //the neuron isn't spiking
}

bool Neuron::isReceivingSignal(Neuron neuron)
{
	if(neuron.isSpiking()==true){
		return true;
	}else{
		return false;
	}
}
