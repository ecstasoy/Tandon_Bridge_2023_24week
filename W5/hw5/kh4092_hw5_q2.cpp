#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int num, guess, lower = 1, upper = 100, count = 5;

    srand(time(0));
    num = (rand() % 100) + 1;

    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

    do
    {
        cout<<"Range: ["<<lower<<", "<<upper<<"], Number of guesses left: "<<count<<endl;
        cout<<"Your guess: ";
        cin>>guess;
        if (guess < num) {
            cout<<"Wrong! My number is bigger."<<endl;
            lower = guess + 1;
            --count;
        }
        if (guess > num) {
            cout<<"Wrong! My number is smaller."<<endl;
            upper = guess - 1;
            --count;
        }
        if (guess == num) {
            cout<<"Congrats! You guessed my number in "<<(6 - count)<<" guesses"<<endl;
        }
    } while (guess != num && count > 0);

    if (count == 0) {
        cout<<"Out of guesses! My number is "<<num<<endl;
    }

    return 0;
}