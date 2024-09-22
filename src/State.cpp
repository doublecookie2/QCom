#include "State.h"

#include <numeric>

State::State(unsigned int n, unsigned int init)
	: m_N(n), m_Psi()
{
	m_Psi = Vector::Constant(static_cast<size_t>(1) << n, Complex(0.0));
	m_Psi[init] = Complex(1.0, 0.0);
}

Real State::ProbSum() const
{
	return std::accumulate(m_Psi.begin(), m_Psi.end(), 0.0, 
		[this](Real s, Complex c) { return s + Prob(c); });
}

void State::ApplyMatrix(const Matrix& m)
{
	m_Psi = m * m_Psi;
}

unsigned int State::Collapse()
{
	Real s = 0.0;

	for (unsigned int i = 0; i < m_Psi.size(); i++)
	{

	}

	// this point should not get reached,
	// as long as the probability sum is 1
	return 0;
}


std::ostream& operator<<(std::ostream& os, const State& s)
{
	std::cout << "State (" << s.m_N << ", " << s.m_Psi.size() << "):\n";

	std::cout << "\tpsi = ";
	for (unsigned int i = 0; i < s.m_Psi.size(); i++)
	{
		//std::setw(s.m_N + 4)
		os << s.Prob(s.m_Psi[i]) << std::format("|{:b}>", i) 
			<< std::string(i == s.m_Psi.size() - 1 ? "" : " + ");
	}
	const Real p = s.ProbSum();
	std::cout << "\n\tProbability sum: " << p << "\n";

	if (std::abs(p - 1.0) > 0.05)
	{
		std::cout << "Warning: Probability sum is not equal to 1" << std::endl;
	}

	for (unsigned int i = 0; i < s.m_Psi.size(); i++)
	{
		os << "\t" << std::format("{:b}: ", i) << s.m_Psi[i] << std::endl;
	}

	return os;
}