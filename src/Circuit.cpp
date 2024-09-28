#include "Circuit.h"

Circuit::Circuit(unsigned int n)
	: State(n), m_Gates()
{
}

void Circuit::Add(const Gate& gate)
{
	m_Gates.push(gate);
}

void Circuit::Step()
{
	ApplyMatrix(m_Gates.front().GetMatrix());
	m_Gates.pop();
}

void Circuit::Run()
{
	while (!m_Gates.empty())
	{
		Step();
	}
}
