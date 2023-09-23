#include <iostream>
#include <vector>
#include <string>

using namespace std;

void statSeq(vector<string> &arrLine, string line, int &count);
bool checkNum(string line);
void printRes(vector<string> arrLine, int count);

int main() {
    vector<string> arrLine;
    string inputLine = " ";
    int count = 0;

    cout << "Please enter a non-empty sequence of Strings. ";
    cout << "Each string should be in a separate line and consists of only decimal digit characters. ";
    cout << "To indicate the end of the input, enter an empty string in one line." << endl;

    while (inputLine != "") {
        getline(cin, inputLine);
        statSeq(arrLine, inputLine, count);
    }

    printRes(arrLine, count);

    return 0;
}

void statSeq(vector<string> &arrLine, string line, int &count) {
    if (checkNum(line)) {
        ++count;
    } else {
        arrLine.push_back(line);
    }
}

bool checkNum(string line) {
    int length = line.length();
    for (int i = 0; i < length; ++i) {
        if (line[i] != '1' && line[i] != '0') return true;
    }

    return false;
}

void printRes(vector<string> arrLine, int count) {
    int arrSize = arrLine.size();

    for (int i = 0; i < arrSize; ++i) {
        cout << arrLine[i] << endl;
    }

    cout << "Number of Strings in the input sequence that get deleted for containing ";
    cout << "at least one character which is not 0 or 1: " << count << endl;
}