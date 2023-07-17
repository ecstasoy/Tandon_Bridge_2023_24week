#include <iostream>
using namespace std;

int main()
{
    int tempCelcius;
    int tempFahrenheit;

    for (tempCelcius = 100; (tempCelcius + 273) >= 0; tempCelcius--)
    {
        tempFahrenheit = (9 * tempCelcius) / 5 + 32;

        if (tempCelcius == tempFahrenheit)
        {
            cout << tempCelcius << " in Celcius = " << tempFahrenheit << " in Fahrenheit" << endl;
        }
    }

    return 0;
}