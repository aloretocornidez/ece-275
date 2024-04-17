/*
 * CellTester.cpp
 *
 *  Created on: Sep 28, 2020
 *      Author: connorfuhrman
 */


#include "CellTester.hpp"

BOOST_AUTO_TEST_CASE ( test_construction )
{
	BOOST_TEST_MESSAGE("Testing that construction of Cell objects sets color to white");
	Cell* UnderTest = new Cell();
    bool passed = UnderTest -> color == white;
	BOOST_CHECK_MESSAGE(passed, "Test failed because 'color' was not set to 'white' on construction!");
    
}

BOOST_AUTO_TEST_CASE ( test_color_flip )
{
	BOOST_TEST_MESSAGE("Testing method to change cell color");
	Cell* UnderTest = new Cell();
	// Flip the color should give black now
	UnderTest -> change_color();
	BOOST_CHECK_MESSAGE(UnderTest -> color == black,
        "Test failed because constructing Cell and calling change color should " <<
        "toggle color to black");
	// Flip again and check that it becomes white
	UnderTest -> change_color();
	BOOST_CHECK_MESSAGE(UnderTest -> color == white,
        "Test failed because again calling change color should " <<
        "toggle color back to white");
}

BOOST_AUTO_TEST_CASE ( test_get_color_method )
{
	BOOST_TEST_MESSAGE("Testing method to get cell color");
	Cell* UnderTest = new Cell();
	// Test that get_color returns white
	BOOST_CHECK_MESSAGE(UnderTest -> get_color() == white and UnderTest -> color == white,
        "Test failed because constructing Cell and calling get_color should " <<
        "return white when color is white");
	// Flip the color should give black now
	UnderTest -> change_color();
	BOOST_CHECK_MESSAGE(UnderTest -> get_color() == black and UnderTest -> color == black,
        "Test failed because calling change_color and then calling get_color should " <<
        "return black when color is black");
	// Flip again and check that it becomes white
	UnderTest -> change_color();
	BOOST_CHECK_MESSAGE(UnderTest -> get_color() == white and UnderTest -> color == white,
        "Test failed because calling change_color 2x and then calling get_color should " <<
        "return white when color is white");
}

BOOST_AUTO_TEST_CASE ( test_get_color_string_method )
{
	BOOST_TEST_MESSAGE("Testing method to get cell color string identifier");
	Cell* UnderTest = new Cell();
	// Test that get_color returns white
	BOOST_CHECK_MESSAGE(UnderTest -> get_color_string() == "0" and UnderTest -> color == white,
        "Test failed becuse get_color_string should return '0' when color is white");

	// Flip the color should give black now
	UnderTest -> change_color();
	BOOST_CHECK_MESSAGE(UnderTest -> get_color_string() == "1" and UnderTest -> color == black,
        "Test failed becuse get_color_string should return '1' when color is black");
	
	// Flip again and check that it becomes white
	UnderTest -> change_color();
    BOOST_CHECK_MESSAGE(UnderTest -> get_color_string() == "0" and UnderTest -> color == white,
        "Test failed becuse get_color_string should return '0' when color is white");
}
