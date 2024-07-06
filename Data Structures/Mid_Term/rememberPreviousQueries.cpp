#include <bits/stdc++.h>
using namespace std;

void print_left_to_right(list<int>lst) {
    cout << "L -> ";
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void print_right_to_left(list<int>lst) {
    cout << "R -> ";
    for (auto it = lst.end(); it != lst.begin();) {
        --it;
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> lst;
    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            lst.push_front(V);
        } else if (X == 1) {
            lst.push_back(V);
        } else if (X == 2) {
            if (V >= 0 && V < lst.size()) {
                auto it = next(lst.begin(), V);
                lst.erase(it);
            }
        }

        print_left_to_right(lst);
        print_right_to_left(lst);
    }

    return 0;
}
