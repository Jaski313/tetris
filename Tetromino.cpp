#include "./Tetromino.h"
#include <iostream>
#include <vector>

Tetromino::Tetromino(int type, int row, int col) {
  position_.y = row;
  position_.x = col;
  type_ = type;
  color_ = TETROMINOS[type].color;
  if (type >= 0 && type < TETROMINOS.size()) {
    for (int i = 0; i < 4; i++) {
      // copy shape from TETROMINOS to shape_ vector
      std::vector<int> row;
      for (int j = 0; j < 4; j++) {
        row.push_back(TETROMINOS[type].shape[i][j]);
      }
      shape_.push_back(row);
    }
  }
}

int Tetromino::getType() { return type_; }

void Tetromino::rotateRight() {

  switch (type_) {
  case 0:
    if (shape_[0][2] == 1) {
      shape_ = {{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    } else {
      shape_ = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}};
    }
    break;
  case 1:
    return;
  case 3:
    if (shape_[0][1] == 1) {
      shape_ = {{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}};
    } else {
      shape_ = {{0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    }
    break;
  case 4:
    if (shape_[0][2] == 0) {
      shape_ = {{0, 0, 1, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}};
    } else {
      shape_ = {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 1, 0, 0}};
    }
    break;
  case 2:
  case 5:
  case 6:
    int tempMatrixSmall[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        tempMatrixSmall[i][j] = shape_[i][j];
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        shape_[i][j] = tempMatrixSmall[2 - j][i];
      }
    }
    break;
  }
}

void Tetromino::rotateLeft() {
  rotateRight();
  rotateRight();
  rotateRight();
}

int Tetromino::getPixel(int row, int col) {
  if (row < 0 || row >= 4 || col < 0 || col >= 4) {
    return -1;
  }
  return shape_[row][col];
}

void Tetromino::logShape() {
  if (type_ != 0 && type_ != 1) {
    // log 3x3
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (shape_[i][j] == 0) {
          std::cout << "░░";
          continue;
        } else {
          std::cout << "██";
        }
      }
      std::cout << std::endl;
    }
  } else {
    // log 4x4
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (shape_[i][j] == 0) {
          std::cout << "░░";
          continue;
        } else {
          std::cout << "██";
        }
      }
      std::cout << std::endl;
    }
  }
}

void Tetromino::moveLeft() { position_.y--; }
void Tetromino::moveRight() { position_.y++; }
void Tetromino::moveDown() { position_.x++; }
int Tetromino::getRow() { return position_.x; }
int Tetromino::getCol() { return position_.y; }
int Tetromino::getColor() { return color_; }
std::vector<std::vector<int>> Tetromino::getShape() { return shape_; }