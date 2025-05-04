#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "lagrange.hpp"

using namespace std;

LagrangePolynomial::LagrangePolynomial() : points({}) {}
LagrangePolynomial::LagrangePolynomial(const vector<pair<float, float>> &initPoints) : points(initPoints) {}

float LagrangePolynomial::evaluate(const float &x) {
    float result;

    for (int i = 0; i < points.size(); i++) {
        // Calculate each basis polynomial at x
        float basisPolynomialSubtotal = points[i].second;
        for (int k = 0; k < points.size(); k++) {
            if (i != k) {
                basisPolynomialSubtotal *= (x - points[k].first)/(points[i].first - points[k].first);
            }
        }
        result += basisPolynomialSubtotal;
    }

    return result;
}

void LagrangePolynomial::setPoints (const vector<pair<float, float>> &newPoints) {
    points = newPoints;
}

void LagrangePolynomial::addPoint (const pair<float, float> &newPoint) {
    points.push_back(newPoint);
}

string LagrangePolynomial::toDesmosString (const string &iv) {  // iv = independent variable
    string result;
    for (int i = 0; i < points.size(); i++) {
        result += to_string(points[i].second);
        for (int k = 0; k < points.size(); k++) {
            if (i != k) {
                result += "\\cdot\\frac{" + iv + "-" + to_string(points[k].first) + "}{" + to_string(points[i].first - points[k].first) + "}";
            }
        }
        if (i != points.size()-1) {
            result += "+";
        }
    }
    return result;
}