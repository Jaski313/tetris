
#include "./Tetromino.h"
#include <gtest/gtest.h>

// Test für die rotate Funktion
TEST(TetrisTest, rotate) {
  Tetromino t(0);
  t.rotateRight();
  // Testet ob die Rotation funktioniert
  ASSERT_EQ(t.getPixel(0, 0), 0);
  ASSERT_EQ(t.getPixel(1, 0), 0);
  ASSERT_EQ(t.getPixel(2, 0), 0);
  ASSERT_EQ(t.getPixel(3, 0), 0);
  ASSERT_EQ(t.getPixel(0, 1), 0);
  ASSERT_EQ(t.getPixel(1, 1), 0);
  ASSERT_EQ(t.getPixel(2, 1), 0);
  ASSERT_EQ(t.getPixel(3, 1), 0);
  ASSERT_EQ(t.getPixel(0, 2), 1);
  ASSERT_EQ(t.getPixel(1, 2), 1);
  ASSERT_EQ(t.getPixel(2, 2), 1);
  ASSERT_EQ(t.getPixel(3, 2), 1);
  ASSERT_EQ(t.getPixel(0, 3), 0);
  ASSERT_EQ(t.getPixel(1, 3), 0);
  ASSERT_EQ(t.getPixel(2, 3), 0);
  ASSERT_EQ(t.getPixel(3, 3), 0);
}
int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}