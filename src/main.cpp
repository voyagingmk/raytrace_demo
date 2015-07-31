#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector.hpp"

TEST_CASE( "Vector base usages", "[Vector]" ) {
    printf("==========\n");
	Vector v1(0,0,0);
	Vector v2(v1);
	REQUIRE( v1 == v2 );
	printf("===\n");
    Vector v3(-1,-1,-1);
	Vector v4(1,1,1);
	REQUIRE( v3 + v4 == v2 );
	printf("===\n");
	REQUIRE( v3 + v4 + v3 + v4 == v2 );
	printf("===\n");
	Vector v10 = (v1 + v4);
	v10.debug();
	printf("===\n");
	REQUIRE( v3 == -v4 );
	printf("===\n");
	REQUIRE( -v3 * 5 == v4 * 5 );
	printf("===\n");
	REQUIRE( v1.cross(v3+v4) == v2.cross(v3+v4) );
	//REQUIRE( (v4.normalize() - Vector(10,10,10).normalize())==Vector(0,0,0));
}
