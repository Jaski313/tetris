
#include "./Game.h"
#include "./Highscore.h"
#include "./TerminalManager.h"
#include <chrono>
#include <iostream>
#include <string>
#include <unistd.h>

// Initialisierung der Farben
Color red(1.0f, 0.0f, 0.0f);
Color green(0.0f, 1.0f, 0.0f);
Color blue(0.0f, 0.0f, 1.0f);
Color yellow(1.0f, 1.0f, 0.0f);
Color cyan(0.0f, 1.0f, 1.0f);
Color magenta(1.0f, 0.0f, 1.0f);
Color orange(1.0f, 0.647f, 0.0f);
Color purple(0.5f, 0.0f, 0.5f);
Color white(1.0f, 1.0f, 1.0f);
Color black(0.0f, 0.0f, 0.0f);

int main(int argc, char *argv[]) {
  TerminalManager tm({{black, black},
                      {white, black},
                      {red, black},
                      {green, black},
                      {blue, black},
                      {yellow, black},
                      {cyan, black},
                      {magenta, black},
                      {orange, black},
                      {purple, black}});
  Highscore highscore;
  Game game(highscore.getHighscores());

  if (argc == 2) {
    // ./TetrisMain Level
    game.setLevel(std::stoi(argv[1]));
  } else if (argc == 4) {
    // ./TetrisMain Level RotateRightKey RotateLeftKey
    game.setLevel(std::stoi(argv[1]));
    game.setRotateRightKey(int(argv[2][0]));
    game.setRotateLeftKey(int(argv[3][0]));
  }
  game.drawInit(tm);
  highscore.renderHighscores(tm);
  const int FPS = 60;
  const int MS_PER_FRAME = 1000 / FPS;
  auto lastFrameTime = std::chrono::steady_clock::now();

  // Taktung des Spiels: Falls die aktuelle Zeit - die Zeit des letzten Frames
  // größer ist als die Zeit die ein Frame dauern soll, dann wird das Spiel
  // geupdatet und gezeichnet
  while (true) {
    auto currentTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(
        currentTime - lastFrameTime);
    int msPerGridCell =
        FRAMES_PER_GRIDCELL[game.getLevel()] *
        MS_PER_FRAME; // evt noch anpassen damit nicht jedesmal gerechnet wird

    if (elapsedTime.count() > msPerGridCell) {
      game.step();
      game.draw(tm);
      lastFrameTime = currentTime;
    }
    tm.refresh();
    UserInput input = tm.getUserInput();
    if (game.computeUserInput(input)) {
      game.draw(tm);
    }

    if (input.keycode_ == 'q') {
      break;
    }

    if (game.isGameOver()) {
      game.drawGameOver(tm);
      highscore.updateHighscores(game.getScore());
      while (true) {
        tm.refresh();
        UserInput input = tm.getUserInput();
        if (input.keycode_ == 'q') {
          return 1;
        }
      }
    }
  }
}