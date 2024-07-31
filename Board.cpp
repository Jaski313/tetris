#include "./Board.h"
#include "./Tetromino.h"
#include <cstdlib>
#include <time.h>

Board::Board(int width, int height) {
  width_ = width;
  height_ = height;
  // initialisierung des Spielfelds (alles auf 0)
  for (int i = 0; i < height; i++) {
    std::vector<int> row;
    for (int j = 0; j < width; j++) {
      row.push_back(0);
    }
    cells_.push_back(row);
  }
  // seeding der random funktion
  srand(time(NULL));
  // generierung der ersten tetrominos
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
  // übernehme die Werte des aktuellen Tetrominos in das Spielfeld
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
  // generierung des nächsten Tetrominos
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

bool Board::isAtBottom() const {
  // überprüfe ob das tetromino am boden ist
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (current_->getPixel(i, j) != 0) {
        if (current_->getRow() + i >= height_ - 1) {
          return true;
        }
      }
      // überprüfe ob das tetromino auf einem anderen liegt
      if (current_->getPixel(i, j) != 0) {
        if (cells_[current_->getRow() + i + 1][current_->getCol() + j] != 0) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Board::canMoveRight() const {
  // überprüfe ob das tetromino sich nach rechts bewegen kann
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

bool Board::canMoveLeft() const {
  // überprüfe ob das tetromino sich nach links bewegen kann
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

bool Board::canRotate() const {
  // überprüfe ob sich das tetromino rotieren kann
  // erstelle eine Kopie des Tetrominos und rotiere diese um dann zu prüfen ob
  // es sich an einer validen position und ausrichtung befindet
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
  // zähle volle Reihen und lösche sie
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
int Board::getWidth() const { return width_; }
int Board::getHeight() const { return height_; }
int Board::getPixel(int row, int col) const { return cells_[row][col]; }
void Board::setPixel(int row, int col, int color) { cells_[row][col] = color; }
Tetromino *Board::getCurrent() const { return current_; }
Tetromino *Board::getNext() const { return next_; }
void Board::setCurrent(Tetromino *t) { current_ = t; }
