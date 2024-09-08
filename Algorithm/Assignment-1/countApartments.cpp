#include <bits/stdc++.h>
using namespace std;

int n, m;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    if (a[i][j] == '#') return false;
    return true;
}

void bfs(int si, int sj) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    
    while (!q.empty()) {
        pair<int, int> par = q.front();
        q.pop();
        int x = par.first, y = par.second;

        for (int i = 0; i < 4; i++) {
            int ci = x + directions[i].first;
            int cj = y + directions[i].second;

            if (valid(ci, cj) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int apartmentCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                apartmentCount++;
                bfs(i, j);
            }
        }
    }

    cout << apartmentCount << endl;

    return 0;
}
