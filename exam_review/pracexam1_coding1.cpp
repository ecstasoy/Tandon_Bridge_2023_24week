#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    char letter = 'a';

    cout<<"Please enter an integer: "<<endl;
    cin>>n;

for (int i = 0; i < n; ++i) {
    string leftPadding(n - i - 1, ' ');
    string middleSpacing(i ? i * 2 - 1 : 0, ' ');

    if (i > 0) {
        cout << leftPadding << letter << middleSpacing << letter << endl;
    } else {
        cout << leftPadding << letter << endl;
    }

    ++letter;
}

letter -= 2;

for (int i = 0; i < n - 1; ++i) {
    string leftPadding(i + 1, ' ');
    string middleSpacing(i < n - 2 ? 2 * n - 5 - 2 * i : 0, ' ');

    if (i < n - 2) {
        cout << leftPadding << letter << middleSpacing << letter << endl;
    } else {
        cout << leftPadding << letter << endl;
    }

    --letter;
}

    return 0;
}