#include <iostream>
using namespace std;

int main()
{
    int i = 0, outputNum = 0, inputNum;

    cout << "Please enter a positive integer: " << endl;
    cin >> inputNum;

    while (i < inputNum)
    {
        outputNum += 2;
        cout << outputNum << endl;
        i++;
    }

    cout << "This is the end of section (a).\n" << endl;

    outputNum = 0;

    for (i = 0; i < inputNum; ++i)
    {
        outputNum += 2;
        cout << outputNum << endl;
    }

    cout << "This is the end of section (b). " << endl;

    return 0;
}