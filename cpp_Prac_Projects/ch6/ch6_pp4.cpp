#include <iostream>
#include <fstream>
#include <string>

double wordLengthStats(std::ifstream& inFile) {
    std::string line, word;
    int wordCount = 0, charCount = 0;
    while(std::getline(inFile, line)) {
        for(int i = 0; i < line.length(); ++i) {
            if(isalpha(line[i])) word += line[i];

            if(i == line.length() - 1 || line[i+1] == ' ' || line[i+1] == ',' || line[i+1] == '.') {
                ++wordCount;
                charCount += word.length();
                word.clear();
            }
        }
    }

    double average = static_cast<double>(charCount) / wordCount;

    return average;
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

int main() {
    std::ifstream inFile;

    openInputFile(inFile);
    double average = wordLengthStats(inFile);

    std::cout << std::fixed << std::setprecision(2) << average << std::endl;

    inFile.close();

    return 0;
}