#include <iostream>
#include <string>
using namespace std;

int main() {
    char inLetter, currLetter = 'a';
    int n;
    string printString;

    cout<<"Please enter a lower-case letter: "<<endl;
    cin>>inLetter;

    n = inLetter - currLetter + 1;

    for (int i = 0; i < n; ++i) {
        string spacing = string(n - i - 1, ' ');
        if (i % 2 == 1) {
            printString = string(2 * (i + 1) - 1, currLetter - 32);
        } else {
            printString = string(2 * (i + 1) - 1, currLetter);
        }

        cout<<spacing<<printString<<endl;
        ++currLetter;
        printString = "";
    }

    return 0;
}