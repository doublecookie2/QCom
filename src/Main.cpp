#include <iostream>

#include "Circuit.h"

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

//#define EXP_HADAMARD
#define EXP_BELL

#ifdef EXP_HADAMARD
	{
		Circuit c (3, 0b101);

		c.Add(new Hadamard(1));
		c.Add(new Hadamard(2));

		c.Run();
		c.Observe(20);
	}
#endif // EXP_HADAMARD

#ifdef EXP_BELL
	{
		Circuit c (2);

		c.Add(new Hadamard(0));
		c.Add(new CNOT(0, 1));

		c.Run();
		c.Observe(10);
		//std::cout << c << std::endl;
	}
#endif // EXP_BELL

	// terminate
	std::cout << "\nFinished." << std::endl;
	std::cin.get();
}