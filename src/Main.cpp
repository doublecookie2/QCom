#include <iostream>

#include "Circuit.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	Circuit c(2);

	c.Add(new Hadamard(0));
	c.Add(new CNOT(0, 1));

	c.Run();
	std::cout << c << std::endl;

	// terminate
	std::cout << "\nFinished." << std::endl;
	std::cin.get();
}