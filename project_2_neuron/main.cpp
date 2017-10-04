#include "Neuron.hpp"
#include <fstream>
#include <string>


int main()
{
	Neuron neuron;
	double const T_STOP(100.0);
	double const T_START(0.0);
	double time(T_START);
	double const dt(1);
	
	//l'utilisateur entre une valeur pour l'intensité et on verifie qu'elle est positive
	double intensity;
	do{
		std::cout<<"enter an intensity : ";
		std::cin>>intensity;
		std::cout<<std::endl;
	}while(intensity<0);
	
	//L'utilisateur entre l'intervalle de temps [a,b) durant lequel I(t) sera different de 0 
	//et on vérifie que a>=T_START, a<b et que b>=T_STOP)
	double a;
	double b;
	do{
		std::cout<<"enter a lower bound : ";
		std::cin>>a;
		std::cout<<"and the upper bound : ";
		std::cin>>b;
		std::cout<<std::endl;
	}while(a<T_START and a>=b and b>T_STOP);
	
	
	//on ouvre un fichier externe
	
	std::ofstream file;
	std::string nom_de_fichier("mbPotential.dat");
	file.open(nom_de_fichier.c_str());
	
	
	while(time<T_STOP)
	{
		//Si on est pas dans l'intervalle [a,b), on met à jour le potentiel de membrane avec une intensité qui vaut zéro
		if(time<a or time>=b){
			neuron.updateNeuronState(dt, 0.0);
		} 
		//Si on est dans l'intervalle [a,b), on met à jour le potentiel de membrane avec une intensité qui vaut Iext
		else if(time>=a and time<b){
			neuron.updateNeuronState(dt, intensity);
		}
		
		//On stocke la valeur du potentiel dans un fichier externe	
		file<< "V("<<time<<") = " <<neuron.getPotential()<<std::endl;
		
		//On incrémente le temps
		time+=dt;
	}
	
	//on ferme le fichier
	file.close();
	
}


