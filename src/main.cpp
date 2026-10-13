#include <iostream>
#include "GameOfLife.hpp"

int main() {
    const int ROW =10;
    const int COL =20;
    GameOfLife game(ROW, COL);
    game.printGrid();
    return 0;
}
