#include "KroneckerProduct.h"

Matrix KroneckerProduct(const Matrix& a, const Matrix& b)
{
	const size_t ar = a.rows();
	const size_t ac = a.cols();
	const size_t br = b.rows();
	const size_t bc = b.cols();

	Matrix c (ar * br, ac * bc);

	for (size_t i = 0; i < ar; i++)
	{
	for (size_t j = 0; j < ac; j++)
	{
	for (size_t k = 0; k < br; k++)
	{
	for (size_t l = 0; l < bc; l++)
	{
		c(i * br + l, j * bc + k) = a(i, j) * b(k, l);
	}
	}
	}
	}

	return c;
}
