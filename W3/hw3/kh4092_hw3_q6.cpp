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

    int startHour, startMin, duration;
    double cost;
    string weekday;
    char colon;

    cout << "Please enter the start time of the call using 24-hour notation (such as 13:30): ";
    cin >> startHour >> colon >> startMin;

    cout << "Please enter the duration of the call:  ";
    cin >> duration;

    cout << "Please enter the day of the week when the call starts using Mo, Tu, We, Th, Fr, Sa, Su: ";
    cin >> weekday;

    if (weekday == "Sa" || weekday == "Su")
    {
        cost = duration * 0.15;
    }
    else if (startHour < 8 || startHour > 18)
    {
        cost = duration * 0.25;
    }
    else
    {
        cost = duration * 0.40;
    }
    

    cout << "The cost of your call is: $" << cost << endl;

    return 0;
}