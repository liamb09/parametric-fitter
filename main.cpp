#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "lagrange.hpp"

int main () {

    // std::pair<double, double> point1 = {1,1};
    // std::pair<double, double> point2 = {2,3};
    // std::pair<double, double> point3 = {3,2};

    // std::vector<int> coefficients = binomialExpansionCoefficients(6);
    // std::cout << intVectorToString(coefficients) << "\n";

    LagrangePolynomial xt({{0, 1}, {2, 5}, {4, 17}, {6, -1}});

    for (double i = 0; i <= 5; i += 0.5) {
        std::cout << i << ((int) i == i - 0.5 ? "" : "  ") << "  " << xt.evaluate(i) << "\n";
    }

}