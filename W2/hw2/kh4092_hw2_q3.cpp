#include <iostream>
using namespace std;

int main()
{
    int johnDays, johnHours, johnMinutes;
    int billDays, billHours, billMinutes;
    int days, hours, minutes, totalMinutes;

    cout<<"Please enter the number of days John has worked: ";
    cin>>johnDays;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>johnHours;
    cout<<"Please enter the number of days John has worked: ";
    cin>>johnMinutes;

    cout<<"Please enter the number of days Bill has worked: ";
    cin>>billDays;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>billHours;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>billMinutes;

    totalMinutes = (johnDays + billDays) * 60 * 24 + (johnHours + billHours)
                    * 60 + johnMinutes + billMinutes;
    days = totalMinutes / (60 * 24);
    hours = (totalMinutes - days * 60 * 24) / 60;
    minutes = totalMinutes - days * 60 * 24 - hours * 60;

    cout<<"The total time both of them worked together is: "
        <<days<<" days, "<<hours<<" hours and "<<minutes<<" minutes.";

    return 0;
}