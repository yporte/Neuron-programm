#include "Neuron.hpp"
#include "Network.hpp"
#include "gtest/include/gtest/gtest.h"
#include <iostream>
#include <cmath>

TEST (NeuronTest, MembranePotential) {
	Neuron n1(1);
	Neuron n2(1);
	Neuron n3(1);
	
	n1.simulation(921, 1.01);
	EXPECT_NEAR(n1.getPotential(), 20, 1);
	
	n2.simulation(0, 1.01);
	EXPECT_NEAR(n2.getPotential(),0, 1);
	
	n3.simulation(925, 1.01);
	EXPECT_NEAR(n3.getPotential(), 0, 1);
	
}

TEST(NeuronTest, NumberSpikes){
	Neuron n(1);
	n.simulation(1000, 1.01);
	EXPECT_EQ(n.getNbSpikes(), 1);	
	}


TEST(NeuronTest, RefractoryTest){
	Neuron n(1);
	if(n.isRefractory()==true){
		EXPECT_EQ(n.getPotential(),0.0);
	}
}

TEST(NetworkTest, NbTargets){
	Network n;
	EXPECT_EQ(n.getNbConnexions(), 1250*12500);
}

int main(int argc, char**argv)
{
	::testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
	
}


