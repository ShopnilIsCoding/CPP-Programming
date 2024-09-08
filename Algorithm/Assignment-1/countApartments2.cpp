#include <bits/stdc++.h>
using namespace std;

char a[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return false;
    if (a[i][j] == '#') return false;
    return true;
}
int dfs(int si, int sj) {
    vis[si][sj] = true;
    int roomCount = 1; 
    for (int i = 0; i < 4; i++) {
        int ci = si + directions[i].first;
        int cj = sj + directions[i].second;
        if (valid(ci, cj) && !vis[ci][cj]) {
            roomCount += dfs(ci, cj);
        }
    }
    return roomCount;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(vis, false, sizeof(vis));

    vector<int> apartmentRooms;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                int roomCount = dfs(i, j); 
                apartmentRooms.push_back(roomCount);
            }
        }
    }

    if (apartmentRooms.empty()) {
        cout << 0 << endl;
    } else {
        sort(apartmentRooms.begin(), apartmentRooms.end()); 
        for (int rooms : apartmentRooms) {
            cout << rooms << " ";
        }
        cout << endl;
    }

    return 0;
}
