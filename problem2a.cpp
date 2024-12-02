#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample2a.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    long long int safeCount = 0;

    while (getline(inputFile, line)) {
        stringstream ss(line);
        vector<int> levels;
        int num;
        while (ss >> num) {
            levels.push_back(num);
        }

        bool isSafe = true;
        bool isIncreasing = true;
        bool isDecreasing = true;

        for (size_t i = 0; i < levels.size() - 1; ++i) {
            int diff = levels[i + 1] - levels[i];

            if (diff > 0) {
                isDecreasing = false;
            } else if (diff < 0) {
                isIncreasing = false;
            }

            if (abs(diff) < 1 || abs(diff) > 3) {
                isSafe = false;
                break;
            }
        }
        if (isSafe && (isIncreasing || isDecreasing)) {
            ++safeCount;
        }
    }

    cout << safeCount << endl;
    return 0;
}
