#include <stdio.h>
#define CATCH_CONFIG_MAIN
#include "base.hpp"
#include "catch.hpp"
#include "vector.hpp"
#include "renderer.hpp"
#include "sphere.hpp"
#include "perspectivecamera.hpp"
#include "material.hpp"
#include "color.hpp"


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

	cil::CImg<unsigned char> img(300,300,1,3);
	//printf("%s",img.data());
	Renderer renderer;
	/*
	PtrSphere sphere = std::make_shared<Sphere>(std::make_shared<Vector>(0,10,-10),10);

	PerspectiveCamera camera(std::make_shared<Vector>(0, 10, 10),
                          std::make_shared<Vector>(0, 0, -1),
                          std::make_shared<Vector>(0, 1, 0),
                          90);
	renderer.renderNormal(img, *sphere, camera, 20);
	*/
	PtrSphere sphere = std::make_shared<Sphere>(std::make_shared<Vector>(-10,10,-10),10);

	PerspectiveCamera camera(std::make_shared<Vector>(0, 5, 15),
                          std::make_shared<Vector>(0, 0, -1),
                          std::make_shared<Vector>(0, 1, 0),
                          90);
	std::shared_ptr<PhongMaterial> pMat = std::make_shared<PhongMaterial>(Color::Red, Color::White, 16);
	sphere->setMaterial(std::static_pointer_cast<Material>(pMat));
	renderer.rayTrace(img, *sphere, camera);


	img.display("");
	//REQUIRE( (v4.normalize() - Vector(10,10,10).normalize())==Vector(0,0,0));
}
