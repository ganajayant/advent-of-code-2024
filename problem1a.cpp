#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample1a.txt");
    if (!inputFile) {
        std::cerr << "Error: File could not be opened.\n";
        return 1; // Exit if the file can't be opened
    }
    int num1, num2;
    vector<long long int> a;
    vector<long long int> b;
    while (inputFile >> num1 >> num2) {
        a.push_back(num1);
        b.push_back(num2);
    }
    inputFile.close();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        diff += abs(a[i] - b[i]);
    }
    cout << diff << endl;
    return 0;
}
