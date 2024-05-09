#include <iostream>
#include <cmath>
using namespace std;

#include <stdexcept>

int factorial(float n) {
    if (n < 0)
        throw invalid_argument("not defined for negative numbers");
    if (floor(n)!=n)
        throw invalid_argument("defined for integers only");
    if (n == 0)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

