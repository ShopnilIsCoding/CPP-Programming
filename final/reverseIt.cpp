#include<bits/stdc++.h>

using namespace std;

class Student {
public:
    string name;
    int cls;
    char section;
    int id;

    Student() {}

    Student(string name, int cls, char section, int id) {
        this->name = name;
        this->cls = cls;
        this->section = section;
        this->id = id;
    }
};

int main() {
    int N;
    cin >> N;

    Student students[N];

    for (int i = 0; i < N; ++i) {
        string name;
        int cls;
        char section;
        int id;
        cin >> name >> cls >> section >> id;
        students[i] = Student(name, cls, section, id);
    }

    for (int i = 0; i < N / 2; ++i) {
        char temp = students[i].section;
        students[i].section = students[N - i - 1].section;
        students[N - i - 1].section = temp;
    }

    for (int i = 0; i < N; ++i) {
        cout << students[i].name << " " << students[i].cls << " " << students[i].section << " " << students[i].id << endl;
    }

    return 0;
}
