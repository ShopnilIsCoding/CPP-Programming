#include<bits/stdc++.h>

using namespace std;

struct Student {
    int id;
    string name;
    char section;
    int totalMarks;
};

bool compareStudents(const Student& s1, const Student& s2) {
    if (s1.totalMarks == s2.totalMarks)
        return s1.id < s2.id;
    return s1.totalMarks > s2.totalMarks;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        vector<Student> students(3);
        
        for (int i = 0; i < 3; ++i) {
            cin >> students[i].id >> students[i].name >> students[i].section >> students[i].totalMarks;
        }

        sort(students.begin(), students.end(), compareStudents);

        cout << students[0].id << " " << students[0].name << " " << students[0].section << " " << students[0].totalMarks << endl;
    }

    return 0;
}
