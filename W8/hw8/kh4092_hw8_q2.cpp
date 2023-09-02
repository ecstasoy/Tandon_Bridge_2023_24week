#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);
void swap(char& v1, char& v2);
string reverse(const string& str);

int main() {
    using namespace std;
    
    string inputStr;

    cout<<"Please enter a word: ";
    cin>>inputStr;

    if (isPalindrome(inputStr)) {
        cout<<inputStr<<" is a palindrome.";
    } else {
        cout<<inputStr<<" is not a palindrome.";
    }
}

bool isPalindrome(string str) {
    return str == reverse(str);
}

void swap(char& v1, char& v2) {
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string& str) {
    int start = 0;
    int end = str.length();
    string temp = string(str);

    while (start < end) {
        --end;
        swap(temp[start], temp[end]);
        ++start;
    }

    return temp;
}