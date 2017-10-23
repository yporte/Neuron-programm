#include "Neuron.hpp"
#include "gtest/include/gtest/gtest.h"
#include <iostream>
#include <cmath>

TEST (NeuronTest, MembranePotential) {
	Neuron n;
	n.updateNeuronState(1, 1.0);
	EXPECT_EQ(n.getPotential(), 0.0);
	
	n.updateNeuronState(56,1.0);
	EXPECT_NEAR(n.getPotential(), 18.0, 1);
	
}

TEST(NeuronTest, NumberSpikes){
	Neuron n;
	for(int i(0); i<100; ++i){
		n.updateNeuronState(i, 1.01);
	}
	EXPECT_EQ(n.getNbSpikes(), 1.01);	
	}

TEST(Neuron, SpkikeTest){
	Neuron n;
	if(n.isSpiking()==true){
		EXPECT_EQ(n.getPotential(),0.0);
	}
}

int main(int argc, char**argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
	
}
