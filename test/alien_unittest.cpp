#include "../src/Alien.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class AlienTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Alien(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Alien *h;
};

TEST_F(AlienTest, AlienCharTest) {
  EXPECT_EQ('@', h -> ch());
}
