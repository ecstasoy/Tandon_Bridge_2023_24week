#include <iostream>
#include <string>
#include <vector>

using namespace std;

void statString(vector<string> &arr, string line, int& count);
bool checkString(string line);
void printRes(vector<string> arr, int count);

int main() {
    vector<string> arr;
    string inputLine = " ";
    int count = 0;

    cout << "Please enter a non-empty sequence of Strings. ";
    cout << "Each string should be in a separate line and consists of only lowercase English letters and/or numerical characters. ";
    cout << "To indicate the end of the input, enter an empty string in one line." << endl;

    while (inputLine != "") {
        getline(cin, inputLine);
        statString(arr, inputLine, count);
    }

    printRes(arr, count);

    return 0;
}

void statString(vector<string> &arr, string line, int& count) {
    if (checkString(line)) {
        ++count;
    } else {
        arr.push_back(line);
    }
}

bool checkString(string line) {
    int size = line.length();
    for (int i = 0; i < size; ++i) {
        if (line[i] >= '0' && line[i] <= '9') return false;
    }

    return true;
}

void printRes(vector<string> arr, int count) {
    int size = arr.size();

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << endl;
    }

    cout << "Number of Strings in the input sequence that contain only lowercase English letters: " << count - 1 << "." << endl;
}