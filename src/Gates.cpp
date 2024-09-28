#include "Gates.h"

#include "KroneckerProduct.h"

Matrix Hadamard::GetMatrix(const unsigned int n) const
{
	// POW_2(1) = 2
	Matrix h (2, 2);
	const Real x = 1.0 / std::sqrt(2.0);
	h << x,  x,
		x, -x;

	const Matrix id = Matrix::Identity(2, 2);
	Matrix r = m_I == 0 ? h : id;

	// for an n qubit system, there are n - 1 operations needed on n operands
	// if n == 1, simply h is returned
	for (unsigned int j = 0; j < n - 1; j++)
	{
		if (j + 1 == m_I)
		{
			r = KroneckerProduct(h, r);
		}
		else
		{
			r = KroneckerProduct(id, r);
		}
	}

	return r;
}

Matrix CNOT::GetMatrix(const unsigned int n) const
{
	Matrix m = Matrix::Constant(POW_2(n), POW_2(n), 0.0);

	for (unsigned int i = 0; i < POW_2(n); i++)
	{
		if (bool(i & (1 << m_C)))
		{
			m(i, i ^ (1 << m_T)) = 1;
		}
		else
		{
			m(i, i) = 1;
		}
	}

	return m;
}