#include <iostream>

using namespace std;

class Student {
public:
    char ID;
    char name[101];
    char section;
    int totalMarks;
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        Student A, B, C;
        cin >> A.ID >> A.name >> A.section >> A.totalMarks;
        cin >> B.ID >> B.name >> B.section >> B.totalMarks;
        cin >> C.ID >> C.name >> C.section >> C.totalMarks;

        Student highestScorer = A;

        if (B.totalMarks > highestScorer.totalMarks || (B.totalMarks == highestScorer.totalMarks && B.ID < highestScorer.ID)) {
            highestScorer = B;
        }

        if (C.totalMarks > highestScorer.totalMarks || (C.totalMarks == highestScorer.totalMarks && C.ID < highestScorer.ID)) {
            highestScorer = C;
        }

        cout << highestScorer.ID << " " << highestScorer.name << " " << highestScorer.section << " " << highestScorer.totalMarks << endl;
    }

    return 0;
}
