#include <iostream>

void printDivisors(int num);

int main() {
    using namespace std;

    int num;

    cout<<"Please enter a positive integer >= 2: "<<endl;
    cin>>num;

    printDivisors(num);

    return 0;
}

void printDivisors(int num) {
    using namespace std;

    for (int i = 1; i <= sqrt(num); ++i) {
        if (num % i == 0) cout<<i<<" ";
    }

    for (int j = sqrt(num) - 1; j > 0; --j) {
        if (num % j == 0) cout<<num / j<<" ";
    }
}