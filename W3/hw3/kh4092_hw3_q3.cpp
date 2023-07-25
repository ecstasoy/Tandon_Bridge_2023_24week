//
// Created by Kunhua Huang on 7/24/23.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, x1, x2, j;

    cout << "Please enter value of a: ";
    cin >> a;

    cout << "Please enter value of b: ";
    cin >> b;

    cout << "Please enter valur of c: ";
    cin >> c;

    if (a != 0)
    {
        j = pow(b, 2) - 4 * a * c;

        if (j <  0)
        {
            cout << "This equation has no real solution.";
        }
        else if (j == 0)
        {
            x1 = (sqrt(j) - b) / (2 * a);
            x2 = x1;

            cout << "This equation has a single real solution x = ";
            cout << x1 << endl;
        }
        else
        {
            x1 = (sqrt(j) - b) / (2 * a);
            x2 = (- sqrt(j) - b) / (2 * a);

            cout << "This equation has two real solution ";
            cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
        }
    }
    else
    {
        cout << "This is not a quadratic equation." << endl;
    }

    return 0;
}