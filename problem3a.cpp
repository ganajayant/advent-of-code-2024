#include <fstream>
#include <iostream>
#include <regex>

using namespace std;

int parseCorruptedSubString(string::const_iterator begin, string::const_iterator end) {
    regex mulPattern("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
    smatch match;
    int result = 0;

    auto it = begin;
    while (regex_search(it, end, match, mulPattern)) {
        result += stoi(match[1].str()) * stoi(match[2].str());
        it = match.suffix().first;
    }

    return result;
}

int parseCorruptedInstructionI(const string &instruction) {
    return parseCorruptedSubString(instruction.cbegin(), instruction.cend());
}

int main() {
    ifstream input("samples/sample3a.txt");
    if (!input.is_open()) {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }
    string completeInstruction;
    string instruction;
    while (getline(input, instruction)) {
        completeInstruction += instruction;
    }
    cout << parseCorruptedInstructionI(completeInstruction) << endl;
}
