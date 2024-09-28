#pragma once

#include "Types.h"

class Gate
{
public:
	Gate() = default;
	virtual Matrix GetMatrix(const unsigned int n) const
	{
		__debugbreak();
		return Matrix::Constant(POW_2(n), POW_2(n), 0.0);
	};
};

class Hadamard
	: public Gate
{
public:
	Hadamard(unsigned int i)
		:  Gate(), m_I(i) {}
	Matrix GetMatrix(const unsigned int n) const;
private:
	unsigned int m_I;
};

/*
Flips the t-th bit (target bit) if the c-th bit (control bit) is set
00 -> 00
01 -> 01
10 -> 11
11 -> 10
*/

class CNOT
	: public Gate
{
public:
	CNOT(unsigned int c, unsigned int t)
		: Gate(), m_C(c), m_T(t) {}
	Matrix GetMatrix(const unsigned int n) const;
private:
	unsigned int m_C, m_T;
};


