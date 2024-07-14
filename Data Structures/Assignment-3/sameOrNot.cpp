#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    stack<int> s;
    queue<int> q;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        s.push(val);
    }

    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        q.push(val);
    }

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    bool same = true;
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            same = false;
            break;
        }
        s.pop();
        q.pop();
    }

    if (same && s.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
