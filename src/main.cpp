#include <iostream>
#include "GameOfLife.hpp"

int main() {
    const int ROW =10;
    const int COL =20;
    GameOfLife game(ROW, COL);
    game.printGrid();

    std::cout << "gen 0 ->1" << std::endl;
    game.updateGrid();
    game.printGrid();  

    std::cout << "gen 1 ->2" << std::endl;
    game.updateGrid();
    game.printGrid();
    return 0;
}
