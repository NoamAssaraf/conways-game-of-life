#include <iostream>
#include <vector>

int main() {
    const int ROW =10;
    const int COL =20;
    std::vector<std::vector<int>> grid(ROW, std::vector<int>(COL, 0));
    grid[0][0] = 1;
    grid[1][1] = 1;
    grid[2][2] = 1;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (grid[i][j] == 1) {
                std::cout << " O ";
            } else {
                std::cout <<" . ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}