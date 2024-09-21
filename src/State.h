#pragma once

#include <vector>

#include <iostream>
#include <ostream>
#include <format>
#include <iomanip>

#include "Types.h"



class State
{
private:
	unsigned int m_N;
	std::vector<Complex> m_Psi;

public:
	State(unsigned int n);

	Real Prob(const Complex c) const
	{
		return std::pow(std::abs(c), 2.0);
	}
	Real ProbSum() const;

	void ApplyMatrix(const Matrix& u, const std::vector<unsigned int>& qubits);

public:
	friend std::ostream& operator<< (std::ostream& os, const State& s);
};