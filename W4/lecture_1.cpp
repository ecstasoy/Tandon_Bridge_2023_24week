#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i <= 99; ++i)
    {
        if (i % 2 != 0 && i != 13)
        {
            cout << i << endl;
        }
        else
        {
            continue;
        }
    }
}