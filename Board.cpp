#include "./Board.h"
#include "./Tetromino.h"
#include <cstdlib>
#include <time.h>

Board::Board(int width, int height) {
  int nextType = rand() % 7;
  srand(time(NULL));
  current_ = new Tetromino(nextType);
  nextType = rand() % 7;
  next_ = new Tetromino(nextType);
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
    delete current_;
  }
  current_ = next_;
  int nextType = rand() % 7;
  if (nextType == current_->getType()) {
    nextType = rand() % 7;
  }
  next_ = new Tetromino(nextType);
}

bool Board::checkIfCurrentTetrominoIsAtBottom(){
  return false;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(current_->getPixel(i, j) != 0){
        if(current_->getRow() + i >= height_ - 1){
          return true;
        }
      }
    }
  }
}

bool Board::checkIfCurrentTetrominoIsAtLeftBorder(){
  return false;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(current_->getPixel(i, j) != 0){
        if(current_->getCol() + j <= 0){
          return true;
        }
      }
    }
  }
}

bool Board::checkIfCurrentTetrominoIsAtRightBorder(){
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      if(current_->getPixel(i, j) != 0){
        if(current_->getCol() + j >= width_ - 1){
          return true;
        }
      }
    }
  }
}


// Getter und Setter
int Board::getWidth() { return width_; }
int Board::getHeight() { return height_; }
int Board::getPixel(int row, int col) { return cells_[row][col]; }
Tetromino *Board::getCurrent() { return current_; }
Tetromino *Board::getNext() { return next_; }

// cd develop/uni/sem2/cpp/jb1519/projekt