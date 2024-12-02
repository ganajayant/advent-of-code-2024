#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    ifstream inputFile("samples/sample1b.txt");
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
    map<long long int, long long int> x;
    for (auto temp : b) {
        x[temp]++;
    }
    long long int sim = 0;
    for (auto temp : a) {
        sim += temp * x[temp];
    }
    cout << sim << endl;
    return 0;
}
