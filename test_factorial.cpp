#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <sstream>
#include <stdexcept>

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
    int exit_code = factorial_main();
    cin.rdbuf(old_cin);    
    BOOST_CHECK_EQUAL(exit_code, 0);
}
BOOST_AUTO_TEST_CASE(TestStdoutOutput) {
    istringstream input("5\n");
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    ostringstream output;
    streambuf* old_cout = cout.rdbuf(output.rdbuf());
    int exit_code = factorial_main();
    cin.rdbuf(old_cin);
    cout.rdbuf(old_cout);
    BOOST_CHECK_EQUAL(exit_code, 0);
    BOOST_CHECK_EQUAL(output.str(), "120\n");
}
BOOST_AUTO_TEST_CASE(TestStderrOutput) {
    istringstream input("-5\n");
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    ostringstream error_output;
    streambuf* old_cerr = cerr.rdbuf(error_output.rdbuf());
    int exit_code = factorial_main();
    cin.rdbuf(old_cin);
    cerr.rdbuf(old_cerr);
    BOOST_CHECK_NE(exit_code, 0);
    BOOST_CHECK_NE(error_output.str(), "");
}
BOOST_AUTO_TEST_CASE(TestNonZeroExitCodeOnError) {
    istringstream input("-5\n");
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    int exit_code = factorial_main();
    cin.rdbuf(old_cin);
    BOOST_CHECK_NE(exit_code, 0);
}
BOOST_AUTO_TEST_CASE(TestZeroExitCodeOnSuccess) {
    istringstream input("5\n");
    streambuf* old_cin = cin.rdbuf(input.rdbuf());
    int exit_code = factorial_main();
    cin.rdbuf(old_cin);
    BOOST_CHECK_EQUAL(exit_code, 0);
}