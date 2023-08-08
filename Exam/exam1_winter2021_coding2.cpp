#include <iostream>
using namespace std;

int main() {
    int totalInches = 0, inches, feet, yards, input = 1, daysCount = 1;
    const int FOOT_TO_INCH = 12;
    const int YARD_TO_FOOT = 3;

    while(input > 0) {
        cout<<"Enter the number of inches the snail traveled in day #"<<daysCount<<", "<<endl;
        cout<<"or type -1 if they reach their destination."<<endl;
        cin>>input;
        if (input > 0) {
            totalInches += input;
            ++daysCount;
        }
    }

    yards = (totalInches / FOOT_TO_INCH) / YARD_TO_FOOT;
    feet = totalInches / FOOT_TO_INCH - yards * YARD_TO_FOOT;
    inches = totalInches - feet * FOOT_TO_INCH - yards * YARD_TO_FOOT * FOOT_TO_INCH;

    cout<<"In "<<daysCount - 1<<" days, the snail traveled "<<yards<<" yards, "<<feet<<" feet and "<<inches<<" inches. "<<endl;

    return 0;
}