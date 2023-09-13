#include <iostream>
#include <vector>

void main1(const int* arr, int num, int arrSize);
void main2(const int* arr, int num, int arrSize);

    const int MAX_SIZE = 100;

int main() {
    int* arr = new int[MAX_SIZE];
    int currNum, num, arrSize = 0;

    std::cout << "Please enter a sequence of positive integers, each in a separate line." << std::endl;
    std::cout << "End your input by typing -1." << std::endl;

    while (std::cin >> currNum)
    {
        if (currNum == -1) break;
        arr[arrSize] = currNum;
        ++arrSize;
    }

    std::cout << "Please enter a number you want to search." << std::endl;
    std::cin >> num;

    main1(arr, num, arrSize);
    std::cout << "\n";
    main2(arr, num, arrSize);
    delete[] arr;
    
    return 0;
}

void main1(const int* arr, int num, int arrSize) {
    int* lineArr = new int[MAX_SIZE];
    int currLine = 1, curr = 0;

    for (int i = 0; i < arrSize; ++i) {
        if (num == arr[i]) {
            currLine = i + 1;
            lineArr[curr] = currLine;
            ++curr;
        }
    }

    std::cout << num << " shows in lines ";

    for (int i = 0; i < curr; ++i) {
        if (i < curr - 1) {
            std::cout << lineArr[i] << ", ";
        } else {
            std::cout << lineArr[i] << ".";
        }
    }

    delete[] lineArr;
}

void main2(const int* arr, int num, int arrSize) {
    std::vector<int> lineArr;

    for (int i = 0; i < arrSize; ++i) {
        if (num == arr[i]) lineArr.push_back(i + 1);
    }

    std::cout << num << " shows in lines ";

    for (int i = 0; i < lineArr.size(); ++i) {
        if (i < lineArr.size() - 1) {
            std::cout << lineArr[i] << ", ";
        } else {
            std::cout << lineArr[i] << ".";
        }
    }
}