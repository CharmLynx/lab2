#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <fstream>

using namespace std;

#include "factorial.h" 

BOOST_AUTO_TEST_CASE(TestFactorial) {
    BOOST_CHECK_EQUAL(factorial(0), 1);
    BOOST_CHECK_EQUAL(factorial(1), 1);
    BOOST_CHECK_EQUAL(factorial(5), 120);
}
BOOST_AUTO_TEST_CASE(TestNegativeNumber) {
    BOOST_CHECK_THROW(factorial(-1), invalid_argument);
}
BOOST_AUTO_TEST_CASE(TestNonInteger) {
    BOOST_CHECK_THROW(factorial(3.5), invalid_argument);
}
BOOST_AUTO_TEST_CASE(TestStdinReading) {
    istringstream input("5\n");
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    int number;
    cin >> number;
    BOOST_TEST(number == 5);
    cin.rdbuf(old_cin);
}
BOOST_AUTO_TEST_CASE(TestStdoutOutput) {
    ostringstream output;
    streambuf* old_stdout = cout.rdbuf(output.rdbuf());
    factorial(5);
    cout.rdbuf(old_stdout);
    BOOST_CHECK_EQUAL(stoi(output.str()), 120);
}
BOOST_AUTO_TEST_CASE(TestStderrOutput) {
    system("./factorial 3.5 2> error_output.txt");
    ifstream error_file("error_output.txt");
    BOOST_CHECK(error_file.good());
    BOOST_CHECK(!error_file.eof());
}
BOOST_AUTO_TEST_CASE(TestNonZeroExitCodeOnError) {
    int exit_code;
    exit_code = system("./factorial 3.5");
    BOOST_CHECK_NE(exit_code, 0);
}
BOOST_AUTO_TEST_CASE(TestZeroExitCodeOnSuccess) {
    factorial(5);
    int exit_code = system("echo $?");
    BOOST_CHECK_EQUAL(exit_code, 0);
}