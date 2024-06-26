
#ifdef CPORTA
#include "gtest_lite.h"
#endif

#include <iostream>
#include "init.hpp"


int main(int argc, char** argv) {
	Game();
	SGL2::init();
#ifndef CPORTA
	try {
		InputManager();
		AssetManager();
		Game().Run();
	}
	catch (std::runtime_error e) {
		std::cout << std::endl << e.what() << std::endl;
	}
#endif

#ifdef CPORTA
	
	/*Test the gameobject getter*/
	g1& testobj = Game().GetGameObject<g1>("g1");
	TEST(Game_t, GetGameObject) { //also confirms that the game object getter is working
		EXPECT_EQ(testobj.GetId(), std::string("g1")/*convert to std::string to be sure*/);
	}END

	/*Test the gameobject getter exception*/
	TEST(Game_t, GetNonExistentGameObject) {
	EXPECT_THROW(
		Game().GetGameObject("object_with_this_id_does_not_exist"),
		std::runtime_error);
	}END

	/*Test the component getter*/
	c1& testcomp = testobj.GetComponent<c1>();
	TEST(GameObject, GetComponentByTypeOnly) {
		EXPECT_EQ(testcomp.GetId(), std::string("c1") /*the first component had the id "c1"*/);
	}END

	/*No component with type 'c2' is attached to 'testobj'*/
	TEST(GameObject, GetNonExistentComponentById) {
		EXPECT_THROW(testobj.GetComponent<c2>(), std::runtime_error);
	}END

	c1& testcomp_2 = testobj.GetComponent<c1>("c1");
	TEST(GameObject, GetComponentByIdAndName) {
		EXPECT_EQ(testcomp_2.GetId(), std::string("c1") /*the first component had the id "c1"*/);
	}END

	Vector2 v(0, 1);
	TEST(Vector2, Length) {
		EXPECT_DOUBLE_EQ(1.0, v.abs());
	}END

	Vector2 vn(1, 1);
	TEST(Vector2, Normalize) {
		EXPECT_DOUBLE_EQ(1.0 / sqrt(2), vn.normalized().x);
	}END

	Transform t = { Vector2(0, 0), Vector2(50, 100), 0 };
	
	TEST(Transform, Middle) {
		EXPECT_DOUBLE_EQ(t.Middle().x, 25.0);
		EXPECT_DOUBLE_EQ(t.Middle().y, 50.0);
	}END

	
#endif


	return 0;
}
