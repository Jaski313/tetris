#include "./Board.h"
#include "./TerminalManager.h"

// Frames pro GridCell für die Taktung
extern const int *FRAMES_PER_GRIDCELL;

// Klasse mit der Spiellogik
class Game {
public:
  // Konstruktor
  Game(std::vector<int> highscores_)
      : board_(10, 22), score_(0), currentDeletedRows_(0), level_(0),
        gameOver_(false), highscores_(highscores_) {}

  // Destruktor
  ~Game();

  // Lässt das Spiel laufen (ein schritt)
  void step();

  // Zeichnet den permanenten Teil des spielfelds
  void drawInit(TerminalManager tm) const;
  // Zeichnet das Spielfeld
  void draw(TerminalManager tm) const;

  // Zeichne GameOver Screen
  void drawGameOver(TerminalManager tm) const;

  // Schreibe NEW HIGHSCORE auf den Bildschirm
  void drawNewHighscore(TerminalManager tm) const;

  // Handled den UserInput (Tetromino verschieben rotieren | verlassen des
  // Spiels)
  bool computeUserInput(UserInput input);

  // Getter und Setter
  void setLevel(int level);
  int getLevel() const;
  void setScore(int score);
  int getScore() const;
  bool isGameOver() const;
  Board getBoard() const;
  void setRotateRightKey(int key);
  void setRotateLeftKey(int key);

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

  // wahrheitswert ob das Spiel vorbei ist
  bool gameOver_;

  // Tasten für die Rotation
  int rotateRightKey_ = int('s');
  int rotateLeftKey_ = int('a');

  // aktuelle Highscores
  std::vector<int> highscores_;
};