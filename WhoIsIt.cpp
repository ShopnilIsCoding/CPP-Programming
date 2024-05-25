#include<bits/stdc++.h>

using namespace std;

class Student {
public:
    int id;
    string name;
    char section;
    int totalMarks;
    Student(int id, string name, char section, int totalMarks) {
        this->id = id;
        this->name = name;
        this->section = section;
        this->totalMarks = totalMarks;
    }
};
bool compareStudents(const Student& a, const Student& b) {
    if (a.totalMarks != b.totalMarks)
        return a.totalMarks > b.totalMarks;
    return a.id < b.id;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<Student> students;
        for (int i = 0; i < 3; ++i) {
            int id, totalMarks;
            string name;
            char section;
            cin >> id >> name >> section >> totalMarks;
            students.push_back(Student(id, name, section, totalMarks));
        }
        sort(students.begin(), students.end(), compareStudents);
        cout << students[0].id << " " << students[0].name << " " << students[0].section << " " << students[0].totalMarks << endl;
    }

    return 0;
}
