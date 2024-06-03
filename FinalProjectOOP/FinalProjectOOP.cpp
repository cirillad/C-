#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class CourseManagement {
private:
    map<string, multimap<string, int>> courses;
    set<string> uniqueStudents;

public:
    void load_from_file(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        string course, student;
        int grade;
        while (file >> course >> student >> grade) {
            add_student_to_course(course, student, grade);
        }
        file.close();
    }

    void save_to_file(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }
        for (const auto& course : courses) {
            for (const auto& student : course.second) {
                file << course.first << " " << student.first << " " << student.second << endl;
            }
        }
        file.close();
    }

    void add_student_to_course(const string& course, const string& student, int grade) {
        if (course.empty() || student.empty()) {
            cerr << "Course or student name cannot be empty!" << endl;
            return;
        }
        courses[course].emplace(student, grade);
        uniqueStudents.insert(student);
    }

    void update_student_grade(const string& course, const string& student, int grade) {
        if (courses.find(course) == courses.end()) {
            cerr << "Course not found!" << endl;
            return;
        }
        auto& students = courses[course];
        auto it = students.find(student);
        if (it == students.end()) {
            cerr << "Student not found in the course!" << endl;
            return;
        }
        it->second = grade;
    }

    void remove_student_from_course(const string& course, const string& student) {
        if (courses.find(course) == courses.end()) {
            cerr << "Course not found!" << endl;
            return;
        }
        auto& students = courses[course];
        auto it = students.find(student);
        if (it == students.end()) {
            cerr << "Student not found in the course!" << endl;
            return;
        }
        students.erase(it);
        if (students.empty()) {
            courses.erase(course);
        }
    }

    void print_courses() const {
        for (const auto& course : courses) {
            cout << "Course: " << course.first << endl;
            for (const auto& student : course.second) {
                cout << "\tStudent: " << student.first << ", Grade: " << student.second << endl;
            }
        }
    }

    void print_unique_students() const {
        cout << "Unique Students:" << endl;
        for (const auto& student : uniqueStudents) {
            cout << "\t" << student << endl;
        }
    }

    void print_students_by_grades() const {
        multimap<int, string, greater<int>> sortedStudents;
        for (const auto& course : courses) {
            for (const auto& student : course.second) {
                sortedStudents.emplace(student.second, student.first);
            }
        }
        cout << "Students by Grades:" << endl;
        for (const auto& entry : sortedStudents) {
            cout << "\tStudent: " << entry.second << ", Grade: " << entry.first << endl;
        }
    }

    void find_student(const string& student) const {
        bool found = false;
        for (const auto& course : courses) {
            auto range = course.second.equal_range(student);
            for (auto it = range.first; it != range.second; ++it) {
                if (it->first == student) {
                    if (!found) {
                        cout << "Student: " << student << endl;
                        found = true;
                    }
                    cout << "\tCourse: " << course.first << ", Grade: " << it->second << endl;
                }
            }
        }
        if (!found) {
            cout << "Student not found!" << endl;
        }
    }
};

void print_file_menu() {
    cout << "\nWork with file:\n";
    cout << "1. Load data from file\n";
    cout << "2. Save data to file\n";
    cout << "3. Back to main menu\n";
    cout << "Enter your choice: ";
}

void print_info_menu() {
    cout << "\nPrint information:\n";
    cout << "1. Print all courses and students\n";
    cout << "2. Print unique students\n";
    cout << "3. Print students by grades\n";
    cout << "4. Find student\n";
    cout << "5. Back to main menu\n";
    cout << "Enter your choice: ";
}

int main() {
    CourseManagement cm;
    int choice;
    string student;
    string filename;

    do {
        cout << "\nCourse Management System Menu:\n";
        cout << "1. Work with file\n";
        cout << "2. Print information\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int fileChoice;
            do {
                print_file_menu();
                cin >> fileChoice;

                switch (fileChoice) {
                case 1:
                    cout << "Enter filename: ";
                    cin >> filename;
                    cm.load_from_file(filename);
                    break;
                case 2:
                    cout << "Enter filename: ";
                    cin >> filename;
                    cm.save_to_file(filename);
                    break;
                case 3:
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    break;
                }
            } while (fileChoice != 3);
            break;
        case 2:
            int infoChoice;
            do {
                print_info_menu();
                cin >> infoChoice;

                switch (infoChoice) {
                case 1:
                    cm.print_courses();
                    break;
                case 2:
                    cm.print_unique_students();
                    break;
                case 3:
                    cm.print_students_by_grades();
                    break;
                case 4:
                    cout << "Enter student name: ";
                    cin >> student;
                    cm.find_student(student);
                    break;
                case 5:
                    break;
                default:
                    cout << "Invalid choice! Please try again.\n";
                    break;
                }
            } while (infoChoice != 5);
            break;
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
