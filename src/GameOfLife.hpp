#pragma once
#include <vector>
#include <iostream>

class GameOfLife {
    private:
    std::vector<std::vector<int>> grid;
    
    public:
    GameOfLife(int rows, int cols);
    void printGrid() const;
    void updateGrid();
};