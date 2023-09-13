#include <iostream>
#include <string>
#include <vector>

std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
void printStrArray(std::string* arr, int size);

int main() {
    int outWordsArrSize = 0;
    std::string inputSentence;
    std::string* outputArr;

    std::cout << "Please enter a sentence separated by a single space: " << std::endl;
    getline(std::cin, inputSentence);

    outputArr = createWordsArray(inputSentence, outWordsArrSize);
    std::cout << "The array has a size of " << outWordsArrSize << ": " << std::endl;
    printStrArray(outputArr, outWordsArrSize);
    delete[] outputArr;

    return 0;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize) {
    int startPos = 0, endPos = 0, arrSize = 1, index = 0;

    while ((index = sentence.find(' ', index)) < sentence.length()) {
        ++arrSize;
        ++index;
    }
    std::string* outArr = new std::string [arrSize];
    std::string wordStr;

    for (int i = 0; i < arrSize; ++i) {
        endPos = sentence.find_first_of(' ', startPos);
        if (sentence.find_first_of(' ', startPos) == -1) endPos = sentence.length();
        wordStr = sentence.substr(startPos, endPos - startPos);
        startPos = endPos + 1;
        outArr[i] = wordStr;
        wordStr = "";
    }

    outWordsArrSize = arrSize;
    return outArr;
}

void printStrArray(std::string* arr, int size) {  
    std::cout<<"[";
    for (int i = 0; i < size; ++i) {
        std::cout<<"\""<<arr[i]<<"\"";
        if (i < size - 1) std::cout<<", ";
    }
    std::cout<<"]"<<std::endl;
}