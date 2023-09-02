#include <iostream>
#include <string>

int main(){
    using namespace std;

    string firstName, lastName, middleInitial;

    cout<<"Please enter your name in the following format: "<<endl;
    cout<<"first name, middle name or initial, last name."<<endl;
    cin>>firstName>>middleInitial>>lastName;

    cout<<lastName<<", "<<firstName<<" "<<middleInitial[0]<<".";

    return 0;
}