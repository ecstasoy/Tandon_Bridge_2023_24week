#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double fluidWeight = 62.4;
    double objectWeight, objectVolume, buoyantForce, objectRadius;

    cout << "Please enter the weight of the sphere in pounds: " << endl;
    cin >> objectWeight;
    cout << "Please enter the radius of the sphere in feets: " << endl;
    cin >> objectRadius;

    objectVolume = (4.0 / 3.0) * M_PI * pow(objectRadius, 3);
    buoyantForce = objectVolume * fluidWeight;

    if (buoyantForce >= objectWeight)
    {
        cout << "Float." << endl;
    }
    else
    {
        cout << "Sink." << endl;
    }

    return 0;
}