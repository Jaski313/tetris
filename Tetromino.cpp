#include "./Tetromino.h"
#include <iostream>
#include <vector>

Tetromino::Tetromino(int type) : position_{0, 0} {
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
  // check if tetromino is square
  if (type_ == 1) {
    return;
  }

  // check if tetromino is 3x3
  if (type_ != 0) {
    // rotate 3x3
    int tempMatrix[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        tempMatrix[i][j] = shape_[i][j];
      }
    }
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        shape_[i][j] = tempMatrix[2 - j][i];
      }
    }
  } else {
    int tempMatrix[4][4];

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tempMatrix[i][j] = shape_[i][j];
      }
    }
    // log 4x4 matrix
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        std::cout << tempMatrix[i][j] << " ";
      }
      std::cout << std::endl;
    }
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        shape_[i][j] = tempMatrix[3 - j][i];
      }
    }
    // log 4x4 matrix rotated
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        std::cout << shape_[i][j] << " ";
      }
      std::cout << std::endl;
    }
  }
}

int Tetromino::getPixel(int x, int y) {
  if (x < 0 || x >= 4 || y < 0 || y >= 4) {
    return -1;
  }
  return shape_[x][y];
}

void Tetromino::moveLeft() { position_.y--; }
void Tetromino::moveRight() { position_.y++; }
void Tetromino::moveDown() { position_.x++; }
int Tetromino::getRow() { return position_.x; }
int Tetromino::getCol() { return position_.y; }
int Tetromino::getColor() { return color_; }