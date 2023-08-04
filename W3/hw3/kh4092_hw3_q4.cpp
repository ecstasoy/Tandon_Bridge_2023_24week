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

    if (int(inputNum) == inputNum)
    {
        outputNum = inputNum;
        cout << outputNum << endl;
    }
    else
    {
        outputNum = (int) inputNum;
        switch (flag)
        {
            case FLOOR_ROUND:
            if (inputNum < 0)
            {
                cout << outputNum - 1 << endl;
                break;
            }
            else
            {
                cout << outputNum << endl;
                break;
            }

            case CEILING_ROUND:
            if (inputNum < 0)
            {
                cout << outputNum << endl;
                break;
            }
            else
            {
                cout << outputNum + 1 << endl;
                break;
            }

            case ROUND:
            {
                if (inputNum < 0)
                {
                    if (outputNum - inputNum < 0.5)
                    {
                        cout << outputNum << endl;
                        break;
                    }
                    else
                    {
                        cout << outputNum - 1 << endl;
                        break;
                    }             
                }
                else
                {
                    if (inputNum - outputNum < 0.5)
                    {
                        cout << outputNum << endl;
                        break;
                    }
                    else
                    {
                        cout << outputNum + 1 << endl;
                        break;
                    }
                }
            }

            default:
                cout << "Invalid input." << endl;
        }
    }

    return 0;
}