#include <iostream>
using namespace std;

int main()
{
    double dueInterest, dueTotal, accountBalance, minimumPayment;
    char quitFlag = 'Y';

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    do
    {
        
        cout << "Please enter your account balance: " << endl;
        cin >> accountBalance;

        if (accountBalance <= 1000)
        {
            dueInterest = accountBalance * 0.015;
            dueTotal = accountBalance + dueInterest;
        }
        else
        {
            dueInterest = 1000 * 0.015 + (accountBalance - 1000) * 0.01;
            dueTotal = accountBalance + dueInterest;
        }

         if (dueTotal <= 10)
         {
            minimumPayment = dueTotal;
         }
         else
         {
            if (dueTotal * 0.01 > 10)
            {
                minimumPayment = dueTotal * 0.01;
            }
            else
            {
                minimumPayment = 10;
            }
         }
    
        cout << "Your Minimum payment is $" << minimumPayment << ". " << endl;
        cout << "Do you wish to continue calculating for a new account? Type 'N' to quit, any other letter key to continue." << endl;
        cin >> quitFlag;

    } while ((quitFlag != 'N') && (quitFlag != 'n'));
    
    return 0;
}