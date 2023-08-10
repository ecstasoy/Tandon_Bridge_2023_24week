#include <iostream>
using namespace std;

int main() {
    int input, num, currDigit, oddCount, evenCount, digitCount = 0;
    int countGroup3 = 0, countGroup4 = 0, countGroup5 = 0;
    int countGroup6 = 0, countGroup7 = 0, countGroupMoreOdd = 0, countGroupEqual = 0;

    cout<<"Please enter a sequence of numbers (with at least 3-digits and ";
    cout<<"at most 7-digits), each one in a separate line. End your sequence by ";
    cout<<"typing -1: "<<endl;

    do
    {
        cin>>input;
        num = input;

        while (num > 0) {
            currDigit = num % 10;
            if (currDigit % 2 ==0) {
                ++evenCount;
            } else {
                ++oddCount;
            }

            num /= 10;
            ++digitCount;
        }

        if (digitCount == 3) {
            ++countGroup3;
        } else if (digitCount == 4) {
            ++countGroup4;
        } else if (digitCount == 5) {
            ++countGroup5;
        } else if (digitCount == 6) {
            ++countGroup6;
        } else {
            ++countGroup7;
        }

        if (oddCount > evenCount) {
            ++countGroupMoreOdd;
        } else if (oddCount == evenCount) {
            ++countGroupEqual;
        }

        digitCount = 0;
        oddCount = 0;
        evenCount = 0;
    } while (input != -1);

    cout<<"Total count of numbers in the 3-digits Numbers Group: "<<countGroup3<<endl;
    cout<<"Total count of numbers in the 4-digits Numbers Group: "<<countGroup4<<endl;
    cout<<"Total count of numbers in the 5-digits Numbers Group: "<<countGroup5<<endl;
    cout<<"Total count of numbers in the 6-digits Numbers Group: "<<countGroup6<<endl;
    cout<<"Total count of numbers in the 7-digits Numbers Group: "<<countGroup7<<endl;
    cout<<"Total count of numbers in the More Odd-digits Group: "<<countGroupMoreOdd<<endl;
    cout<<"Total count of numbers in the Equal-digits Group: "<<countGroupEqual<<endl;

    return 0;
}