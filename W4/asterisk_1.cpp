#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, spaces = 0;
    string printStr = "";

    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    for (int i = 0; i < 2 * n - 1; ++i)
    {
        
        if (i < n)
        {
            for (int j = 0; j < spaces; ++j)
            {
                printStr += " ";
            }

            for (int k = 0; k < 2 * (n - i) - 1; ++k)
            {
                printStr += "*";
            }
            spaces++;
        }
        else
        {
            for (int j = 0; j < spaces - 2; ++j)
            {
                printStr += " ";
            }

            for (int k = 0; k < 2 * (i - n + 2) - 1; ++k)
            {
                printStr += "*";
            }
            spaces--;
        }
    cout << printStr << endl;
    printStr = "";
    }

    return 0;
}