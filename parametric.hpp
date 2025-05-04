#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "lagrange.hpp"

using namespace std;

class LagrangeParametric {

    LagrangePolynomial xt;
    LagrangePolynomial yt;
    float endT;

    public:
        LagrangeParametric(const vector<pair<float, float>> &initPoints, const bool &accountForDistance);
        LagrangeParametric(const LagrangePolynomial &initxt, const LagrangePolynomial &inityt);

        pair<float, float> evaluate (const float &t);
        void addPoint(const float &t, const pair<float, float> &newPoint);

        string toDesmosString ();
};