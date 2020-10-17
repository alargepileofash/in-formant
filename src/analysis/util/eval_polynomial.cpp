#include "util.h"

void Analysis::evaluatePolynomialWithDerivative(const std::vector<double>& poly, const double x, double *y, double *dy)
{
    double p = poly[poly.size() - 1];
    double dp = 0.0f;

    for (int i = poly.size() - 1; i >= 0; --i) {
        dp = dp * x + p;
        p = p * x + poly[i];
    }

    *y = p;
    *dy = dp;
}

void Analysis::evaluatePolynomialWithDerivative(const std::vector<double>& poly, const std::complex<double>& z, std::complex<double> *y, std::complex<double> *dy)
{
    std::complex<double> p = poly[poly.size() - 1];
    std::complex<double> dp = 0.0f;

    for (int i = poly.size() - 1; i >= 0; --i) {
        dp = dp * z + p;
        p = p * z + poly[i];
    }
    
    *y = p;
    *dy = dp;
}

std::vector<std::complex<double>> Analysis::evaluatePolynomialDerivatives(const std::vector<std::complex<double>>& poly, const std::complex<double>& x, int numberOfDerivatives)
{
    const int degree = poly.size() - 1;
    std::vector<std::complex<double>> derivatives(numberOfDerivatives + 1);
    numberOfDerivatives = numberOfDerivatives > degree ? degree : numberOfDerivatives;

    derivatives[0] = poly[poly.size() - 1];

    for (int i = degree - 1; i >= 0; --i) {
        const int n = numberOfDerivatives < degree - i ? numberOfDerivatives : degree - i;
        for (int j = n; j >= 1; --j) {
            derivatives[j] = derivatives[j] * x + derivatives[j - 1];
        }
        derivatives[0] = derivatives[0] * x + poly[i];
    }

    double fact = 1.0;
    for (int j = 2; j <= numberOfDerivatives; ++j) {
        fact *= j;
        derivatives[j] *= fact;
    }
    return derivatives;
}
