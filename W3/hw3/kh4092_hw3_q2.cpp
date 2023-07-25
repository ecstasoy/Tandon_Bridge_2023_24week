//
// Created by Kunhua Huang on 7/24/23.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int curYear, graYear;
    string name;

    cout << "Please enter your name: ";
    cin >> name;

    cout << "Please enter your graduation year: ";
    cin >> graYear;

    cout << "Please enter current year: ";
    cin >> curYear;

    if (graYear - curYear <= 0)
    {
        cout << name << ", you are graduated!" << endl;
    }
    else if (graYear - curYear == 1)
    {
        cout << name << ", you are a Senior!" << endl;
    }
    else if (graYear - curYear == 2)
    {
        cout << name << ", you are a Junior!" << endl;
    }
    else if (graYear - curYear == 3)
    {
        cout << name << ", you are a Sophomore" << endl;
    }
    else if ( graYear - curYear == 4)
    {
        cout << name << ", you are a Freshman!" << endl;
    }
    else
    {
        cout << name << ", you are not in college yet!" << endl;
    }

    return 0;
}