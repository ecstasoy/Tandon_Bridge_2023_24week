#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num, power = 1, countDigit = 0;

    cout << "Enter decimal number: " << endl;
    cin >> num;

    cout << "The binary representation of " << num << " is ";

    while (power < num)
    {
        power *= 2;
    }

    while (power > 0)
    {
        if (num >= power)
        {
            cout << "1";
            num -= power;
        }
        else if(countDigit >0)
        {
            cout << "0";
        }
        power /= 2;
        ++countDigit;
    }

    cout << endl;

    return 0;
}