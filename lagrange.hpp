#include <iostream>
#include <utility>
#include <string>
#include <vector>

class LagrangePolynomial {

    std::vector<std::pair<double, double>> points;
    std::vector<double> coefficients;

public:
    LagrangePolynomial();
    LagrangePolynomial(const std::vector<std::pair<double, double>> &initPoints);

    double evaluate (const double &x);

};