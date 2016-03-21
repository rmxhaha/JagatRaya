#include "../src/board.hpp"
#include "gtest/gtest.h"

TEST(BoardTest, DimensionTest) {
	Board b(5,6);
	EXPECT_EQ(5, b.GetW());
	EXPECT_EQ(6, b.GetH());
}

TEST(BoardTest, ElementTest) {
	Board b(5,6);
	EXPECT_EQ("", b.GetEl(2, 3));
	b.SetEl('d', 2, 3);
	EXPECT_EQ("d", b.GetEl(2, 3));
	b.SetEl('s', 2, 3);
	b.SetEl('a', 2, 3);
	EXPECT_EQ("dsa", b.GetEl(2, 3));
	b.DelEl('s', 2, 3);
	EXPECT_EQ("da", b.GetEl(2, 3));
}