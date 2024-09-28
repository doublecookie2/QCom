#pragma once

#include <queue>

#include "Gates.h"
#include "State.h"

class Circuit
	: public State
{
private:
	std::queue<Gate> m_Gates;
public:
	Circuit(unsigned int n);

	void Add(const Gate& gate);
	void Step();
	void Run();
};

