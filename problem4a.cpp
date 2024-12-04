#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool checkWord(const vector<string> &grid, int row, int col, int dRow, int dCol) {
    string word = "XMAS";
    int n = grid.size();
    int m = grid[0].size();

    for (int k = 0; k < word.size(); k++) {
        int newRow = row + k * dRow;
        int newCol = col + k * dCol;

        if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m) {
            return false;
        }
        if (grid[newRow][newCol] != word[k]) {
            return false;
        }
    }
    return true;
}

int countXMAS(const vector<string> &grid) {
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();

    vector<pair<int, int>> directions = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto dir : directions) {
                if (checkWord(grid, i, j, dir.first, dir.second)) {
                    count++;
                }
            }
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample4a.txt");
    if (!inputFile) {
        cerr << "Error: File could not be opened.\n";
        return 1;
    }

    vector<string> lines;
    string line;
    while (inputFile >> line) {
        lines.push_back(line);
    }
    inputFile.close();

    int result = countXMAS(lines);
    cout << "Total occurrences of XMAS: " << result << endl;
    return 0;
}
