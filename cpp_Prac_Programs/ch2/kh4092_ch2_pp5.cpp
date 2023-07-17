#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double radius, vm;

    cout << "Enter radius of a sphere: " << endl;
    cin >> radius;

    vm = (4.0 / 3.0) * M_PI * pow(radius, 3);

    cout << "The volume of the sphere is: " << vm <<endl;

    return 0;
}