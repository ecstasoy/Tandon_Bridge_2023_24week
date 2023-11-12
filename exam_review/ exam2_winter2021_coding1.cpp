#include <iostream>
#include <vector>
#include <string>

using namespace std;

void readGrade(vector<vector<string>> arrLine, int index);
int findHighest(vector<vector<string>> arrLine, int arrSize);
void findStudents(vector<vector<string>> &arrLine, int highestGrade, int arrSize);

int main() {
    
    int index = 0;
    string inputLine = "";
    vector<vector<string>> inputArr(100);

    cout << "Please enter a non-empty sequence of lines." << endl;
    cout << "Each line should have a student ID and their grade (0-100), separated by a space." << endl;
    cout << "To indicate the end of the input, enter -1 as a student ID:" << endl;
    while (inputLine != "-1") {
        getline(cin, inputLine);
        inputArr[index].push_back(inputLine);
        readGrade(inputArr, index);
        ++index;
    }

    int highestGrade = findHighest(inputArr, index);

    cout << "The highest grade is " << highestGrade << "." << endl;
    findStudents(inputArr, highestGrade, index);

    return 0;    
}

void readGrade(vector<vector<string>> arrLine, int index) {
    int arrSize = arrLine[index][0].size();
    int spaceIndex = arrLine[index][0].find_first_of(" ");
    string studentID = arrLine[index][0].substr(0, spaceIndex);
    string grade = arrLine[index][0].substr(spaceIndex + 1, arrSize - 1);

    arrLine[index][0] = studentID;
    arrLine[index][1] = grade;
}

int findHighest(vector<vector<string>> arrLine, int arrSize) {
    int highest = stoi(arrLine[0][1]);
    
    for (int i = 0; i < arrSize; ++i) {
        int compare = stoi(arrLine[i][1]);
        if (compare > highest) {
            highest = compare;
        }
    }

    return highest;
}

void findStudents(vector<vector<string>> &arrLine, int highestGrade, int arrSize) {
    vector<string> arrID;

    for (int i = 0; i < arrSize; ++i) {
        if (arrLine[i][1] == to_string(highestGrade)) arrID.push_back(arrLine[i][0]);
    }

    if (arrID.size() == 1) {
        cout << "The student with grade " << highestGrade << " is: " << arrID[0];
    } else {
        cout << "The student with grade " << highestGrade << " is: ";
        for (int i = 0; i < arrID.size(); ++i) {
            if (i < arrID.size() - 1) {
                cout << arrID[i] << " ";
            } else {
                cout << arrID[i] << "." << endl;
            }
        }
    }
}