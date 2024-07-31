#include "./TerminalManager.h"

class Highscore {
public:
  Highscore();

  // fügt einen neuen Highscore hinzu und sortiert die Liste
  void updateHighscores(int score);

  // läd die Highscores aus der Datei
  void loadHighscores();

  // schreibt die Highscores auf den Bildschirm
  void renderHighscores(TerminalManager tm) const;

  // schreibt die Highscores in die Konsole (debbuging)
  void logHighscores() const;

  // gibt den aktuellen Highscore zurück
  std::vector<int> getHighscores() const;

private:
  // Liste der Highscores
  std::vector<int> highscores_;
  // Datei in der die Highscores gespeichert/geladen werden
  const std::string file_ = "highscores.txt";
};
