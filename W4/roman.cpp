#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num, thousand, hundred, ten, one;
    string romanNum;

    cout << "Enter decimal number: " << endl;
    cin >> num;

    thousand = num / 1000;
    hundred = (num - thousand * 1000) / 100;
    ten = (num - thousand * 1000 - hundred * 100) / 10;
    one = num - thousand * 1000 - hundred * 100 - ten * 10;
    
    for (int i = thousand; i > 0; --i)
    {
        romanNum += "M";
    }

    for (int i = hundred; i > 0; --i)
    {
        if (i > 5)
        {
            romanNum += "D";
            for (int j = i - 5; j > 0; --j)
            {
                romanNum += "C";
            }
            break;
        }
        else
        {
            romanNum += "C";
        }
    }

    for (int i = ten; i > 0; --i)
    {
        if (i > 5)
        {
            romanNum += "L";
            for (int j = i - 5; j > 0; --j)
            {
                romanNum += "X";
            }
            break;
        }
        else
        {
            romanNum +="X";
        }
    }

    for (int i = one; i > 0; --i)
    {
        if (i > 5)
        {
            romanNum += "V";
            for (int j = i - 5; j > 0; --j)
            {
                romanNum += "I";
            }
            break;
        }
        else
        {
            romanNum +="I";
        }
    }

    cout << num << " is " << romanNum << endl;

    return 0;

}