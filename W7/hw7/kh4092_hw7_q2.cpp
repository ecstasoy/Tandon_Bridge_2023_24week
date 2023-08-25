#include <iostream>
#include <cmath>

using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main(){
    int num, countDivs = 0, sumDivs = 0, temp;

    cout<<"Please enter a positive number: "<<endl;
    cin>>num;

    cout<<"All the perfect numbers between 2 and "<<num<<": "<<endl;
    for(int i = 2; i <= num; ++i){
        if (isPerfect(i)) cout<<i<<endl;
    }

    cout<<"All pairs of amicable numbers that are between 2 and "<<num<<": "<<endl;
    for(int i = 2; i <= num; ++i){
        analyzeDivisors(i, countDivs, sumDivs);
        temp = sumDivs;
        analyzeDivisors(temp, countDivs, sumDivs);
        if(i == sumDivs && sumDivs < temp && temp < num) {
            cout<<i<<" & "<<temp<<endl;
        }
    }

    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs){
    outCountDivs = 0;
    outSumDivs = 0;
    int n = sqrt(num);
    for(int j = 1; j <= n; ++j){
        if (num % j == 0){
            outSumDivs += (j + num / j);
            ++outCountDivs;
        }
    }
    if(n * n == num){
        outSumDivs -= (n + num);
        outCountDivs = outCountDivs * 2 - 1;
    } else {
        outSumDivs -= num;
        outCountDivs *= outCountDivs * 2;
    }
}

bool isPerfect(int num){
    int outCountDivs = 0, outSumDivs = 0;
    analyzeDivisors(num, outCountDivs, outSumDivs);
    if (outSumDivs == num) {
        return true;
    } else {
        return false;
    }
}