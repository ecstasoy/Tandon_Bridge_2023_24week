#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    int input, num, sqroot, divisorSum = 0;
    int countPSquares = 0, countPNumbers = 0;

    cout<<"Please enter a sequence of integers ";
    cout<<"(with at least 1-digit and at most 9-digits)";
    cout<<", Each one in a separate line. End your sequence by typing -1. "<<endl;;

    do
    {
        cin>>input;
        num = input;
        sqroot = sqrt(num);

        if (num == sqroot * sqroot) 
        {
            ++countPSquares;
        }

        for (int i = 1; i < num; ++i) 
        {
            if (num % i ==0) {
                divisorSum += i;
            }
        }

        if (divisorSum == num) 
        {
            ++countPNumbers;
        }

        divisorSum = 0;

    } while (input != -1);

    cout<<"Total count of Perfect Squares in the given sequence: "<<countPSquares<<endl;
    cout<<"Total count of Perfect Numbers in the given sequence: "<<countPNumbers<<endl;
    
    return 0;
}