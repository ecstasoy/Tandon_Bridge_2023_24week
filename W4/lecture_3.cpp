#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Please enter a decimal number: " << endl;
    cin >> n;

    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= i - 1; ++j)
        {
            cout << " ";
        }
        
        for (int k = i; k <= n; ++k)
        {
            cout << "*";
        }

        for (int m = i; m < n; ++m)
        {
            cout << "*";
        }
    
        cout << endl;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            cout << " ";
        }
        
        for (int k = 0; k <= i; ++k)
        {
            cout << "*";
        }

        for (int m = 0; m < i; ++m)
        {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}