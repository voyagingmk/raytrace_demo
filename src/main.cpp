#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"

TEST_CASE( "Vector base usages", "[Vector]" ) {
	Vector v1(0,0,0);
	Vector v2(v1);
	Vector v3(-1,-1,-1);
	Vector v4(1,1,1);
	REQUIRE( v1 == v2 );
	REQUIRE( v3 + v4 == v2 );
	REQUIRE( v3 == -v4 );
	REQUIRE( v3 * -5 == -v4 * 5 );
}
