#include<bits/stdc++.h>
using namespace std;

int main() {
    

    int q;
    cin >> q;

    queue<string> line;

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 0) {
            string name;
            cin >> name;
            line.push(name);
        } else if (type == 1) {
            if (line.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << line.front() << endl;
                line.pop();
            }
        }
    }

    return 0;
}
