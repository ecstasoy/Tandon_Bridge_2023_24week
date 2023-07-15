#include <iostream>
using namespace std;

int main()
{
    double weightOunces, weightTons, countBoxes;
    char flagQuit = 'Y';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    while ((flagQuit != 'N') && (flagQuit != 'n'))
    {
        cout << "Please enter the weight of a package of breakfast cereal in ounces: " << endl;
        cin >> weightOunces;

        weightTons = weightOunces / 35273.92;
        countBoxes = 35273.92 / weightOunces;
        
        cout << "The weight of a package of breakfast cereal is " << weightTons << " in tons." << endl;
        cout << "You need " << countBoxes << " boxes to yield one ton of cereal." << endl;

        cout << "Do you want to start a new calculation? Type any letter key to continue and 'N' to quit" << endl;
        cin >> flagQuit;
    }

    return 0;
}