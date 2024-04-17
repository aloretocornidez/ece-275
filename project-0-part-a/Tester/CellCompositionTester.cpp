/*
 * CellCompositionTester.cpp
 *
 *  Created on: Sep 28, 2020
 *      Author: connorfuhrman
 */


#include "CellCompositionTester.hpp"
#include <random>
#include <iostream>

BOOST_AUTO_TEST_CASE(test_cell_no_public_color)
{
	BOOST_TEST_MESSAGE("Testing that Cell has no public member of color");
	// Check that Cell has no public color
	BOOST_CHECK_MESSAGE(not has_public_color(Cell{}),
        "Test failed because color must be a private member but is known to be public!");
}

BOOST_AUTO_TEST_CASE(test_cell_private_color)
{
	BOOST_TEST_MESSAGE("Testing that Cell has a private member of color");
	// Check that Cell has a private color
	BOOST_CHECK_MESSAGE(has_private_color(Cell{}),
        "Test failed because color must be a private member but is known to be public!");
}
