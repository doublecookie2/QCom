#pragma once

#include <vector>
#include <string>

#include <iostream>
#include <ostream>
#include <format>
#include <iomanip>

#include "Types.h"

class State
{
private:
	unsigned int m_N;
	Vector m_Psi;

public:
	State(unsigned int n, unsigned int init = 0);

	Real Prob(const Complex c) const
	{
		return std::pow(std::abs(c), 2.0);
	}
	Real ProbSum() const;

	void ApplyMatrix(const Matrix& m);

	unsigned int Collapse();
public:
	friend std::ostream& operator<< (std::ostream& os, const State& s);
};