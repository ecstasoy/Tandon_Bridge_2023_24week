#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int n;
    string spacing, letter;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>n;

    for (int i = 0; i <= n; ++i) 
    {
        spacing = string(n - i, ' ');
        letter = string(2 * i + 1, '*');
        cout<<spacing<<letter<<endl;   
    }

    for (int j = 0; j < n; ++j) 
    {
        spacing = string(j + 1, ' ');
        letter = string(2 * n - 2 * j - 1, '*');
        cout<<spacing<<letter<<endl;
    }

    return 0;
}