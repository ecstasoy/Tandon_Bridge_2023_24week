//
// Created by Kunhua Huang on 7/24/23.
//

#include <iostream>
using namespace std;

int main()
{
    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int flag;
    double inputNum, outputNum;

    cout << "Please enter a real number: ";
    cin >> inputNum;

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round" << endl;
    cout << "2. Ceiling round" << endl;
    cout << "3. Round to the nearest whole number" << endl;

    cin >> flag;

    outputNum = (int) inputNum;

    switch (flag)
    {
        case FLOOR_ROUND:
            cout << outputNum << endl;
            break;

        case CEILING_ROUND:
            cout << outputNum + 1 << endl;
            break;

        case ROUND:
            cout << round(inputNum) << endl;
            break;

        default:
            cout << "Invalid input." << endl;
    }

    return 0;
}