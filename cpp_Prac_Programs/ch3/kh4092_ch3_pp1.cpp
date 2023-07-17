#include <iostream>
using namespace std;

int main()
{
    char inputA, inputB;
    char quitFlag = 'y';

    do
    {
        do
        {
            cout << "Player A's turn: please type in either P, R, or S: " << endl;
            cin >> inputA;
            cout << "Player B's turn: please type in either P, R, or S: " << endl;
            cin >> inputB;

            if ((inputA == inputB) || (inputA - inputB == 32) || (inputB - inputA == 32))
            {
                cout << "Tied! Please try enter again!" << endl;
            }
        } while ((inputA == inputB) || (inputA - inputB == 32) || (inputB - inputA == 32));
        

        if ((inputA == 'P') || (inputA == 'p'))
        {
            if ((inputB == 'R') || (inputB == 'r'))
            {
                cout << "Paper covers Rock! Player A wins." << endl;
            }
            else
            {
                cout << "Scissors cut Paper! Player B wins." << endl;
            }
        }

        if ((inputA == 'R') || (inputA == 'r'))
        {
            if ((inputB == 'P') || (inputB == 'p'))
            {
                cout << "Paper covers Rock! Player B wins." << endl;
            }
            else
            {
                cout << "Rock smashes scissors! Player A wins." << endl;
            }
        }

        if ((inputA == 'S') || (inputA == 's'))
        {
            if ((inputB == 'P') || (inputB == 'p'))
            {
                cout << "Scissors cut Paper! Player A wins." << endl;
            }
            else
            {
                cout << "Rock smashes scissors! Player B wins." << endl;
            }
        }

    cout << "If you want to quit, type 'N'; If you wish to play another round, type any other letter key to continue.";
    cin >> quitFlag;

    } while ((quitFlag != 'N') && (quitFlag != 'n'));

    return 0;
}