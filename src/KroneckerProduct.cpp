#include "KroneckerProduct.h"

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
