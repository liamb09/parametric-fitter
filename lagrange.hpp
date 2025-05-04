#ifndef LAGRANGE_HPP
#define LAGRANGE_HPP

#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

class LagrangePolynomial {

    vector<pair<float, float>> points;

public:
    LagrangePolynomial ();
    LagrangePolynomial (const vector<pair<float, float>> &initPoints);

    float evaluate (const float &x);
    void setPoints (const vector<pair<float, float>> &newPoints);
    void addPoint (const pair<float, float> &newPoint);

    string toDesmosString (const string &iv); // iv = independent variable

};

#endif