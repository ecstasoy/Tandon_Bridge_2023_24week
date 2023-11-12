#include <iostream>
#include <vector>
#include <string>

using namespace std;

void recHighestID(vector<string> &IDHighest, string lineID, int &highestGrade, int Grade);
void printRes(vector<string> IDHighest, int highesGrade);

int main() {
    vector<string> IDHighest;
    string inputLineID;
    int highestGrade = 0, inputGrade;

    cout << "Please enter a non-empty sequence of lines. " << endl;
    cout << "Each line should have a student ID and their grade (0-100), separated by a space." << endl;
    cout << "To indicate the end of the input, enter -1 as a student ID:" << endl;
    while (true) {
        cin >> inputLineID;
        if (inputLineID == "-1") break;
        cin >> inputGrade;
        recHighestID(IDHighest, inputLineID, highestGrade, inputGrade);
    }

    printRes(IDHighest, highestGrade);

    return 0;
}

void recHighestID(vector<string> &IDHighest, string lineID, int &highestGrade, int Grade) {
    if (Grade >= highestGrade) {
        highestGrade = Grade;
        IDHighest.push_back(lineID);
    }
}

void printRes(vector<string> IDHighest, int highesGrade) {
    int size = IDHighest.size();

    cout << "The highest grade is " << highesGrade << "." << endl;
    cout << " The students with grade " << highesGrade << " are: ";

    for (int i = 0; i < size; ++i) {
        if (i < size - 1) {
            cout << IDHighest[i] << " ";
        } else {
            cout << IDHighest[i] << "." << endl;
        }
    }
}