#pragma once

#include <random>

template <class T>
class Randomizer
{
public:
	static T randomize(T from, T to)
	{
		std::random_device randomDevice;
		std::mt19937 mt ( randomDevice() );
		std::uniform_real<> uniformDistribution( from, to );
		return uniformDistribution( mt );
	};
};

