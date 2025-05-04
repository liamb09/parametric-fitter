#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include "parametric.hpp"

using namespace std;

int main () {

    LagrangeParametric curve1({{1, 1}, {2, 2}, {4, 6}, {6, -1}, {0, 4}}, false);
    cout << "\n";
    LagrangeParametric curve2({{1, 1}, {2, 2}, {4, 6}, {6, -1}, {0, 4}}, true);
    cout << "\n";

    cout << curve1.toDesmosString() << "\n\n" << curve2.toDesmosString() << "\n";

}