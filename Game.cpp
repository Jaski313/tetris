#include "./Game.h"
#include <iostream>

const int *FRAMES_PER_GRIDCELL =
    new int[30]{48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 5, 5, 4, 4,
                4,  3,  3,  3,  2,  2,  2,  2,  2, 2, 2, 2, 2, 1};

void Game::drawInit(TerminalManager tm) {
  // draw gui border
  int windowHeight = tm.numRows();
  int windowWidth = tm.numCols();
  for (int i = 0; i < windowWidth; i++) {
    tm.drawPixel(0, i, 0);
    tm.drawPixel(windowHeight - 1, i, 0);
  }
  for (int i = 0; i < windowHeight; i++) {
    tm.drawPixel(i, 0, 0);
    tm.drawPixel(i, windowWidth - 1, 0);
  }
  // draw game board border at the middle
  for (int i = 0; i < board_.getHeight(); i++) {
    tm.drawPixel(i + 3, windowWidth / 2 - (board_.getWidth() + 2) / 2, 1);
    tm.drawPixel(i + 3, windowWidth / 2 + board_.getWidth() / 2, 1);
  }
  for (int i = 0; i < board_.getWidth() + 2; i++) {
    tm.drawPixel(2, windowWidth / 2 - board_.getWidth() / 2 + i - 1, 1);
    tm.drawPixel(board_.getHeight() + 3,
                 windowWidth / 2 - board_.getWidth() / 2 + i - 1, 1);
  }
  tm.refresh();
}
void Game::draw(TerminalManager tm) {
  int windowWidth = tm.numCols();

  // draw game board
  for (int i = 0; i < board_.getHeight(); i++) {
    for (int j = 0; j < board_.getWidth(); j++) {

      tm.drawPixel(i + 3, windowWidth / 2 - board_.getWidth() / 2 + j,
                   board_.getPixel(i, j));
    }
  }
  // draw current
  if (board_.getCurrent() != nullptr) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int pixelValue = board_.getCurrent()->getPixel(i, j);
        if (pixelValue > 0) {
          tm.drawPixel(board_.getCurrent()->getRow() + i + 3,
                       (windowWidth / 2) - (board_.getWidth() / 2) +
                           board_.getCurrent()->getCol() + j,
                       board_.getCurrent()->getColor());
        }
      }
    }
  }

  // draw next
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int pixelValue = board_.getNext()->getPixel(i, j);
      tm.drawPixel(i + 3, windowWidth / 2 + board_.getWidth() / 2 + j + 2, 0);
      if (pixelValue > 0) {
        tm.drawPixel(i + 3, windowWidth / 2 + board_.getWidth() / 2 + j + 2,
                     board_.getNext()->getColor());
      }
    }
  }
}

void Game::step() {
  if (board_.getCurrent() == nullptr) {
    board_.placeTetromino();
  } else {
    // check if tetrio is at the bottom or on top of another tetrio
    if (board_.checkIfCurrentTetrominoIsAtBottom()) {
      board_.placeTetromino();
    } else {
      board_.getCurrent()->moveDown();
    }
  }
}

bool Game::computeUserInput(UserInput input) {
  if (input.isKeyLeft() && !board_.checkIfCurrentTetrominoIsAtLeftBorder()) {
    board_.getCurrent()->moveLeft();
    return true;
  } else if (input.isKeyRight() &&
             !board_.checkIfCurrentTetrominoIsAtRightBorder()) {
    board_.getCurrent()->moveRight();
    return true;
  } else if (input.keycode_ == int('s')) {
    board_.getCurrent()->rotateRight();
    return true;
  } else if (input.isKeyDown() && !board_.checkIfCurrentTetrominoIsAtBottom()) {

    board_.getCurrent()->moveDown();

    return true;
  }
  return false;
}
// Getter und Setter
int Game::getLevel() { return level_; }

int Game::getScore() { return score_; }

void Game::setLevel(int level) { level_ = level; }

void Game::setScore(int score) { score_ = score; }
