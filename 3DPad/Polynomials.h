#pragma once

#include <QObject>

class Polynomials : public QObject
{
	Q_OBJECT

public:
	Polynomials(QObject *parent);
	~Polynomials();
	inline double CubicPolynomialRoot(const double p, const double q, const double r);
	inline int QuadraticPolynomialRootsGeneric(const float a, const float b, const float c, float& r0, float& r1);
	inline int CubicPolynomialRootsGeneric(float* roots, const double a, const double b, const double c, const double d);
	inline float QuadraticPolynomialRoot(const float a, const float b, const float c);
};
