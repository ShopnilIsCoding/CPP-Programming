#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, Q;
    cin >> N;

    set<int> elements;
    map<int, int> count_map;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        elements.insert(x);
        count_map[x]++;
    }

    cin >> Q;
    while (Q--) {
        int command;
        cin >> command;

        if (command == 0) {
            int X;
            cin >> X;
            elements.insert(X);
            count_map[X]++;
            cout << *elements.begin() << endl;
        } 
        else if (command == 1) {
            if (elements.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << *elements.begin() << endl;
            }
        } 
        else if (command == 2) {
            if (elements.empty()) {
                cout << "Empty" << endl;
            } else {
                int min_element = *elements.begin();
                count_map[min_element]--;
                
                if (count_map[min_element] == 0) {
                    elements.erase(min_element);
                    count_map.erase(min_element);
                }

                if (elements.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << *elements.begin() << endl;
                }
            }
        }
    }

    return 0;
}
