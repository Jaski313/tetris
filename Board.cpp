#include "./Board.h"
#include "./Tetromino.h"
#include <cstdlib>
#include <time.h>

Board::Board(int width, int height) {
  int nextType = rand() % 7;
  srand(time(NULL));
  current_ = new Tetromino(nextType, width / 2, 0);
  ;
  nextType = rand() % 7;
  next_ = new Tetromino(nextType, width / 2, 0);
  ;
  width_ = width;
  height_ = height;
  for (int i = 0; i < height; i++) {
    std::vector<int> row;
    for (int j = 0; j < width; j++) {
      row.push_back(0);
    }
    cells_.push_back(row);
  }
}

void Board::placeTetromino() {
  if (current_ != nullptr) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (current_->getPixel(i, j) != 0) {
          cells_[current_->getRow() + i][current_->getCol() + j] =
              current_->getColor();
        }
      }
    }
    countFullRowsAndDelete();
    delete current_;
  }
  current_ = next_;
  int nextType = rand() % 7;
  if (nextType == current_->getType()) {
    nextType = rand() % 7;
  }
  next_ = new Tetromino(nextType, width_ / 2, 0);
}

bool Board::checkIfCurrentTetrominoIsAtBottom() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getRow() + i >= height_ - 1) {
          return true;
        }
      }
      // check if tetromino hits other tetromino
      if (current_->getPixel(i, j) != 0) {
        if (cells_[current_->getRow() + i + 1][current_->getCol() + j] != 0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Board::checkIfCurrentTetrominoIsAtLeftBorder() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getCol() + j <= 0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Board::checkIfCurrentTetrominoIsAtRightBorder() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getCol() + j >= width_ - 1) {
          return true;
        }
      }
    }
  }
  return false;
}

int Board::countFullRowsAndDelete() {
  int count = 0;
  for (int i = 0; i < height_; i++) {
    bool full = true;
    for (int j = 0; j < width_; j++) {
      if (cells_[i][j] == 0) {
        full = false;
        break;
      }
    }
    if (full) {
      count++;
      for (int k = i; k > 0; k--) {
        for (int l = 0; l < width_; l++) {
          cells_[k][l] = cells_[k - 1][l];
        }
      }
    }
  }
  return count;
}

// Getter und Setter
int Board::getWidth() { return width_; }
int Board::getHeight() { return height_; }
int Board::getPixel(int row, int col) { return cells_[row][col]; }
Tetromino *Board::getCurrent() { return current_; }
Tetromino *Board::getNext() { return next_; }

// cd develop/uni/sem2/cpp/jb1519/projekt