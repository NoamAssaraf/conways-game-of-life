#include "GameOfLife.hpp"

GameOfLife::GameOfLife(int rows, int cols): grid(rows, std::vector<int>(cols, 0)){
if (rows > 3 && cols > 3) {
    grid[0][1] = 1;
    grid[1][2] = 1;
    grid[2][0] = 1;
    grid[2][1] = 1;
    grid[2][2] = 1;
}
}

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

int GameOfLife::countNeighbors(int row, int col) const{
    int count = 0;
    for (int i=-1; i<2; i++){
        for (int j=-1;j<2;j++){
            if (i==0 && j==0) continue;
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()) {
                count += grid[newRow][newCol];
            }
        }
    }
    return count; 
}

bool GameOfLife::updateGrid() {
    std::vector<std::vector<int>> nextGrid = grid;
    bool changed = false;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            int neighbors = countNeighbors(i, j);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    nextGrid[i][j] = 0; // Cell dies
                    changed = true;
                }
            } else {
                if (neighbors == 3) {
                    nextGrid[i][j] = 1; // Cell becomes alive
                    changed = true;
                }
            }
        }
    }
    grid.swap(nextGrid);
    return changed;
}
