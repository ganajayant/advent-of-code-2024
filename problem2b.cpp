#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample2b.txt");

    if (!inputFile) {
        cerr << "Error opening file sample2b.txt" << endl;
        return 1;
    }

    int ans = 0;

    auto checkSafe = [](vector<int> &a) {
        bool unsafe = false;
        int num_levels = static_cast<int>(a.size());

        for (int i = 1; i < num_levels; i++) {
            int diff = abs(a[i] - a[i - 1]);
            if (diff < 1 || diff > 3) {
                unsafe = true;
                break;
            }
        }

        if (unsafe)
            return false;

        if (is_sorted(a.begin(), a.end()) || is_sorted(a.rbegin(), a.rend())) {
            return true;
        }

        return false;
    };

    string line;
    while (getline(inputFile, line)) {
        vector<int> levels;
        istringstream iss(line);
        int num;

        while (iss >> num) {
            levels.push_back(num);
        }

        int num_levels = static_cast<int>(levels.size());

        for (int i = 0; i < num_levels; i++) {
            vector<int> tmp = levels;
            tmp.erase(tmp.begin() + i);
            if (checkSafe(tmp)) {
                ++ans;
                break;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
