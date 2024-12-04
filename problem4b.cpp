#include <fstream>
#include <iostream>

using namespace std;

bool isXMAS(const vector<string> &grid, int row, int col) {
    if (row - 1 < 0 || row + 1 >= grid.size() || col - 1 < 0 || col + 1 >= grid[0].size()) {
        return false;
    }
    char topLeft = grid[row - 1][col - 1];
    char topRight = grid[row - 1][col + 1];
    char center = grid[row][col];
    char bottomLeft = grid[row + 1][col - 1];
    char bottomRight = grid[row + 1][col + 1];
    if (center != 'A') {
        return false;
    }
    string diagonal1 = {topLeft, center, bottomRight};
    string diagonal2 = {topRight, center, bottomLeft};

    return (diagonal1 == "MAS" || diagonal1 == "SAM") &&
           (diagonal2 == "MAS" || diagonal2 == "SAM");
}

int countXMAS(const vector<string> &grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (isXMAS(grid, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample4b.txt");
    if (!inputFile) {
        std::cerr << "Error: File could not be opened.\n";
        return 1;
    }
    string line;
    vector<string> lines;
    while (inputFile >> line) {
        lines.push_back(line);
    }
    inputFile.close();
    int count = countXMAS(lines);
    cout << count << endl;
    return 0;
}
