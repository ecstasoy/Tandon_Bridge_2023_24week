#include <iostream>
#include <vector>
#include <random>
#include <chrono>

std::vector<int> findMinMax(std::vector<int>& vec, int low, int high) {
    if (low == high) {
        return {vec[low], vec[low]};
    } else if (low == high - 1) {
        if (vec[low] < vec[high]) {
            return {vec[low], vec[high]};
        } else {
            return {vec[high], vec[low]};
        }
    }

    int mid = (low + high) / 2;
    std::vector<int> leftRes = findMinMax(vec, low, mid);
    std::vector<int> rightRes = findMinMax(vec, mid + 1, high);

    return {std::min(leftRes[0], rightRes[0]), std::max(leftRes[1], rightRes[1])};
}

std::vector<int> findMinMax(std::vector<int>& vec) {
    return findMinMax(vec, 0, vec.size() - 1);
}

int main() {
    int vecSize, lowerBound, upperBound;

    std::cout << "The size of sample vector: ";
    std::cin >> vecSize;
    std::cout << "Lower bound of the range: ";
    std::cin >> lowerBound;
    std::cout << "Upper bound of the range: ";
    std::cin >> upperBound;

    std::vector<int> sampleVec;

    std::random_device rd;
    std::mt19937 g(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(lowerBound, upperBound);

    for (int i = 0; i < vecSize; ++i) sampleVec.push_back(dist(g));

    std::cout << "The randomized sequence is: {";
    for (int j = 0; j < vecSize; ++j) {
        if (j == vecSize - 1) {
            std::cout << sampleVec[j];
        } else {
            std::cout << sampleVec[j] << ", ";
        }
    }
    std::cout << "}" << std::endl;

    std::vector<int> minMax = findMinMax(sampleVec);
    std::cout << "Minimum: " << minMax[0] << "; ";
    std::cout << "Maximum: " << minMax[1] << std::endl;

    return 0;
}