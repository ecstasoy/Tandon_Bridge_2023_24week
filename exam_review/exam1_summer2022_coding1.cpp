#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string letter, spacing, line;

    cout<<"Please enter a positive number: "<<endl;
    cin>>n;

    for (int i = 1; i <= n+1; ++i) {
        if (i == 1 || i == n+1) {
            line = string(2*n, '*');
            cout<<line<<endl;
        } else {
            letter = string(i-1, '*');
            spacing = string(2*(n+1-i), ' ');
            cout<<letter<<spacing<<letter<<endl;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            line = string(2*n, '*');
            cout<<line<<endl;
        } else {
            letter = string(n-i, '*');
            spacing = string(2*i, ' ');
            cout<<letter<<spacing<<letter<<endl;
        }
    }

    return 0;
}