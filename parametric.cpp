#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include "parametric.hpp"
#include "lagrange.hpp"

using namespace std;

LagrangeParametric::LagrangeParametric(const vector<pair<float, float>> &initPoints, const bool &accountForDistance) {
    vector<pair<float, float>> xtPoints;
    vector<pair<float, float>> ytPoints;
    
    // Populate xtPoints and ytPoints according to initPoints
    float lastT, currentT = 0;
    for (int i = 0; i < initPoints.size(); i++) {
        currentT = i;
        // Make the t difference proportional to the distance between points (to maintain a constant resolution)
        if (i != 0 && accountForDistance) {
            currentT = lastT + sqrt(pow(initPoints[i].first - initPoints[i-1].first, 2) + pow(initPoints[i].second - initPoints[i-1].second, 2));
        }
        xtPoints.push_back({currentT, initPoints[i].first});
        ytPoints.push_back({currentT, initPoints[i].second});
        lastT = currentT;
    }
    if (accountForDistance) {
        endT = currentT;
    } else {
        endT = initPoints.size()-1;
    }
    cout << endT << "\n";

    for (int i = 0; i < xtPoints.size(); i++) {
        cout << "x=(" << xtPoints[i].first << ", " << xtPoints[i].second << ")   y=(" << ytPoints[i].first << ", " << ytPoints[i].second << ")\n";
    }

    xt.setPoints(xtPoints);
    yt.setPoints(ytPoints);
}

LagrangeParametric::LagrangeParametric (const LagrangePolynomial &initxt, const LagrangePolynomial &inityt) : xt(initxt), yt(inityt) {}

pair<float, float> LagrangeParametric::evaluate (const float &t) {
    return {xt.evaluate(t), yt.evaluate(t)};
}

void LagrangeParametric::addPoint(const float &t, const pair<float, float> &newPoint) {
    xt.addPoint({t, newPoint.first});
    yt.addPoint({t, newPoint.second});
}

string LagrangeParametric::toDesmosString () {
    return "(" + xt.toDesmosString("t") + "," + yt.toDesmosString("t") + ")";
}