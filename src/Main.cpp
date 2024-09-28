#include <iostream>

#include "State.h"
#include "KroneckerProduct.h"

namespace Gate
{
	Matrix Hadamard(unsigned int n, unsigned int i)
	{
		if (n == 1)
		{
			// POW_2(1) = 2
			Matrix h (2, 2);
			const Real x = 1.0 / std::sqrt(2.0);
			h << x,  x,
				 x, -x;
			return h;
		}
		else
		{
			const Matrix id = Matrix::Identity(2, 2);
			Matrix r = i == 0 ? Hadamard(1, 0) : id;

			// for an n qubit system, there are n - 1 operations needed on n operands
			for (unsigned int j = 0; j < n - 1; j++)
			{
				if (j + 1 == i)
				{
					r = KroneckerProduct(Hadamard(1, 0), r);
				}
				else
				{
					r = KroneckerProduct(id, r);
				}
			}

			return r;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	// std complex test
	//Complex c = std::sqrt(0.5) + 1i * std::sqrt(0.5);
	//std::cout << "c: " << c << std::endl;

	if (true)
	{
		// hadamard gate test
		
		// iterate number of qubits
		for (unsigned int n = 1; n <= 6; n++)
		{
			// iterate (BINARY!) starting configurations
			for (unsigned int i = 0; i < POW_2(n); i++)
			{
				// iterate which qubit to apply the hadamard gate / operation to
				for (unsigned int j = 0; j < n; j++)
				{
					std::cout << "\nn: " << n << ", i: " << i << ", j: " << j << "\n";

					State s (n, i);
					s.ApplyMatrix(Gate::Hadamard(n, j));
					
					// verify
					const Real p = s.ProbSum();

					if (std::abs(p - 1.0) > 0.05)
					{
						std::cout << "Warning: Probability sum is not equal to 1, p: " << p << std::endl;
					}

					Real p0 = s.SingleQubitProb(j, false);
					Real p1 = s.SingleQubitProb(j, true);

					if (std::abs(p0 - 0.5) > 0.05 || std::abs(p1 - 0.5) > 0.05)
					{
						std::cout << "Warning: p0 and / or p1 are not equal to 1/2. p0: " << p0 << ", " << p1 << std::endl;
						std::cout << s << std::endl;
					}
				}
			}
		}
	}
	
	if (false)
	{
		std::cout << "Applying NAND\n" << std::endl;
		State s (3, 0b000);
	
		Matrix nand = Matrix::Constant(POW_2(3), POW_2(3), Complex(0.0));
		nand(0, 1) = 1;
		nand(1, 0) = 1;

		nand(2, 3) = 1;
		nand(3, 2) = 1;

		nand(4, 5) = 1;
		nand(5, 4) = 1;

		nand(6, 6) = 1;
		nand(7, 7) = 1;

		//std::cout << "NAND:\n" << nand << std::endl;

		s.ApplyMatrix(nand);
		std::cout << s << std::endl;
	}


	// terminate
	std::cout << "\nFinished." << std::endl;
	std::cin.get();
}