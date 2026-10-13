#include "GameOfLife.hpp"

GameOfLife::GameOfLife(int rows, int cols): grid(rows, std::vector<int>(cols, 0)){}

void GameOfLife::printGrid() const{
    for (const auto& row : grid) {
        for (auto cell : row) {
            if (cell == 1) {
                std::cout << " O ";
            } else {
                std::cout << " . ";
            }
        }
        std::cout << std::endl;
    }
}
