#include <iostream>
#include <string>
using namespace std;

int main()
{
    int inputNum, num, currDigit;
    string binString = "";

    cout << "Please enter a positive decimal number: " << endl;
    cin >> inputNum;

    num = inputNum;

    while (num > 0)
    {
        binString = to_string(num % 2) + binString;
        num /= 2;
    }

    cout << "The binary representation of " << inputNum << " is " << binString << endl;

    return 0;
}