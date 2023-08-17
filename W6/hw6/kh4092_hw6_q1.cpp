#include <iostream>

int fib(int n);

int main() {
    using namespace std;

    int num, fibNum;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>num;

    fibNum = fib(num);

    cout<<fibNum<<endl;
}

int fib(int n) {
    int add1 = 1, add2 = 1, temp;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        for (int i = 3; i <= n; ++i) {
            temp = add1 + add2;
            add1 = add2;
            add2 = temp;
        }

        return temp;
    }
}