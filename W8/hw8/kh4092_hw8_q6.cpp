#include <iostream>
#include <string>

using namespace std;

bool isInteger(const string& word);
void replaceDigits(const string& line);

int main() {
    string line;

    cout << "Please enter a line of text: "<<endl;
    getline(cin, line);
    replaceDigits(line);

    return 0;
}

bool isInteger(const string& word) {
    for (size_t i = 0; i < word.length(); ++i) {
        if (word[i] < '0' || word[i] > '9') {
            return false;
        }
    }
    return true;
}

void replaceDigits(const string& line) {
    string word, output;
    for (int i = 0; i <= line.length(); ++i) {
        if (i == line.length() || line[i] == ' ') {
            if (isInteger(word)) {
                output += string(word.length(), 'x');
            } else {
                output += word;
            }
            word = "";

            if (i != line.length()) {
                output += ' ';
            }
        } else {
            word += line[i];
        }
    }

    cout << output << endl;

}