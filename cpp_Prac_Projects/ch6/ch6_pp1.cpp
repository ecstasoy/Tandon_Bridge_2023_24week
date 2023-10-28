#include <iostream>
#include <fstream>
#include <string>

void emailReplace(std::ifstream& inFile, std::ofstream& outFile) {
    std::string line;
    while (std::getline(inFile, line)) {
        if (line.empty()) continue;
        size_t pos = line.find("#N#");
        while(pos != std::string::npos) {
            std::string name;
            std::cin.ignore(1);
            std::cout << "Please enter the name you want to replace with: " << std::endl;
            std::getline(std::cin, name);
            line.replace(pos, 3, name);
            pos = line.find("#N#");
        }
        outFile << line << std::endl;
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
    emailReplace(inFile, outFile);
    inFile.close();
    outFile.close();

    return 0;
}