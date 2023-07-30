#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int lengthSeq, inputNum, multiple = 1;
    double mean;

    cout << "section a" << endl;

    cout << "Please enter the length of the sequence: " << endl;
    cin >> lengthSeq;

    cout << "Please enter your sequence: " << endl;

    for (int i = 0; i < lengthSeq; ++i)
    {
        cin >> inputNum;
        multiple *= inputNum;
    }

    mean = pow(multiple, 1.0 / lengthSeq);

    cout << "The geometric mean is: " << mean << endl;

    lengthSeq = 0;
    inputNum = 0;
    mean = 0;
    multiple = 1;

    cout << "\nsection b" << endl;

    cout << "Please enter a non-empty sequence of positive integers,"; 
    cout << " each one in a separate line. End your sequence by typing -1:" << endl;

    while (cin >> inputNum)
    {
        if (inputNum == -1)
        {
            break;
        }
        multiple *= inputNum;
        ++lengthSeq;
    }

    mean = pow(multiple, 1.0 / lengthSeq);

    cout << "The geometric mean is: " << mean << endl;

    return 0;
}