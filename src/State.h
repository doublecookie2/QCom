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
	friend Circuit;

	unsigned int m_N;
	Vector m_Psi;

public:
	State(unsigned int n, unsigned int init = 0);

	inline Real Prob(const Complex c) const
	{
		return std::pow(std::abs(c), 2.0);
	}

	Real ProbSum() const;
	Real SingleQubitProb(unsigned int i, bool b = true) const;

	void ApplyMatrix(const Matrix& m);
	void Observe(const unsigned int n = 1);


	// outside access, mostly for testing purposes
	inline const Vector& Psi() const { return m_Psi; }
	inline Real Prob(unsigned int i) const
	{
		return Prob(m_Psi[i]);
	}

	inline unsigned int N() const { return m_N; }

public:
	void CollapseTo(const unsigned int result);
	unsigned int GetWeightedRandom();

	friend std::ostream& operator<< (std::ostream& os, const State& s);
};