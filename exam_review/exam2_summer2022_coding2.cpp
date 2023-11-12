#include <iostream>
#include <vector>
#include <string>

using namespace std;

void statString(vector<string> &arrLine, string line, int &specCount, int &lowerCount);
bool checkSpec(string line);    
bool checkLower(string line);
string removeSpec(string line);
void printRes(vector<string> arrLine, int specCount, int lowerCount);

int main() {
    vector<string> inputArr;
    string inputLine = " ";
    int specCount =0;
    int lowerCOunt = 0;

    cout << "Please enter a non-empty sequence of Strings. ";
    cout << "Each string should be in a separate line and consists of only lowercase English ";
    cout << "letters and/or special characters @, #, $, !, &. ";
    cout << "To indicate the end of the input, enter an empty string in one line." << endl;

    while (!inputLine.empty()) {
        getline(cin, inputLine);
        statString(inputArr, inputLine, specCount, lowerCOunt);
    }

    printRes(inputArr, specCount, lowerCOunt);

    return 0;
}

void statString(vector<string> &arrLine, string line, int &specCount, int &lowerCount) {
    if (checkSpec(line)) {
        ++specCount;
    } else if (checkLower(line)) {
        arrLine.push_back(line);
        ++lowerCount;
    } else {
        string newLine = removeSpec(line);
        arrLine.push_back(newLine);
    }
}

bool checkSpec(string line) {
    int size = line.length();

    for (int i = 0; i < size; ++i) {
        if (line[i] != '#' && line[i] != '@' && line[i] != '$' && line[i] != '!' && line[i] != '&') return false;
    }

    return true;
}

bool checkLower(string line) {
    int size = line.length();

    for (int i = 0; i < size; ++i) {
        if (line[i] < 97 || line[i] > 122) return false;
    }

    return true;
}

string removeSpec(string line) {
    string newStr = "";
    int size = line.length();

    for (int i = 0; i < size; ++i) {
        if (line[i] != '#' && line[i] != '@' && line[i] != '$' && line[i] != '!' && line[i] != '&') {
            newStr.push_back(line[i]);
        }
    }

    return newStr;
}

void printRes(vector<string> arrLine, int specCount, int lowerCount) {
    int arrSize = arrLine.size();

    for (int i = 0; i < arrSize; ++i) {
        cout << arrLine[i] << endl;
    }

    cout << "Number of Strings in the input sequence that contain only special characters: " << specCount << endl;
    cout << "Number of Strings in the input sequence that contain only lowercase English letters:" << lowerCount << endl;
}