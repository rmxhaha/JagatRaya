#include "../src/Race.hpp"
#include "../src/RaceState.hpp"
#include "gtest/gtest.h"

class RaceTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    r = new Race(1, 1, 4, 4);
  }

  // virtual void TearDown() {}

  Race *r;
};

TEST_F(RaceTest, InitialConditionTest) {
	EXPECT_EQ(RaceState::RECRUITMENT, r -> getState());
}
