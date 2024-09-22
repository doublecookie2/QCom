#include <iostream>

#include "State.h"

Matrix KroneckerProduct(const Matrix& a, const Matrix& b)
{
	const unsigned int ar = a.rows();
	const unsigned int ac = a.cols();
	const unsigned int br = b.rows();
	const unsigned int bc = b.cols();

	Matrix c(ar * br, ac * bc);

	for (unsigned int i = 0; i < ar; i++)
	{
		for (unsigned int j = 0; j < ac; j++)
		{
			for (unsigned int k = 0; k < br; k++)
			{
				for (unsigned int l = 0; l < bc; l++)
				{
					c(i * br + l, j * bc + k) = a(i, j) * b(k, l);
				}
			}
		}
	}

	return c;
}

int main()
{
	// std complex test
	Complex c = std::sqrt(0.5) + 1i * std::sqrt(0.5);
	std::cout << "c: " << c << std::endl;
	

	// Eigen matrix test
	Matrix m(2,2);

	m(0,0) = 3;
	m(1,0) = 2.5;
	m(0,1) = -1;
	m(1,1) = m(1,0) + m(0,1);

	std::cout << m << std::endl;

	{
		// state test
		State s (2, 0b00);
		std::cout << s << std::endl;

		std::cout << "Applying Hadamard gate\n" << std::endl;
		Matrix h (2, 2);
		h(0, 0) =  1.0;
		h(0, 1) =  1.0;
		h(1, 0) =  1.0;
		h(1, 1) = -1.0;
		h = h * (1.0 / std::sqrt(2.0));


		const Matrix i = Matrix::Identity(2, 2);

		const Matrix h0 = KroneckerProduct(h, i);
		const Matrix h1 = KroneckerProduct(i, h);

		//std::cout << "h:\n" << h << std::endl;
		std::cout << "h0:\n" << h0 << std::endl;
		std::cout << "h1:\n" << h1 << std::endl;


		//s.ApplyMatrix(h0);
		//std::cout << s << std::endl;

		s.ApplyMatrix(h1);
		std::cout << s << std::endl;
	}
	

	{
		std::cout << "Applying NAND\n" << std::endl;
		State s (3, 0b000);
	
		Matrix nand = Matrix::Constant(1 << 3, 1 << 3, Complex(0.0));
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

/*
string state, s; 
unsigned int r, j; 
state_map old = copy_map(states); 
amp c;

for (state_map::iterator i = old.begin(); i != old.end(); ++i) {
	//! Iterate psi
	
	state = i->first; s = "";
	
	//! s represents the states of qubits that the operation is going to be applied on
	for (unsigned int q : qubits)
		s += state[q];

	// Find which number basis element s corresponds to.
	r = binary_to_base10(s)


	for (j = 0; j < qubits.size(); j++)
	{
		if (j == r)
		{
			// set main diagonal
			states[state] -= (1.0 - u[j][r]) * old[state];
		}
		else
		{
			// set everything apart from the main diagonal
			string n = state;

			// j (int) -> k (string)
			// r (int) -> s (string)

			string k = binary_to_base10(j);
			for (unsigned int l = 0; l < k.size(); l++)
				n[qubits[l]] = k[l];

			states[n] += u[j][r] * old[state];
		}
	}
}

*/