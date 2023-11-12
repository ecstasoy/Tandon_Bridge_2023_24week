#include <iostream>
#include <vector>

int main() {
    std::cout << "Please enter a non-empty sequence of lines." << std::endl;
    std::cout << "Each line should have a student ID and their grade (0-100), separated by a space." << std::endl;
    std::cout << "To indicate the end of the input, enter -1 as a student ID:" << std::endl;

    int highest_grade = -1;
    std::vector<int> highest_grade_students;

    while (true) {
        int student_id, grade;
        std::cin >> student_id;

        if (student_id == -1) {
            break;
        }

        std::cin >> grade;

        if (grade > highest_grade) {
            highest_grade = grade;
            highest_grade_students.clear();
            highest_grade_students.push_back(student_id);
        } else if (grade == highest_grade) {
            highest_grade_students.push_back(student_id);
        }
    }

    std::cout << "The highest grade is " << highest_grade << "." << std::endl;
    std::cout << "The students with grade " << highest_grade << " are: ";

    for (size_t i = 0; i < highest_grade_students.size(); ++i) {
        std::cout << highest_grade_students[i];
        if (i < highest_grade_students.size() - 1) {
            std::cout << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
