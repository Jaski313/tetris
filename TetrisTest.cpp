
#include "./Game.h"
#include <gtest/gtest.h>

// Tests für die Tetromino Klasse
// ----------------------------------------------

// Test für den Tetromino Konstruktor
TEST(TetrominoTest, constructor) {
  Tetromino t(0, 0, 0);
  ASSERT_EQ(t.getType(), 0);
  std::vector<std::vector<int>> shape = t.getShape();
  std::vector<std::vector<int>> initialShape = {
      {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, initialShape);
  ASSERT_EQ(t.getColor(), 2);
  ASSERT_EQ(t.getRow(), 0);
  ASSERT_EQ(t.getCol(), 0);
}

// Test für die rotate Funktion
TEST(TetrominoTest, rotate) {
  // Form 0
  Tetromino t0(0, 0, 0);
  t0.rotateRight();
  std::vector<std::vector<int>> shape = t0.getShape();
  std::vector<std::vector<int>> rotatedShape = {
      {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t0.rotateRight();
  shape = t0.getShape();
  rotatedShape = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t0.rotateRight();
  shape = t0.getShape();
  rotatedShape = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 1
  Tetromino t1(1, 0, 0);
  t1.rotateRight();
  shape = t1.getShape();
  rotatedShape = {{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 2
  Tetromino t2(2, 0, 0);
  t2.rotateRight();
  shape = t2.getShape();
  rotatedShape = {{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t2.rotateRight();
  shape = t2.getShape();
  rotatedShape = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t2.rotateRight();
  shape = t2.getShape();
  rotatedShape = {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t2.rotateRight();
  shape = t2.getShape();
  rotatedShape = {{0, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 3
  Tetromino t3(3, 0, 0);
  t3.rotateRight();
  shape = t3.getShape();
  rotatedShape = {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t3.rotateRight();
  shape = t3.getShape();
  rotatedShape = {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 4
  Tetromino t4(4, 0, 0);
  t4.rotateRight();
  shape = t4.getShape();
  rotatedShape = {{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t4.rotateRight();
  shape = t4.getShape();
  rotatedShape = {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 5
  Tetromino t5(5, 0, 0);
  t5.rotateRight();
  shape = t5.getShape();
  rotatedShape = {{1, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t5.rotateRight();
  shape = t5.getShape();
  rotatedShape = {{0, 0, 1, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t5.rotateRight();
  shape = t5.getShape();
  rotatedShape = {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // Form 6
  Tetromino t6(6, 0, 0);
  t6.rotateRight();
  shape = t6.getShape();
  rotatedShape = {{0, 1, 0, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t6.rotateRight();
  shape = t6.getShape();
  rotatedShape = {{1, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);
  t6.rotateRight();
  shape = t6.getShape();
  rotatedShape = {{0, 1, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
  ASSERT_EQ(shape, rotatedShape);

  // ein rotateLeft() test ist überflüssig, da rotateLeft() nur rotateRight()
  // dreimal aufruft und rotateRight() oben getestet wird
}

// Test für die move Funktionen
TEST(TetrominoTest, move) {
  Tetromino t(0, 0, 0);
  t.moveDown();
  ASSERT_EQ(t.getRow(), 1);
  ASSERT_EQ(t.getCol(), 0);

  t.moveRight();
  ASSERT_EQ(t.getRow(), 1);
  ASSERT_EQ(t.getCol(), 1);

  t.moveLeft();
  ASSERT_EQ(t.getRow(), 1);
  ASSERT_EQ(t.getCol(), 0);
}

// Test für die getPixel Funktion
TEST(TetrominoTest, getPixel) {
  Tetromino t(0, 0, 0);
  std::vector<std::vector<int>> initialShape = {
      {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(t.getPixel(i, j), initialShape[i][j]);
    }
  }
}

// Tests für die Board Klasse
// ----------------------------------------------

// Test für den Board Konstruktor
TEST(BoardTest, constructor) {
  Board b(10, 20);
  ASSERT_EQ(b.getWidth(), 10);
  ASSERT_EQ(b.getHeight(), 20);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(b.getPixel(i, j), 0);
    }
  }
  Tetromino *current = b.getCurrent();
  Tetromino *next = b.getNext();
  ASSERT_NE(current, nullptr);
  ASSERT_NE(next, nullptr);
}

// Test für die placeTetromino Funktion
TEST(BoardTest, placeTetromino) {
  Board b(10, 20);
  Tetromino *current = b.getCurrent();
  Tetromino *next = b.getNext();
  ASSERT_NE(current, nullptr);
  ASSERT_NE(next, nullptr);
  b.placeTetromino();
  ASSERT_NE(b.getCurrent(), current);
  ASSERT_NE(b.getNext(), next);
}

// Test für die countFullRowsAndDelete Funktion
TEST(BoardTest, countFullRowsAndDelete) {
  Board b(10, 20);
  for (int i = 0; i < 10; i++) {
    for (int j = 16; j < 20; j++) {
      b.setPixel(j, i, 1);
    }
  }
  ASSERT_EQ(b.countFullRowsAndDelete(), 4);
  for (int i = 0; i < 10; i++) {
    for (int j = 16; j < 20; j++) {
      ASSERT_EQ(b.getPixel(j, i), 0);
    }
  }
}

// Test für die isAtBottom Funktion
TEST(BoardTest, isAtBottom) {
  Board b(10, 20);
  Tetromino t(0, 0, 0);
  b.setCurrent(&t);
  for (int i = 0; i < 17; i++) {
    ASSERT_FALSE(b.isAtBottom());
    t.moveDown();
  }
  ASSERT_TRUE(b.isAtBottom());
}

// Test für die canMoveRight Funktion
TEST(BoardTest, canMoveRight) {
  Board b(10, 20);
  Tetromino t(0, 0, 0);
  b.setCurrent(&t);
  for (int i = 0; i < 5; i++) {
    t.moveRight();
    ASSERT_TRUE(b.canMoveRight());
  }
  t.moveRight();
  ASSERT_FALSE(b.canMoveRight());
}

// Test für die canMoveLeft Funktion
TEST(BoardTest, canMoveLeft) {
  Board b(10, 20);
  Tetromino t(0, 5, 0);
  b.setCurrent(&t);
  for (int i = 0; i < 4; i++) {
    t.moveLeft();
    ASSERT_TRUE(b.canMoveLeft());
  }
  t.moveLeft();
  ASSERT_FALSE(b.canMoveLeft());
}

// Test für die canRotate Funktion
TEST(BoardTest, canRotate) {
  Board b(10, 20);
  Tetromino t(0, 0, 0);
  b.setCurrent(&t);
  ASSERT_TRUE(b.canRotate());
  t.rotateRight();
  t.moveLeft();
  ASSERT_FALSE(b.canRotate());
}

// Test für die setPixel Funktion
TEST(BoardTest, setPixel) {
  Board b(10, 20);
  b.setPixel(0, 0, 1);
  ASSERT_EQ(b.getPixel(0, 0), 1);
}

// Tests für die Game Klasse
// ----------------------------------------------

// Test für den Konstruktor
TEST(GameTest, constructor) {
  Game g(std::vector<int>(0));
  ASSERT_EQ(g.getLevel(), 0);
  ASSERT_EQ(g.getScore(), 0);
  ASSERT_EQ(g.isGameOver(), false);
}

// Test für setter und getter
TEST(GameTest, getterAndSetter) {
  Game g(std::vector<int>(0));
  g.setLevel(1);
  ASSERT_EQ(g.getLevel(), 1);
  g.setScore(20);
  ASSERT_EQ(g.getScore(), 20);
  g.setScore(0);
  ASSERT_EQ(g.getScore(), 0);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}