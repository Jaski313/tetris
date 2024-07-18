
#include "./Tetromino.h"
#include <gtest/gtest.h>

// Test für die rotate Funktion
TEST(TetrisTest, rotate) {
  Tetromino t(0, 0, 0);
  t.rotateRight();
  // Testet ob die Rotation funktioniert
  std::vector<std::vector<int>> shape = t.getShape();
  ASSERT_EQ(shape[0][0], 0);
  ASSERT_EQ(shape[0][1], 0);
  ASSERT_EQ(shape[0][2], 1);
  ASSERT_EQ(shape[0][3], 0);
  ASSERT_EQ(shape[1][0], 0);
  ASSERT_EQ(shape[1][1], 0);
  ASSERT_EQ(shape[1][2], 1);
  ASSERT_EQ(shape[1][3], 0);
  ASSERT_EQ(shape[2][0], 0);
  ASSERT_EQ(shape[2][1], 0);
  ASSERT_EQ(shape[2][2], 1);
  ASSERT_EQ(shape[2][3], 0);
  ASSERT_EQ(shape[3][0], 0);
  ASSERT_EQ(shape[3][1], 0);
  ASSERT_EQ(shape[3][2], 1);
  ASSERT_EQ(shape[3][3], 0);
}
int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}