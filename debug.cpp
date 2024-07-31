
#include "./Game.h"
#include "./Highscore.h"
#include <chrono>
#include <iostream>
#include <string>
#include <unistd.h>

// code der nur zum debuggen verwendet wurde
/*
int main() {
  for (int i = 0; i < 7; i++) {
    std::cout << "------------------------" << std::endl;
    Tetromino t(i, 0, 0);
  // log something
  t.logShape();
  for (int i = 0; i < 4; i++) {
    std::cout << "Rotating right!" << std::endl;
    t.rotateRight();
    t.logShape();
  }
  }

  Highscore hs;
  //hs.loadHighscores();
  hs.logHighscores();
  hs.updateHighscores(1000);
  std::cout << "..." << std::endl;
  hs.logHighscores();
}
 */