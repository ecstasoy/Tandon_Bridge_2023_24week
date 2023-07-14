#include <iostream>
using namespace std;

int main()
{
    int countQuarters, countDimes, countNickels, countPennies;
    int amountDollars, amountCents;
    int amountTotalInCents;

    cout<<"Please enter number of coins:"<<endl;
    cout<<"# of quarters: ";
    cin>>countQuarters;
    cout<<"# of dimes: ";
    cin>>countDimes;
    cout<<"# of nickels: ";
    cin>>countNickels;
    cout<<"# of pennies: ";
    cin>>countPennies;

    amountTotalInCents = countQuarters * 25 + countDimes * 10 
                + countNickels * 5 + countPennies;
    amountDollars = amountTotalInCents / 100;
    amountCents = amountTotalInCents % 100;

    cout<<"The total is "<<amountDollars
        <<" dollars and "<<amountCents<<" cents";

    return 0;
}