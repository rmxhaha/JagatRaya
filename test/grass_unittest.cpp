#include "../src/Grass.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class GrassTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Grass(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Grass *h;
};

TEST_F(GrassTest, GrassCharTest) {
  EXPECT_EQ('G', h -> ch());
}