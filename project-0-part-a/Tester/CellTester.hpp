/*
 * CellTester.hpp
 *
 *  Created on: Sep 27, 2020
 *      Author: connorfuhrman
 */

#ifndef TESTER_CELLTESTER_HPP_
#define TESTER_CELLTESTER_HPP_

#include <random>
#include <iostream>

#define BOOST_TEST_MODULE CellTester
#define BOOST_TEST_LOG_LEVEL message

#define private public
#include "Cell.hpp"
#undef private

#include <boost/test/included/unit_test.hpp>



#endif /* TESTER_CELLTESTER_HPP_ */
