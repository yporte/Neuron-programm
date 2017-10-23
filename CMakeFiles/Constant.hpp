#pragma once
#include <iostream>


double const TAU(20.0);      //membrane time constant
double const R(20.0);        //membrane resistance                
double const V_TH(20.0);     //valeur seuil du potentiel de menbrane  
double const DT(1);          //pas de temps           
int const REFRACT_TIME(2);   //temps pendant lequel le neurone reste inactif apres un spike            
///double const REFRACT_STEP(REFRACT_TIME/DT); 
int const T_STOP(100);
int const T_START(0);
double const POT_RESET(0.0);  
double const JE(0.1);  //constant we add to the membrane potential if a neuron receives a signal from an excitatory neuron 
double JI(0.5);		   //constant we add to the membrane potential if a neuron receives a signal from an inhibitory neuron 
double const DELAY(1.5); //delay after wich the post synaptic neuron responds 
double const STEP(0.1); 
