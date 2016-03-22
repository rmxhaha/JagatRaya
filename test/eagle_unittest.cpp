#include "../src/Eagle.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class EagleTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Eagle(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Eagle *h;
};

TEST_F(EagleTest, EagleCharTest) {
  EXPECT_EQ('E', h -> ch());
}