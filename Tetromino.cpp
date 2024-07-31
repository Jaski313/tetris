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
      // übertage die Werte des Tetrominos aus dem array in den shape vektor
      std::vector<int> row;
      for (int j = 0; j < 4; j++) {
        row.push_back(TETROMINOS[type].shape[i][j]);
      }
      shape_.push_back(row);
    }
  }
}

void Tetromino::rotateRight() {
  // switch case für die verschiedenen Formen
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
      shape_ = {{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
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
  // rotation nach links entspricht 3 rotationen nach rechts
  rotateRight();
  rotateRight();
  rotateRight();
}

int Tetromino::getPixel(int row, int col) const {
  // gibt den Wert des Pixels an der Stelle row, col zurück (mit test ob die
  // eingabe nicht out of bounds ist)
  if (row < 0 || row >= 4 || col < 0 || col >= 4) {
    return -1;
  }
  return shape_[row][col];
}

void Tetromino::logShape() const {
  // funktion zum debuggen
  if (false) {
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

// Getter und Setter
void Tetromino::moveLeft() { position_.y--; }
void Tetromino::moveRight() { position_.y++; }
void Tetromino::moveDown() { position_.x++; }
int Tetromino::getRow() const { return position_.x; }
int Tetromino::getCol() const { return position_.y; }
int Tetromino::getColor() const { return color_; }
std::vector<std::vector<int>> Tetromino::getShape() const { return shape_; }
int Tetromino::getType() const { return type_; }
