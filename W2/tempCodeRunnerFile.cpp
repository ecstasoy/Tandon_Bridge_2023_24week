#include <iostream>
using namespace std;

 int main()
 {
    double inputTemp, outputTemp;

    cout<<"Enter a temperature in Fahrenheit: \n"<<endl;
    cin>>inputTemp;

    outputTemp = (5.0 / 9.0) * (inputTemp - 32.0);


    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout<<"\n"<<inputTemp<<"F can be converted into "<<outputTemp<<"C. "<<endl;

    return 0;
 }