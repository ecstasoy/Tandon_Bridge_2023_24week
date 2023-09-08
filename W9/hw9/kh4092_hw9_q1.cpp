#include <iostream>
#include <string>
#include <vector>

int countWords(const std::string &line);
void countLetters(const std::string &line, std::vector<int> &countLetter);
void statText(const std::string &line, std::vector<int> &countLetter);

int main() {
    using namespace std;

    string line;
    vector<int> countLetter(26);

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, line);

    statText(line, countLetter);

    return 0;
}

int countWords(const std::string &line) {
    int count = 0;
    bool inAWord = true;

    for (char c : line) {
        if (c == ' ' || c == ',' || c == '.') {
            ++count;
            inAWord = false;
        } else {
            inAWord = true;
        }
    }

    if (inAWord == true) ++count;

    return count;
}

void countLetters(const std::string &line, std::vector<int> &countLetter) {
    for (char c : line) {
        if (c != ' ' && c != ',' && c != '.') {
            char lowerLetter = tolower(c);
            int index = lowerLetter - 'a';
            ++countLetter[index];
        }
    }
}

void statText(const std::string &line, std::vector<int> &countLetter) {
    using namespace std;
    
    int countWord = countWords(line);
    cout<<countWord<<"\twords"<<endl;

    countLetters(line, countLetter);

    for (int i = 0; i < countLetter.size(); ++i) {
        if (countLetter[i] != 0) {
            cout<<countLetter[i]<<"\t"<<static_cast<char> ('a' + i)<<endl;
        }
    }
}