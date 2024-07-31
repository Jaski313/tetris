#include "./TerminalManager.h"
#include "./Tetromino.h"

class Board {
public:
  // Konstruktor
  Board(int width, int height);

  // zählt volle Reihen und löscht sie
  int countFullRowsAndDelete();
  // Erzeugt ein neues Tetromino und platzier das alte auf dem Spielfeld
  bool placeTetromino();

  // gibt zurück ob der aktuelle Tetromino am Boden ist oder auf einen anderen
  // stößt
  bool isAtBottom() const;

  // funktionen zum überprüfen ob das tetromino sich bewegen oder rotieren kann
  bool canMoveRight() const;
  bool canMoveLeft() const;
  bool canRotate() const;

  // Getter und Setter
  int getWidth() const;
  int getHeight() const;
  int getPixel(int row, int col) const;
  void setPixel(int row, int col, int color);
  Tetromino *getCurrent() const;
  Tetromino *getNext() const;
  void setCurrent(Tetromino *t);

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
