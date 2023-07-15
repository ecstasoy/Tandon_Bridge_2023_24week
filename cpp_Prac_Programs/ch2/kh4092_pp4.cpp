#include <iostream>
#include <string>
using namespace std;

int main()
{
    int number;
    string instructor, name, food, adj, color, animal;

    cout << "Please follow the prompt to enter the items: " << endl;
    cout << "The first or last name of your instructor: " << endl;
    cin >> instructor;
    cout << "Your name: " << endl;
    cin >> name;
    cout << "A food" << endl;
    cin >> food;
    cout << "A number between 100 and 120" << endl;
    cin >> number;
    cout << "An adjective" << endl;
    cin >> adj;
    cout << "A color" << endl;
    cin >> color;
    cout << "An animal" << endl;
    cin >> animal;

    cout << "\nDear Instructor " << instructor << ", " << endl;
    cout << "\nI am sorry that I am unable to turn in my homework at this time. First, " << endl;
    cout << "I ate a rotten "<< food << ", which made me turn " << color << " and extremely ill. I" << endl;
    cout << "came down with a fever of "<<number<<". Next, my " << adj << " pet" << endl;
    cout << animal << " must have smelled the remains of the " << food << " on my homework," << endl;
    cout << "because he ate it. I am currently rewriting my homework and" << endl;
    cout << "hope you will accept it late." << endl;
    cout << "\n\nSincerely,\n" << name << "\n" << endl;

    return 0;
}