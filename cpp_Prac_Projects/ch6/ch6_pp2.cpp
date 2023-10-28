#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void readFile(std::ifstream& inFile, std::ofstream& outFile) {
    std::string line;
    while(std::getline(inFile, line)) {
        if (line.empty()) continue;

        std::istringstream is(line);
        std::string lastName, firstName, score;
        int sum = 0;
        int count = 0;

        is >> lastName >> firstName;
        while(is >> score) {
            sum += std::stoi(score);
            ++count;
        }
        double average = sum / count;
        outFile << lastName << " " << firstName << " " << average << std::endl;
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
    readFile(inFile, outFile);

    inFile.close();
    outFile.close();

    return 0;
}