#include <iostream>
using namespace std;

int main()
{
    int month, day;
    int startMonth, endMonth, startDay, endDay;
    char quitFlag = 'Y';

    do
    {
        cout << "Please enter your birth month: " << endl;
        cin >> month;
        cout << "Please enter your birth day: " << endl;
        cin >> day;
        if (month < 0 || month > 12 || day < 0 || day > 31)
        {
            cout << "What are you thinking?";
        }
        else
        {
            startMonth = 3;
            endMonth = 4;
            startDay = 21;
            endDay = 19;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Aries. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Pisces" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Taurus" << endl;
                }
            }

            startMonth = 4;
            endMonth = 5;
            startDay = 20;
            endDay = 20;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                
                cout << "You horoscope sign is Taurus. " << endl;

                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Aries" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Gemini" << endl;
                }
            }

            startMonth = 5;
            endMonth = 6;
            startDay = 21;
            endDay = 21;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                
                cout << "You horoscope sign is Gemini. " << endl;
                
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Taurus" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Cancer" << endl;
                }
            }

            startMonth = 6;
            endMonth = 7;
            startDay = 22;
            endDay = 22;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Cancer . " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Gemini" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Leo" << endl;
                }
            }

            startMonth = 7;
            endMonth = 8;
            startDay = 23;
            endDay = 22;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Leo. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Cancer" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Virgo" << endl;
                }
            }

            startMonth = 8;
            endMonth = 9;
            startDay = 23;
            endDay = 22;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Virgo. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Leo" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Libra" << endl;
                }
            }

            startMonth = 9;
            endMonth = 10;
            startDay = 23;
            endDay = 22;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Libra. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Virgo" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Scorpio" << endl;
                }
            }

            startMonth = 10;
            endMonth = 11;
            startDay = 23;
            endDay = 21;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Scorpio. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Libra" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Sagittarius" << endl;
                }
            }

            startMonth = 11;
            endMonth = 12;
            startDay = 22;
            endDay = 21;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Sagittarius. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Scorpio" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Capricorn" << endl;
                }
            }

            startMonth = 12;
            endMonth = 1;
            startDay = 22;
            endDay = 19;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Capricorn. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Saggitarius" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Aquarius" << endl;
                }
            }

            startMonth = 1;
            endMonth = 2;
            startDay = 20;
            endDay = 18;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Aquarius. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Capricorn" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Pisces" << endl;
                }
            }

            startMonth = 2;
            endMonth = 3;
            startDay = 19;
            endDay = 20;

            if ((month == startMonth && day > startDay) || (month == endMonth && day < endDay))
            {
                cout << "You horoscope sign is Pisces. " << endl;
                if (day < startDay + 3)
                {
                    cout << "You are on a cusp of Aquarius" << endl;
                }
                else if (day > endDay - 3)
                {
                    cout << "You are on a cusp of Aries" << endl;
                }
            }
        }

    cout << "Quit: type 'N'" << endl;
    cin >> quitFlag;

    } while (quitFlag != 'N' && quitFlag != 'n');
    
    return 0;
}