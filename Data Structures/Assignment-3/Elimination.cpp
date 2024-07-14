#include<bits/stdc++.h>
using namespace std;

bool canEliminateAll( string str) {
    stack<char> s;
    for (char c : str) {
        if (!s.empty() && s.top() == '0' && c == '1') {
            s.pop();
        } else {
            s.push(c);
        }
    }
    return s.empty();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        if (canEliminateAll(str)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
