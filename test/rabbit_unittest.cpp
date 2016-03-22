#include "../src/Rabbit.hpp"
#include "../src/UniverseSTL.hpp"
#include "gtest/gtest.h"

class RabbitTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    b = new Board(10, 10);
    u = new UniverseSTL(*b, 1);
    h = new Rabbit(*u, 0, 0, 0);
    u -> add(h);
  }

  // virtual void TearDown() {}

  Board *b;
  UniverseSTL *u;
  Rabbit *h;
};

TEST_F(RabbitTest, RabbitCharTest) {
  EXPECT_EQ('R', h -> ch());
}