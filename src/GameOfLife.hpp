#pragma once
#include <vector>
#include <iostream>

class GameOfLife {
    private:
    std::vector<std::vector<int>> grid;
    int countNeighbors(int row, int col) const;

    public:
    GameOfLife(int rows, int cols);
    void printGrid() const;
    bool updateGrid();
    void setGliderPattern();
};