#include "../src/OrganismList.hpp"
#include "gtest/gtest.h"

class OrganismListTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    o = new OrganismList();
  }

  // virtual void TearDown() {}

  OrganismList *o;
};

TEST_F(OrganismListTest, InitialConditionTest) {
	EXPECT_EQ(NULL, o -> begin());
	EXPECT_EQ(NULL, o -> end());
	EXPECT_EQ(0, o -> size());
}
