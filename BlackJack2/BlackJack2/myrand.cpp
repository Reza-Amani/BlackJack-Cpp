#include "pch.h"
#include "myrand.h"


template<class T> myrand<T>::myrand(T const min, T const max)
{
	std::random_device rd;
	pmt = new std::mt19937(rd());
	pdist = new std::uniform_int_distribution<T>(min, max);
}

template<class T> T myrand<T>::get_rnd()
{
	return pdist(*pmt);
}


template<> myrand<double>::myrand(double const min, double const max)
{
	std::random_device rd;
	pmt = new std::mt19937(rd());
	pdist = new std::uniform_double_distribution<double>(min, max);
}

template<> double myrand<double>::get_rnd()
{
	return pdist(*pmt);
}


