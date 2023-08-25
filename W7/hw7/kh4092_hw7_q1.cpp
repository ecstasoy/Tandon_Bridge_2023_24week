#include <iostream>
#include <string>

using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool checkLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int year, startDay;

    cout<<"Please enter a year (e.g. 2016): "<<endl;
    cin>>year;
    cout<<"Please entera number 1-7 that represents the day in the week";
    cout<<"of 1/1 in that year: "<<endl;
    cin>>startDay;

    printYearCalender(year, startDay);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    const string SPACING = "   ";
    int countDays = 1;
    int returnVal;

    for (int i = 0; i < 7; ++i) {
        if (i == 0) {
            cout<<"Mon\tTue\tWed\tThr\tFri\tSat\tSun"<<endl;
        } else {
            if (i == 1 && startingDay < 7) {
                for (int j = 0; j < startingDay - 1; ++j) {
                    cout<<SPACING<<"\t";
                }
                for (int k = 0; k <= 7 - startingDay; ++k) {
                    cout<<countDays<<"\t";
                    ++countDays;
                }

                cout<<"\n";
            }
            
            for (int k = 0; k < 7; ++k) {
                cout<<countDays<<"\t";
                ++countDays;

                if (countDays > numOfDays) {
                    for (int m = 0; m < 7 - k; ++m) {
                        cout<<"\t"<<SPACING;
                    }
                    returnVal = k + 1;
                    break;
                }
            }

            if (countDays > numOfDays) break;

            cout<<"\n";
        }
    }

    return returnVal;
}

bool checkLeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 ? true : false;
}

void printYearCalender(int year, int startingDay) {
    int dayOfMon;
    string printMon = "";

    for (int month = 1; month <= 12; ++month) {
        switch (month)
        {
        case 1:
            printMon = "January";
            dayOfMon = 31;
            break;
        case 2:
            printMon = "Feburary";
            dayOfMon = checkLeapYear(year) ? 29 : 28;
            break;
        case 3:
            printMon = "March";
            dayOfMon = 31;
            break;
        case 4:
            printMon = "April";
            dayOfMon = 30;
            break;
        case 5:
            printMon = "May";
            dayOfMon = 31;
            break;
        case 6:
            printMon = "June";
            dayOfMon = 30;
            break;
        case 7:
            printMon = "July";
            dayOfMon = 31;
            break;
        case 8:
            printMon = "August";
            dayOfMon = 31;
            break;
        case 9:
            printMon = "September";
            dayOfMon = 30;
            break;
        case 10:
            printMon = "October";
            dayOfMon = 31;
            break;
        case 11:
            printMon = "November";
            dayOfMon = 30;
            break;
        case 12:
            printMon = "December";
            dayOfMon = 31;
            break;
        
        default:
            break;
        }

        cout<<"\n\n"<<printMon<<" "<<year<<endl;
        startingDay = printMonthCalender(dayOfMon, startingDay) + 1;
    }
}