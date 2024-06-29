#include<bits/stdc++.h>

using namespace std;

class Student {
public:
    string name;
    int cls;
    char section;
    int id;
    int math_marks;
    int eng_marks;

    Student() {}

    Student(string name, int cls, char section, int id, int math_marks, int eng_marks) {
        this->name = name;
        this->cls = cls;
        this->section = section;
        this->id = id;
        this->math_marks = math_marks;
        this->eng_marks = eng_marks;
    }
};

bool compareStudents( Student a,  Student b) {
    if (a.eng_marks != b.eng_marks) {
        return a.eng_marks > b.eng_marks; 
    } else if (a.math_marks != b.math_marks) {
        return a.math_marks > b.math_marks; 
    } else {
        return a.id < b.id; 
    }
}

int main() {
    int N;
    cin >> N;

    Student students[N];

    for (int i = 0; i < N; ++i) {
        string name;
        int cls, id, math_marks, eng_marks;
        char section;
        cin >> name >> cls >> section >> id >> math_marks >> eng_marks;
        students[i] = Student(name, cls, section, id, math_marks, eng_marks);
    }

    sort(students, students + N, compareStudents);
    for (int i = 0; i < N; ++i) {
        cout << students[i].name << " " << students[i].cls << " " << students[i].section << " "
             << students[i].id << " " << students[i].math_marks << " " << students[i].eng_marks << endl;
    }

    return 0;
}
