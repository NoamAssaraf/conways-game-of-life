#include <iostream>
#include "GameOfLife.hpp"
#include <thread>
#include <chrono>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./GameOfLife --demo  " << std::endl;
        return 0;
    }
    else{
    int row =10;
    int col =20;
    int numReps = 50;
    if (std::string(argv[1]) != "--demo") {
    for (int i=1; i<argc; i++){
        std::string arg = argv[i];
        if (arg == "--rows" && i+1 < argc) {
            row = std::stoi(argv[i+1]);
            i++;
        }
        else if (arg == "--cols" && i+1 < argc) {
            col = std::stoi(argv[i+1]);
            i++;
        }
        else if (arg == "--reps" && i+1 < argc) {
            numReps = std::stoi(argv[i+1]);
            i++;
        }
    }
}
    GameOfLife game(row, col);
    game.setGliderPattern();
    for (int i=0; i<numReps; i++){
        std::cout << "\x1B[2J\x1B[H";
        game.printGrid();
        if (!game.updateGrid()) {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    }
    return 0;
}
