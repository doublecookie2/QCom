#include <iostream>

#include "State.h"

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

	// state test
	State s (1);
	std::cout << s << std::endl;

	std::cout << "Applying Hadamard operation\n" << std::endl;
	Matrix h (2, 2);
	h(0, 0) =  1.0;
	h(0, 1) =  1.0;
	h(1, 0) =  1.0;
	h(1, 1) = -1.0;

	h = h * (1.0 / std::sqrt(2.0));
	std::cout << "h:\n" << h << std::endl;

	s.ApplyMatrix(h, {0});

	std::cout << s << std::endl;

	std::cout << "\nFinished." << std::endl;
	std::cin.get();
}