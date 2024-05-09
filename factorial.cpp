#include <iostream>
#include <cmath>
#include "factorial.h"
using namespace std;

#include <stdexcept>

int main(int argc, char* argv[]) { 
    try {
        float input_number;
        cin >> input_number;
        float result = factorial(input_number);
        cout << result << endl;
        return 0;
    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
        return 1;
    }
}
