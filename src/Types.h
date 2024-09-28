
// https://en.cppreference.com/w/cpp/numeric/complex
#include <complex>
using namespace std::complex_literals;

#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

using Real		= double;
using Complex	= std::complex<double>;
using Matrix	= Eigen::Matrix<Complex, Eigen::Dynamic, Eigen::Dynamic>;
using Vector	= Eigen::Vector<Complex, Eigen::Dynamic>;

#define POW_2(n) (1 << n)