#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char flagQuit;

do
{
    double inputN, guessN, guessNPrevious, guessR;

    cout << "Please enter a number: " << endl;
    cin >> inputN;

    guessN = inputN / 2.0;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    while (abs((guessN - guessNPrevious) / guessNPrevious) >= 0.01)
    {
        guessNPrevious = guessN;
        guessR = inputN / guessN;
        guessN = (guessN + guessR) / 2.0;
    }

    cout << "The square root of the number you enter is: " << endl;
    cout << guessN << endl;

    cout << "Type 'N' to quit and any other letter key to start over." << endl;
    cin >> flagQuit;

} while ((flagQuit != 'N') && (flagQuit != 'n'));

    return 0;
}