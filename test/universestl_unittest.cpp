#include "../src/Human.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class UniverseSTLTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h1 = new Human(*u, 0, 0, 0);
    h2 = new Human(*u, 0, 0, 0);
    u -> add(h1);
    u -> add(h2);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Human *h1, *h2;
};

TEST_F(UniverseSTLTest, CullingOrganismTest) {
    u -> killWeakestOrganismAt(0, 0);
    SUCCEED();
}
