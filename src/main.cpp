#include <iostream>
#include "GameOfLife.hpp"
#include <thread>
#include <chrono>

int main() {
    const int ROW =10;
    const int COL =20;
    GameOfLife game(ROW, COL);
    for (int i=0; i<50; i++){
        std::cout << "\x1B[2J\x1B[H";
        game.printGrid();
        if (!game.updateGrid()) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    return 0;
}
