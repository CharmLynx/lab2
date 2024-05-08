#include <iostream>
#include <cmath>
using namespace std;

#include <stdexcept>

int factorial(int n) {
    if (n < 0)
        throw invalid_argument("not defined for negative numbers.");
    if (floor(n)!= n)
        throw invalid_argument("defined for integers only");

    if (n == 0)
        return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    try {
        int input_number;
        cin >> input_number;
        int result = factorial(input_number);
        cout << result << endl;
        return 0;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
