#include <iostream>
#include <string>
using namespace std;

struct Teacher {
    string name;
    int age;
};

struct Student {
    string name;
    int age;
    float score;
};

struct Course {
    Teacher teacher;
    Student students[25];

    Teacher* teacherPtr;
    Student* studentPtr[25];

    int studentCount;
};

int main() {

    Course course;

    // Teacher information
    course.teacher.name = "Mr. Sok";
    course.teacher.age = 35;

    // Point to the teacher
    course.teacherPtr = &course.teacher;

    // Number of students
    course.studentCount = 3;

    // Student 1
    course.students[0].name = "Dara";
    course.students[0].age = 20;
    course.students[0].score = 85.5;

    // Student 2
    course.students[1].name = "Liza";
    course.students[1].age = 21;
    course.students[1].score = 91.0;

    // Student 3
    course.students[2].name = "Sophea";
    course.students[2].age = 20;
    course.students[2].score = 78.5;

    // Point to each student
    for (int i = 0; i < course.studentCount; i++) {
        course.studentPtr[i] = &course.students[i];
    }

    // =========================
    // Display Course Information
    // =========================

    cout << "==========================================" << endl;
    cout << "            COURSE INFORMATION" << endl;
    cout << "==========================================" << endl;

    // Teacher
    cout << endl;
    cout << "Teacher" << endl;
    cout << "------------------------------" << endl;
    cout << "Name : " << course.teacherPtr->name << endl;
    cout << "Age  : " << course.teacherPtr->age << endl;

    // Students
    cout << endl;
    cout << "Students (" << course.studentCount << "/25)" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; i < course.studentCount; i++) {

        cout << endl;
        cout << i + 1 << ". " << course.studentPtr[i]->name << endl;
        cout << "   Age   : " << course.studentPtr[i]->age << endl;
        cout << "   Score : " << course.studentPtr[i]->score << endl;
    }

    cout << endl;
    cout << "==========================================" << endl;

    return 0;
}