#include "./Highscore.h"
#include "./TerminalManager.h"
#include <algorithm>
#include <fstream>
#include <iostream>

Highscore::Highscore() { loadHighscores(); }

void Highscore::updateHighscores(int score) {
  highscores_.push_back(score);
  std::sort(highscores_.begin(), highscores_.end(), std::greater<int>());
  if (highscores_.size() > 5) {
    highscores_.pop_back();
  }
  std::ofstream file(file_);
  if (file.is_open()) {
    for (int i = 0; i < highscores_.size(); i++) {
      file << highscores_[i] << std::endl;
    }
    file.close();
  }
}

void Highscore::loadHighscores() {
  std::ifstream file(file_);
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
      highscores_.push_back(std::stoi(line));
    }
    file.close();
  }
}

void Highscore::renderHighscores(TerminalManager tm) const {
  tm.drawString(1, 5, 1, "Highscores:");
  for (int i = 0; i < highscores_.size(); i++) {
    tm.drawString(i + 3, 6, 1, std::to_string(highscores_[i]).data());
  }
  tm.refresh();
}

void Highscore::logHighscores() const {
  for (int i = 0; i < highscores_.size(); i++) {
    std::cout << highscores_[i] << std::endl;
  }
}

std::vector<int> Highscore::getHighscores() const { return highscores_; }