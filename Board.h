#include "./TerminalManager.h"
#include "./Tetromino.h"

class Board {
public:
  // Konstruktor
  Board(int width, int height);

  // Zeichnet das Spielfeld mit allen liegenden Tetrominos (cells) und dem
  // fallenden Tetromino (current)
  void draw(TerminalManager tm);

  // Prüft ob eine Reihe komplett ist, entfernt sie und rückt die
  // darüberliegenden Reihen nach unten
  void removeFullRows();
  // Erzeugt ein neues Tetromino und platzier es
  void placeTetromino();

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
