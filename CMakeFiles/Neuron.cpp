#include "Neuron.hpp"
#include <cmath>

//constructor
Neuron::Neuron(Kind a) : state(false), buffer({0}, kind(a))
{
	time_spikes.clear();
	nb_spikes=0;
}


//Destructor
Neuron::~Neuron()
{}


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

//tells if the neron is spiking or not
bool Neuron::isSpiking() const
{
	return state;
}

//set the neuron's buffer
std::array<double,29> Neuron::setBuffer (int i, double potential)
{
	buffer[i] +=potential;
}

void Neuron::updateNeuronState(double dt, double I)
{
	//after a spike, the neuron stays inactive during a given refractory time and it's potential is 0
	if (refractory_time >= 0){
		mb_potential= 0.0;
		refractory_time-=dt;
		return;
	}
	
	//calcul of the mebrane potential
	mb_potential=exp(-dt/TAU)*mb_potential+ I*R*(1-exp(-dt/TAU));
	
	//si le buffer du neurone post synaptique au pas de temps clock_ contient une valeur, on rajoute cette valeur au potentiel de membrane
	if (buffer[clock_%(int)buffer.size()]!=0){
		mb_potential +=buffer[clock_%(int)buffer.size()];
		buffer[clock_%(int)buffer.size()]=0;
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

//when the pre synaptic neuron is spiking, we had the constant J in the post synaptic neuron buffer with the delay 
void Neuron::sendingMessage(Neuron* n)
{
	if (isSpiking()==true)
	{
		n->setBuffer(((int)(clock_+(DELAY/STEP))%(int)buffer.size()), J);
	}
}


