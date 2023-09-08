#include <iostream>
#include <string>
#include <vector>

void countLetters(const std::string &line, std::vector<int> &countLetter);
bool isAnagram(const std::string &lineOne, const std::string &lineTwo, std::vector<int> &countLetterOne, std::vector<int> &countLetterTwo);

int main() {
    using namespace std;

    string lineOne, lineTwo;
    vector<int> countLetterOne(26);
    vector<int> countLetterTwo(26);

    cout<<"Please enter first line of text: "<<endl;
    getline(cin, lineOne);
        cout<<"Please enter second line of text: "<<endl;
    getline(cin, lineTwo);

    if(isAnagram(lineOne, lineTwo, countLetterOne, countLetterTwo)) {
        cout<<"They are anagrams."<<endl;
    } else {
        cout<<"They are not anagrams."<<endl;
    }

    return 0;
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

bool isAnagram(const std::string &lineOne, const std::string &lineTwo, std::vector<int> &countLetterOne, std::vector<int> &countLetterTwo) {
    bool isEqual = true;
    
    countLetters(lineOne, countLetterOne);
    countLetters(lineTwo, countLetterTwo);

    for (int i = 0; i < 26; ++i) {
        if (countLetterOne[i] != countLetterTwo[i]) {
            isEqual = false;
        }
    }

    if (isEqual) {
        return true;
    } else {
        return false;
    }
}