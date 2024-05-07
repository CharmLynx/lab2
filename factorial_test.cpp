#include <iostream>
#include <stdexcept>

int factorial(int n);

int main() {
    try {
        int result = factorial(0);
        if (result != 1) {
            cerr << "Test failed: factorial(0) should return 1, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(0) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        int result = factorial(1);
        if (result != 1) {
            cerr << "Test failed: factorial(1) should return 1, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(1) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        int result = factorial(5);
        if (result != 120) {
            cerr << "Test failed: factorial(5) should return 120, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(5) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        int result = factorial(10);
        if (result != 3628800) {
            cerr << "Test failed: factorial(10) should return 3628800, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(10) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        int result = factorial(15);
        if (result != 1307674368000) {
            cerr << "Test failed: factorial(15) should return 1307674368000, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(15) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        int result = factorial(17);
        if (result != 355687428096000) {
            cerr << "Test failed: factorial(17) should return 355687428096000, but returned " << result << endl;
            return 1;
        }
    } catch (const exception& e) {
        cerr << "Test failed: factorial(17) should not throw an exception, but threw " << e.what() << endl;
        return 1;
    }

    try {
        factorial(-1);
        cerr << "Test failed: factorial(-1) should throw an exception, but did not." << endl;
        return 1;
    } catch (const invalid_argument& e) {
        
    } catch (...) {
        cerr << "Test failed: factorial(-1) should throw an invalid_argument exception, but threw a different exception." << endl;
        return 1;
    }

    return 0;
}
