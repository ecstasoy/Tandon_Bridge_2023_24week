//
// Created by Kunhua Huang on 7/24/23.
//

#include <iostream>
using namespace std;

int main()
{
    const double POUND_TO_KILO = 0.453592;
    const double INCH_TO_METER = 0.0254;
    double weight, height, bmi;

    cout << "Please enter weight (in pounds): ";
    cin >> weight;

    cout << "Please enter height (in inches): ";
    cin >> height;

    bmi = weight * POUND_TO_KILO / pow(height * INCH_TO_METER, 2);

    if (bmi < 18.5)
    {
        cout << "The weight status is: underweight" << endl;
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        cout << "The weight status is: Normal" << endl;
    }
    else if (bmi >= 25 && bmi < 30)
    {
        cout << "The weight status is: Overweight" << endl;
    }
    else
    {
        cout << "The weight status is: Obese" << endl;
    }

    return 0;
}