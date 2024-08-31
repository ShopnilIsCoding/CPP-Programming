#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Student {
    string name;
    int roll;
    int marks;

    bool operator<(const Student &other) const {
        if (marks == other.marks) {
            return roll < other.roll;
        }
        return marks > other.marks;
    }
};

int main() {
    int N, Q;
    cin >> N;

    set<Student> students;

    for (int i = 0; i < N; i++) {
        Student s;
        cin >> s.name >> s.roll >> s.marks;
        students.insert(s);
    }

    cin >> Q;
    while (Q--) {
        int command;
        cin >> command;

        if (command == 0) {
            Student s;
            cin >> s.name >> s.roll >> s.marks;
            students.insert(s);
            cout << students.begin()->name << " " << students.begin()->roll << " " << students.begin()->marks << endl;
        } 
        else if (command == 1) {
            if (students.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << students.begin()->name << " " << students.begin()->roll << " " << students.begin()->marks << endl;
            }
        } 
        else if (command == 2) {
            if (students.empty()) {
                cout << "Empty" << endl;
            } else {
                students.erase(students.begin());
                if (students.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << students.begin()->name << " " << students.begin()->roll << " " << students.begin()->marks << endl;
                }
            }
        }
    }

    return 0;
}
