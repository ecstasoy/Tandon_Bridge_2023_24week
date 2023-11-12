#include <iostream>

using namespace std;

int findIndex(int S[], int x, int left, int right);

int main() {
    int S1[8] = {10, 15, 20, 25, 28, 40, 55, 90};

    cout << findIndex(S1, 39, 0, 7) << endl;

    return 0;
}

int findIndex(int S[], int x, int left, int right) {
    if (left == right) return -1;

    int mid = (left + right) / 2;

    if (S[mid] == x) {
        return mid;
    } else if (S[mid] > x) {
        return findIndex(S, x, left, mid);
    } else {
        return findIndex(S, x, mid + 1, right);
    }
}