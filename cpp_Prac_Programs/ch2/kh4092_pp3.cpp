#include <iostream>
using namespace std;

int main()
{
    double speedMPH, pace, paceSeconds;
    int paceMinutes;

    cout << "Please enter your speed in MPH: " << endl;
    cin >> speedMPH;

    pace = 60.0 / speedMPH;
    paceMinutes = static_cast<int>(pace);
    paceSeconds = (pace - paceMinutes) * 60.0;

    cout << paceMinutes << " " << paceSeconds << endl;

    return 0;
}