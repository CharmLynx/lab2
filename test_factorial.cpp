#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>

#include "factorial.h" 

BOOST_AUTO_TEST_CASE(TestFactorial) {
    BOOST_CHECK_EQUAL(factorial(0), 1);
    BOOST_CHECK_EQUAL(factorial(1), 1);
    BOOST_CHECK_EQUAL(factorial(5), 120);
}

BOOST_AUTO_TEST_CASE(TestNegativeNumber) {
    BOOST_CHECK_THROW(factorial(-1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TestNonInteger) {
    BOOST_CHECK_THROW(factorial(3.5), std::invalid_argument);
}
