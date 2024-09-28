#include "Circuit.h"

Circuit::Circuit(unsigned int n)
	: State(n), m_Gates()
{
}

void Circuit::Add(Gate* gate)
{
	m_Gates.emplace(gate);
}

void Circuit::Step()
{
	ApplyMatrix(m_Gates.front()->GetMatrix(m_N));
	m_Gates.pop();
}

void Circuit::Run()
{
	while (!m_Gates.empty())
	{
		Step();
	}
}
