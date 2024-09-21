#include "State.h"

#include <numeric>

State::State(unsigned int n)
	: m_N(n), m_Psi(size_t(1) << n, Complex(0.0))
{
	m_Psi[0] = Complex(1.0, 0.0);
}

Real State::ProbSum() const
{
	return std::accumulate(m_Psi.begin(), m_Psi.end(), 0.0, 
		[this](Real s, Complex c) { return s + Prob(c); });
}

void State::ApplyMatrix(const Matrix& m, const std::vector<unsigned int>& qubits)
{
	Vector v;
	v.resize(m_Psi.size());
	for (unsigned int i = 0; i < v.size(); i++)
	{
		v[i] = m_Psi[i];
	}

	std::cout << v << std::endl;

	const Vector u = m * v;
	std::cout << u << std::endl;

	for (unsigned int i = 0; i < u.size(); i++)
	{
		m_Psi[i] = u[i];
	}
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