#include <iostream>
using namespace std;

int main()
{
    int m, modRemainder;
    int n, modCount;

    for (m = 2; m < 100; m++)
    {

        modCount = 0;

        for (n = 2; n <= m - 1; n++)
        {
            
            modRemainder = m % n;

            if (modRemainder == 0)
            {
                modCount++;
            }
        }

        if (modCount == 0)
        {
            cout << m << endl;
        }

    }

    return 0;
}
