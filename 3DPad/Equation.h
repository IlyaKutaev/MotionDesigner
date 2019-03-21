#ifndef Equation_h__
#define Equation_h__

#pragma once
#include <QObject>
#include <qglobal.h>
#include <Pad_Numeric.h>

template <typename FactorType, int Degree>
class Equation
{
public:
	FactorType a = 0, b = 0, c = 0, d = 0;
	FactorType root0 = 0, root1 = 0, root2 = 0, root3 = 0;
public:
	Equation();
	virtual ~Equation();
	virtual void Solve() = 0;
};

template <typename FactorType, int Degree>
Equation<FactorType, Degree>::~Equation()
{

}

template <typename FactorType, int Degree>
Equation<FactorType, Degree>::Equation()
{

}

#endif // Equation_h__
