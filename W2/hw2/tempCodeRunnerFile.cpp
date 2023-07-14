#include <iostream>
using namespace std;

int main()
{
    int inputA, inputB;
    int outputAdd, outputSubtract, outputMultiply, outputDivideInt, outputModulo;
    double outputDivide;

    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>inputA>>inputB;

    outputAdd = inputA + inputB;
    outputSubtract = inputA - inputB;
    outputMultiply = inputA * inputB;
    outputDivideInt = inputA / inputB;
    outputModulo = inputA % inputB;
    outputDivide = (double) inputA / (double) inputB;

    cout<<inputA<<" + "<<inputB<<" = "<<outputAdd<<endl;
    cout<<inputA<<" - "<<inputB<<" = "<<outputSubtract<<endl;
    cout<<inputA<<" * "<<inputB<<" = "<<outputMultiply<<endl;
    cout<<inputA<<" / "<<inputB<<" = "<<outputDivide<<endl;
    cout<<inputA<<" div "<<inputB<<" = "<<outputDivideInt<<endl;
    cout<<inputA<<" mod "<<inputB<<" = "<<outputModulo<<endl;

    return 0;
}