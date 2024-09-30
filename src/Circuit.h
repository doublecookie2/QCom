#pragma once

#include <queue>
#include <memory>

#include "Gates.h"
#include "State.h"

class Circuit
	: public State
{
private:
	std::queue<std::unique_ptr<Gate>> m_Gates;
public:
	Circuit(unsigned int n, unsigned int init = 0);

	void Add(Gate* gate);
	void Step();
	void Run();
};

