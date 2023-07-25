//
// Created by Kunhua Huang on 7/24/23.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    const double RATE_ONE = 0.40;
    const double RATE_TWO = 0.25;
    const double RATE_THREE = 0.15;

    int startHour, startMin, endHour, endMin, duration;
    double cost;
    string weekday;

    cout << "Please enter the start hour of the call using 24-hour notation: ";
    cin >> startHour;

    cout << "Please enter the start minute of the call: ";
    cin >> startMin;

    cout << "Please enter the end hour of the call using 24-hour notation:  ";
    cin >> endHour;

    cout << "Please enter the end minute of the call: ";
    cin >> endMin;

    cout << "Please enter the day of the week when the call starts using Mo, Tu, We, Th, Sa, Su: ";
    cin >> weekday;

    if (endHour < startHour)
    {
        duration = (endHour + 23 - startHour) * 60 + 60 - startMin + endMin;
    }
    else if (endHour > startHour)
    {
        duration = (endHour - 1 - startHour) * 60 + 60 - startMin + endMin;
    }
    else
    {
        duration = endMin - startMin;
    }

    if (weekday != "Sa" && weekday != "Su")
    {
        if (startHour >= 8 && startHour < 18)
        {
            cost = duration * RATE_ONE;
        }
        else
        {
            cost = duration * RATE_TWO;
        }
    }
    else
    {
        cost = duration * RATE_THREE;
    }

    cout << "The cost of your call is: $" << cost << endl;

    return 0;
}