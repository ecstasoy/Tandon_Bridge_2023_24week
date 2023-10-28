#include <iostream>
#include <fstream>
#include <string>

void numberLines(std::ifstream& inFile, std::ofstream& outFile) {
    std::string line;
    int lineNum;

    while(std::getline(inFile, line)) {
        ++lineNum;

        size_t startPos = line.find_first_not_of(" \t");
        if (startPos != std::string::npos) {
            line = line.substr(startPos);
        }

        std::cout << std::setw(3) << lineNum << ": " << line << std::endl;
        outFile << std::setw(3) << lineNum << ": " << line << std::endl;
    }
}

void openInputFile(std::ifstream& inFile) {
	std::string fileName;
	std::cout << "What file name would you like to open: ";
	std::cin >> fileName;
	inFile.open(fileName);
	while (!inFile) {
		std::cout << "Bad file name!" << std::endl;
		std::cout << "What file name would you like to open: ";
		std::cin >> fileName;
		inFile.clear();
		inFile.open(fileName);
	}
}

void openOutputFile(std::ofstream& outFile) {
    std::string fileName;
    std::cout << "What file name would you like to output: ";
	std::cin >> fileName;
    outFile.open(fileName);
}

int main() {
    std::ifstream inFile;
    std::ofstream outFile;
    openInputFile(inFile);
    openOutputFile(outFile);
    numberLines(inFile, outFile);

    return 0;
}