/*
 * CellCompositionTester.hpp
 *
 *  Created on: Sep 28, 2020
 *      Author: connorfuhrman
 */

#ifndef TESTER_CELLCOMPOSITIONTESTER_HPP_
#define TESTER_CELLCOMPOSITIONTESTER_HPP_

#define BOOST_TEST_MODULE CellCompositionTester
#define BOOST_TEST_LOG_LEVEL message
#include "Cell.hpp"
#include <boost/test/included/unit_test.hpp>

// Check that cell color is a private member
template<typename T>
auto has_public_color(T &t) -> decltype(t.color, true)
{
	// Returns true if Cell has a public member named color
    return true;
}
auto has_public_color(...)
{
    return false;
}
template<typename T>
auto has_private_color(T &t) -> decltype(t.color, true)
{
	// Returns false if Cell has a private member named color
    return false;
}
auto has_private_color(...)
{
    return true;
}




#endif /* TESTER_CELLCOMPOSITIONTESTER_HPP_ */
