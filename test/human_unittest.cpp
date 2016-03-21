#include "../src/Human.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

TEST(HumanTest, HumanCharTest) {
	Board b(10,10);
    UniverseSTL u(b,1);
    Human h(u,0,0,0);
    u.add(&h);
	EXPECT_EQ('H', h.ch());
}
