#include <iostream>
using namespace std;

int main()
{
    int n, num, currDigit, evenCount = 0, oddCount = 0;

    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    for (int i = 0; i <= n; ++i)
    {
        num = i;
        while (num > 0)
        {
            currDigit = num % 10;
            if (currDigit % 2 == 0)
            {
                evenCount++;
            }
            else
            {
                oddCount++;
            }
            num /= 10;
        }
        
        if (evenCount > oddCount)
        {
            cout << i << endl;
        }

        evenCount = 0;
        oddCount = 0;
    }

    return 0;
}