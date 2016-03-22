#include "../src/Human.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class HumanTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Human(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Human *h;
};

TEST_F(HumanTest, HumanCharTest) {
	EXPECT_EQ('H', h -> ch());
}

TEST_F(HumanTest, HumanPowerTest) {
	EXPECT_EQ(1, h -> power());
}

TEST_F(HumanTest, HumanAgeTest) {
	EXPECT_EQ(500000, h -> age());
}
