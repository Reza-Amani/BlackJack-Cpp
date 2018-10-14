#pragma once
#include <random>
template<class T> class myrand
{
	std::mt19937* pmt;
	std::uniform_int_distribution<T>* pdist;
public:
	myrand(T const min, T const max);
	myrand(float const min, float const max) = delete;
	T get_rnd();
	~myrand();
};


template<> class myrand <double>
{
	std::mt19937* pmt;
	std::uniform_int_distribution<double>* pdist;
public:
	myrand(double const min, double const max);
	double get_rnd();
	~myrand();
};


