#include "./Game.h"
#include <cstring>
#include <iostream>
#include <string>

// Frames pro GridCell für die Taktung
const int *FRAMES_PER_GRIDCELL =
    new int[30]{48, 43, 38, 33, 28, 23, 18, 13, 8, 6, 5, 5, 5, 4, 4,
                4,  3,  3,  3,  2,  2,  2,  2,  2, 2, 2, 2, 2, 1};

Game::~Game() {
  delete[] FRAMES_PER_GRIDCELL;
  FRAMES_PER_GRIDCELL = nullptr;
}

void Game::drawInit(TerminalManager tm) const {
  // zeichne gui border
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
  // zeichne game board border in der mitte
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
void Game::draw(TerminalManager tm) const {
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
  tm.drawString(6, windowWidth / 2 + board_.getWidth() / 2 + 2, 1, "Next: ");
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      int pixelValue = board_.getNext()->getPixel(i, j);
      tm.drawPixel(i + 7, windowWidth / 2 + board_.getWidth() / 2 + j + 4, 0);
      if (pixelValue > 0) {
        tm.drawPixel(i + 7, windowWidth / 2 + board_.getWidth() / 2 + j + 4,
                     board_.getNext()->getColor());
      }
    }
  }

  // draw level and score
  tm.drawString(3, windowWidth / 2 + board_.getWidth() / 2 + 2, 1, "Level: ");
  tm.drawString(3, windowWidth / 2 + board_.getWidth() / 2 + 9, 1,
                (std::to_string(level_).data()));

  tm.drawString(4, windowWidth / 2 + board_.getWidth() / 2 + 2, 1, "Score: ");
  tm.drawString(4, windowWidth / 2 + board_.getWidth() / 2 + 9, 1,
                (std::to_string(score_).data()));

  if (score_ > highscores_[0]) {
    tm.drawString(15, windowWidth / 2 - 15, 1, "NEW HIGHSCORE!");
  }
}

void Game::drawGameOver(TerminalManager tm) const {
  int windowWidth = tm.numCols();
  int windowHeight = tm.numRows();
  for (int i = 0; i < windowWidth; i++) {
    for (int j = 0; j < windowHeight; j++) {
      tm.drawPixel(j, i, 0);
    }
  }

  // definiere ein "logo" für den gameover screen
  int logoright[5][5] = {{0, 0, 0, 4, 0},
                         {0, 0, 0, 4, 4},
                         {0, 0, 0, 4, 7},
                         {0, 0, 6, 6, 7},
                         {0, 6, 6, 7, 7}};
  int logoleft[5][5] = {{2, 2, 2, 2, 0},
                        {8, 8, 5, 5, 0},
                        {8, 5, 5, 0, 0},
                        {8, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0}};
  int green[2][2] = {{3, 3}, {3, 3}};

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tm.drawPixel(windowHeight / 2 - 5 + i, windowWidth / 2 + 7 + j,
                   green[i][j]);
    }
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      tm.drawPixel(windowHeight / 2 - 5 + i, windowWidth / 2 - 10 + j,
                   logoleft[i][j]);
      tm.drawPixel(windowHeight / 2 + 1 + i, windowWidth / 2 + 4 + j,
                   logoright[i][j]);
    }
  }

  tm.drawString(windowHeight / 2, windowWidth / 2 - 4, 1, "GAME OVER");

  tm.drawString(windowHeight / 2 + 3, windowWidth / 2 - 4, 1, "Score: ");
  tm.drawString(windowHeight / 2 + 3, windowWidth / 2 + 2, 1,
                (std::to_string(score_).data()));

  if (score_ > highscores_[0]) {
    tm.drawString(windowHeight / 2 + 1, windowWidth / 2 - 4, 1,
                  "NEW HIGHSCORE!");
  }

  tm.refresh();
}

void Game::step() {
  if (board_.getCurrent() == nullptr) {
    board_.placeTetromino();
  } else {
    // check if tetrio is at the bottom or on top of another tetrio
    if (board_.isAtBottom()) {
      if (board_.placeTetromino() == false) {
        gameOver_ = true;
      }
      // berechnng des scores
      int deletedRows = board_.countFullRowsAndDelete();
      currentDeletedRows_ = currentDeletedRows_ + deletedRows;

      switch (deletedRows) {
      case 1:
        score_ = score_ + 40 * (level_ + 1);
        break;
      case 2:
        score_ = score_ + 100 * (level_ + 1);
        break;
      case 3:
        score_ = score_ + 300 * (level_ + 1);
        break;
      case 4:
        score_ = score_ + 1200 * (level_ + 1);
        break;
      }
      // berechnung des levels
      if (currentDeletedRows_ >= 10) {
        level_++;
        currentDeletedRows_ = currentDeletedRows_ - 10;
      }
    } else {
      board_.getCurrent()->moveDown();
    }
  }
}

bool Game::computeUserInput(UserInput input) {
  // switch case für die verschiedenen user eingaben
  if (input.isKeyLeft() && board_.canMoveLeft()) {
    board_.getCurrent()->moveLeft();
    return true;
  } else if (input.isKeyRight() && board_.canMoveRight()) {
    board_.getCurrent()->moveRight();
    return true;
  } else if (input.keycode_ == (rotateRightKey_) && board_.canRotate()) {
    board_.getCurrent()->rotateRight();
    return true;
  } else if (input.keycode_ == (rotateLeftKey_) && board_.canRotate()) {
    board_.getCurrent()->rotateLeft();
    return true;
  } else if (input.isKeyDown() && !board_.isAtBottom()) {
    board_.getCurrent()->moveDown();
    score_ = score_ + 1;
    return true;
  }
  return false;
}
// Getter und Setter
int Game::getLevel() const { return level_; }
int Game::getScore() const { return score_; }
bool Game::isGameOver() const { return gameOver_; }
void Game::setLevel(int level) { level_ = level; }
void Game::setScore(int score) { score_ = score; }
Board Game::getBoard() const { return board_; }
void Game::setRotateRightKey(int key) { rotateRightKey_ = key; }
void Game::setRotateLeftKey(int key) { rotateLeftKey_ = key; }
