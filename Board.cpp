#include "./Board.h"
#include "./Tetromino.h"
#include <cstdlib>
#include <time.h>

Board::Board(int width, int height) {
  width_ = width;
  height_ = height;

  for (int i = 0; i < height; i++) {
    std::vector<int> row;
    for (int j = 0; j < width; j++) {
      row.push_back(0);
    }
    cells_.push_back(row);
  }

  srand(time(NULL));
  int nextType = rand() % 7;
  if (nextType == 0) {
    current_ = new Tetromino(nextType, width_ / 2 - 2, 0);
  } else {
    current_ = new Tetromino(nextType, width_ / 2 - 2, 0);
  }
  nextType = rand() % 7;
  if (nextType == current_->getType()) {
    nextType = rand() % 7;
  }
  if (nextType == 0) {
    next_ = new Tetromino(nextType, width_ / 2, 0);
  } else {
    next_ = new Tetromino(nextType, width_ / 2, 1);
  }
}

bool Board::placeTetromino() {
  if (current_ != nullptr) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (current_->getPixel(i, j) != 0) {
          cells_[current_->getRow() + i][current_->getCol() + j] =
              current_->getColor();
        }
      }
    }
    delete current_;
  }
  current_ = next_;
  int nextType = rand() % 7;
  if (nextType == current_->getType()) {
    nextType = rand() % 7;
  }
  if (nextType == 0) {
    next_ = new Tetromino(nextType, width_ / 2 - 2, 0);
  } else {
    next_ = new Tetromino(nextType, width_ / 2 - 2, 1);
  }

  // check if current is at top
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (cells_[current_->getRow() + i][current_->getCol() + j] != 0) {
          current_ = nullptr;
          return false;
        }
      }
    }
  }
  return true;
}

bool Board::isAtBottom() {
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

bool Board::canMoveRight() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getCol() + j + 1 >= width_) {
          return false;
        }
        if (cells_[current_->getRow() + i][current_->getCol() + j + 1] != 0) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Board::canMoveLeft() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getCol() + j - 1 < 0) {
          return false;
        }
        if (cells_[current_->getRow() + i][current_->getCol() + j - 1] != 0) {
          return false;
        }
      }
    }
  }
  return true;
}

bool Board::canRotate() {
  Tetromino temp = *current_;
  temp.rotateRight();
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (temp.getPixel(i, j) != 0) {
        if (temp.getCol() + j >= width_ || temp.getCol() + j < 0) {
          return false;
        }
        if (temp.getRow() + i >= height_ || temp.getRow() + i < 0) {
          return false;
        }
        if (cells_[temp.getRow() + i][temp.getCol() + j] != 0) {
          return false;
        }
      }
    }
  }
  return true;
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