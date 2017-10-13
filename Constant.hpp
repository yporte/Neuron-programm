#pragma once
#include <iostream>


double const TAU(20.0);      //membrane time constant
double const R(20.0);        //membrane resistance                
double const V_TH(20.0);     //valeur seuil du potentiel de menbrane  
double const DT(1);          //pas de temps           
int const REFRACT_TIME(2);   //temps pendant lequel le neurone reste inactif apres un spike            
double const REFRACT_STEP(REFRACT_TIME/DT); 
int const T_STOP(100);
int const T_START(0);
double const POT_RESET(0.0);  
double const J(10.0);  //constante qu'on ajoute au potentiel de membrane si un neurone recoit un signal d'un autre neurone
