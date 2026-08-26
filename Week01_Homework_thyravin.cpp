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

    course.teacher.name = "Mr. Sok";
    course.teacher.age = 35;

    course.teacherPtr = &course.teacher;

    course.studentCount = 3;

    int studentCount=3;
    Student student[studentCount] = {{"Dara", 20, 85.5}, {"Liza", 21, 91.0}, {"Sophea", 20, 78.5}};
    for (int i = 0; i < studentCount; i++) {
        course.students[i] = student[i];
    }
    for (int i = 0; i < course.studentCount; i++) {
        course.studentPtr[i] = &course.students[i];
    }
    cout << "==========================================" << endl;
    cout << "            COURSE INFORMATION" << endl;
    cout << "==========================================" << endl;

    cout << endl;
    cout << "Teacher" << endl;
    cout << "------------------------------" << endl;
    cout << "Name : " << course.teacherPtr->name << endl;
    cout << "Age  : " << course.teacherPtr->age << endl;

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