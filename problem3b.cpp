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

int parseCorruptedInstructionII(const string &instruction) {
    regex dontPattern("don't\\(\\)");
    regex doPattern("do\\(\\)");
    smatch match;
    int result = 0;

    bool enabled{true};
    auto it = instruction.cbegin();

    while (it != instruction.cend()) {
        if (enabled) {
            regex_search(it, instruction.cend(), match, dontPattern);
            result += parseCorruptedSubString(it, match.suffix().first);
            enabled = false;
            it = match.suffix().first;
        } else {
            regex_search(it, instruction.cend(), match, doPattern);
            enabled = true;
            it = match.suffix().first;
        }
    }

    return result;
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
    cout << parseCorruptedInstructionII(completeInstruction) << endl;
}
