#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing a student
class Student {
public:
    Student(string first_name, string last_name, int student_id)
        : first_name(first_name), last_name(last_name), student_id(student_id) {}

    string getFirstName() const { return first_name; }
    string getLastName() const { return last_name; }
    int getStudentID() const { return student_id; }

private:
    string first_name;
    string last_name;
    int student_id;
};

// Class representing an assignment
class Assignment {
public:
    Assignment(string name, int total_points)
        : name(name), total_points(total_points) {}

    string getName() const { return name; }
    int getTotalPoints() const { return total_points; }

private:
    string name;
    int total_points;
};

// Class representing the Gradebook
class Gradebook {
public:
    // Method to add a new student to the class
    void addStudent(string first_name, string last_name, int student_id) {
        students.push_back(Student(first_name, last_name, student_id));
    }

    // Method to add a new assignment to the class
    void addAssignment(string name, int total_points) {
        assignments.push_back(Assignment(name, total_points));
    }

    // Method to give a student a grade for an assignment
    void giveGrade(int student_id, string assignment_name, int grade) {
        // Find student and assignment indices
        int student_index = -1;
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getStudentID() == student_id) {
                student_index = i;
                break;
            }
        }

        int assignment_index = -1;
        for (size_t i = 0; i < assignments.size(); ++i) {
            if (assignments[i].getName() == assignment_name) {
                assignment_index = i;
                break;
            }
        }

        // If both student and assignment are found, give grade
        if (student_index != -1 && assignment_index != -1) {
            grades[student_index][assignment_index] = grade;
        }
    }

    // Method to print out a formatted report showing all students and grade information
    void printReport() {
        // Print header
        cout << setw(10) << "StudentID" << setw(15) << "First Name" << setw(15) << "Last Name";
        for (const auto& assignment : assignments) {
            cout << setw(15) << assignment.getName();
        }
        cout << endl;

        // Print grades for each student
        for (size_t i = 0; i < students.size(); ++i) {
            cout << setw(10) << students[i].getStudentID() << setw(15) << students[i].getFirstName() << setw(15) << students[i].getLastName();
            for (size_t j = 0; j < assignments.size(); ++j) {
                cout << setw(15) << grades[i][j];
            }
            cout << endl;
        }
    }

private:
    vector<Student> students;
    vector<Assignment> assignments;
    vector<vector<int>> grades; // 2D vector to store grades
};

// Example usage
int main() {
    // Create a Gradebook
    Gradebook gradebook;

    // Add students
    gradebook.addStudent("John", "Doe", 1001);
    gradebook.addStudent("Jane", "Smith", 1002);
    gradebook.addStudent("Alice", "Johnson", 1003);

    // Add assignments
    gradebook.addAssignment("Assignment 1", 100);
    gradebook.addAssignment("Assignment 2", 100);
    gradebook.addAssignment("Final Exam", 200);

    // Give grades
    gradebook.giveGrade(1001, "Assignment 1", 85);
    gradebook.giveGrade(1001, "Assignment 2", 90);
    gradebook.giveGrade(1001, "Final Exam", 180);

    gradebook.giveGrade(1002, "Assignment 1", 75);
    gradebook.giveGrade(1002, "Assignment 2", 80);
    gradebook.giveGrade(1002, "Final Exam", 190);

    gradebook.giveGrade(1003, "Assignment 1", 95);
    gradebook.giveGrade(1003, "Assignment 2", 85);
    gradebook.giveGrade(1003, "Final Exam", 195);

    // Print report
    gradebook.printReport();

    return 0;
}
