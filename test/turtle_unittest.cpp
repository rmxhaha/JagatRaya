#include "../src/Turtle.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class TurtleTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Turtle(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Turtle *h;
};

TEST_F(TurtleTest, TurtleCharTest) {
  EXPECT_EQ('U', h -> ch());
}
