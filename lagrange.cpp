#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "lagrange.hpp"

LagrangePolynomial::LagrangePolynomial() : points({}), coefficients({}) {}
LagrangePolynomial::LagrangePolynomial(const std::vector<std::pair<double, double>> &initPoints) : points(initPoints) {
    
}

double LagrangePolynomial::evaluate(const double &x) {
    double result;

    for (int i = 0; i < (int) points.size(); i++) {
        double basisPolynomialSubtotal = points[i].second;
        for (int k = 0; k < (int) points.size(); k++) {
            if (i != k) {
                basisPolynomialSubtotal *= (x - points[k].first)/(points[i].first - points[k].first);
            }
        }
        result += basisPolynomialSubtotal;
    }

    return result;
}