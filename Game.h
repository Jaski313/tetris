#include "./Board.h"
#include "./TerminalManager.h"

// Frames pro GridCell für die Taktung
extern const int *FRAMES_PER_GRIDCELL;

class Game {
public:
  // Konstruktor
  Game() : board_(10, 22), score_(0), currentDeletedRows_(0), level_(0) {}

  // Lässt das Spiel laufen
  void step();

  void drawInit(TerminalManager tm);
  // Zeichnet das Spielfeld
  void draw(TerminalManager tm);

  // Handled den UserInput (Tetromino verschieben rotieren | verlassen des
  // Spiels)
  bool computeUserInput(UserInput input);
  // Getter und Setter
  void setLevel(int level);
  int getLevel();
  void setScore(int score);
  int getScore();

private:
  // Spielfeld
  Board board_;

  // Aktuelle punktzahl
  int score_;

  // Aktuelle Anzahl der gelöschten Reihen (wichtig für die Berechnung des
  // Levels)
  int currentDeletedRows_;

  // Aktuelles Level
  int level_;
};