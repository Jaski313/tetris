#include "./TerminalManager.h"
#include "./Tetromino.h"

class Board {
public:
  // Konstruktor
  Board(int width, int height);

  int countFullRowsAndDelete();
  // Erzeugt ein neues Tetromino und platzier es
  bool placeTetromino();

  bool isAtBottom();

  bool canMoveRight();
  bool canMoveLeft();

  bool canRotate();

  // Getter und Setter
  int getWidth();
  int getHeight();
  int getPixel(int x, int y);
  Tetromino *getCurrent();
  Tetromino *getNext();

private:
  // Maase des Spielfelds
  int width_;
  int height_;

  // aktueller Tetromino (fallender)
  Tetromino *current_;
  // nächster Tetromino
  Tetromino *next_;
  // Alle Pixel des Spielfelds(außer den Fallenden bewegbaren Tetromino) als
  // Farben
  std::vector<std::vector<int>> cells_;
};
