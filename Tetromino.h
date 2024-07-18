#pragma once

#include <vector>

// Struktur eines Tetrominos mit Form und Farbwert
struct TetrominoData {
  std::vector<std::vector<int>> shape;
  int color;
};

// Jeder Tetromino hardcoded mit Farbe
const std::vector<TetrominoData> TETROMINOS = {
    {{{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}}, 2},
    {{{0, 0, 0, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, 3},
    {{{0, 0, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}}, 4},
    {{{0, 0, 0, 0}, {0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}}, 5},
    {{{0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, 6},
    {{{0, 0, 0, 0}, {1, 1, 1, 0}, {1, 0, 0, 0}, {0, 0, 0, 0}}, 7},
    {{{0, 0, 0, 0}, {1, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}}, 8}};

// Struktur einer Position (Koordinaten)
struct Position {
  int x;
  int y;
};

class Tetromino {
public:
  // Konstruktor
  Tetromino(int type, int row, int col);

  // Rotiert den Tetromino nach rechts
  void rotateRight();

  // Rotiert den Tetromino nach links
  void rotateLeft();

  // Bewegt den Tetromino (verändert die Koordinaten)
  void moveLeft();
  void moveRight();
  void moveDown();

  // Getter und Setter
  int getType();

  int getPixel(int x, int y);
  int getRow();
  int getCol();
  int getColor();
  std::vector<std::vector<int>> getShape();

  void logShape();

private:
  // Position des Tetrominos
  Position position_;

  // Form des Tetrominos (wird aus den Presets ausgewählt und dann in das shape
  // Feld kopiert und dort dann später rotiert)
  std::vector<std::vector<int>> shape_;
  int type_;
  int color_;
};
