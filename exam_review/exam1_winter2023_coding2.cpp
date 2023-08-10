#include <iostream>
using namespace std;

int main() {
    int input, num, currDigit, sum = 0;
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;

    cout<<"Please enter a sequence of numbers";
    cout<<" (with at least 1-digit and at most 8-digits)";
    cout<<", each one in a separate line. End yoursequence by typing -1:"<<endl;

    do
    {
        cin>>input;
        num = input;
        while(num > 0) {
            currDigit = num % 10;
            sum += currDigit;
            num /= 10;
        }

        if (sum < 10) {
            ++count1;
        } else if (sum < 20)
        {
            ++count2;
        } else if (sum < 30)
        {
            ++count3;
        } else {
            ++count4;
        }
        
        sum = 0;
    } while (input != -1);
    
    cout<<"Total count of numbers in the numbers Group 1: "<<count1<<endl;
    cout<<"Total count of numbers in the numbers Group 2: "<<count2<<endl;    
    cout<<"Total count of numbers in the numbers Group 3: "<<count3<<endl;
    cout<<"Total count of numbers in the numbers Group 4: "<<count4<<endl;

    return 0;
}