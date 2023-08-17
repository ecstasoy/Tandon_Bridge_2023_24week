#include <iostream>

double eApprox (int n);

int main() {
    using namespace std;

    int n;

    cout.precision(30);

    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }

    return 0;
}

double eApprox (int n) {
    
    if (n == 1) return 1;

    double factorial = 1;
    double approxSum = 1;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        approxSum += 1.0 / factorial;
    }

    return approxSum;
}