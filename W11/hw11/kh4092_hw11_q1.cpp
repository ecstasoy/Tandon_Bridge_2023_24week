#include <iostream>
#include <cmath>

void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main() {
    int n;

    std::cout << "Please enter an positive integer: " << std::endl;
    std::cin >> n;

    std::cout << "\n1. printTriangle(): " << std::endl;
    printTriangle(n);
    std::cout << "\n2. printOppositeTriangles(): " << std::endl;
    printOppositeTriangles(n);
    std::cout << "\n3. printRuler(): " << std::endl;
    printRuler(n);

    return 0;
}

void printTriangle(int n) {
    if (n == 0) {
        return;
    }

    printTriangle(n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void printOppositeTriangles(int n) {
    if (n == 0) {
        return;
    }
    for (int i = n; i > 0; --i) {
        std::cout << "*";
    }
    std::cout << std::endl;

    printOppositeTriangles(n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}

void printRuler(int n) {
    if (n - 1 > 0) printRuler(n - 1);
    for (int i = 0; i < n; ++i) std::cout << "-";
    std::cout << std::endl;
    if (n - 1 > 0) printRuler(n - 1);
}