#include <iostream>
using namespace std;

int main()
{
    int countQuarters, countDimes, countNickels, countPennies;
    int amountDollars, amountCents;
    int amountTotalInCents;

    cout<<"Please enter your amount in the format of ";
    cout<<"dollars and cents separated by a space: "<<endl;
    cin>>amountDollars>>amountCents;

    amountTotalInCents = amountDollars * 100 + amountCents;
    countQuarters = amountTotalInCents / 25;
    countDimes = (amountTotalInCents - countQuarters * 25) / 10;
    countNickels = (amountTotalInCents - countQuarters * 25 - countDimes * 10) / 5;
    countPennies = amountTotalInCents - countQuarters * 25 - countDimes * 10 
                    - countNickels * 5;
    
    cout<<amountDollars<<" dollars and "<<amountCents<<" cents are:"<<endl;
    cout<<countQuarters<<" quarters, "<<countDimes<<" dimes, ";
    cout<<countNickels<<" nickels, "<<countPennies<<" pennies.";

    return 0;
}