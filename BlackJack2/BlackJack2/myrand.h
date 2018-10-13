#pragma once
#include <random>
template<class T> class myrand
{
	std::mt19937* pmt;
	std::uniform_int_distribution<T>* pdist;
public:
	myrand(T const min, T const max);
	myrand();
	myrand(float const min, float const max) = delete;
	T get_rnd();
	~myrand();
};

