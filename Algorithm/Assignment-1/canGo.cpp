#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {-1, 1, 0, 0}; 
vector<int> dy = {0, 0, -1, 1}; 

bool visited[1005][1005];
vector<string> grid;
int H, W;

bool isValid(int x, int y) {
    return x >= 0 && x < H && y >= 0 && y < W && grid[x][y] != '#' && !visited[x][y];
}

bool bfs(pair<int, int> start, pair<int, int> end) {
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        
        int x = current.first;
        int y = current.second;

        if (x == end.first && y == end.second) {
            return true; 
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return false; 
}

int main() {
    cin >> H >> W;

    grid.resize(H);

    pair<int, int> roomA, roomB;
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == 'A') {
                roomA = {i, j};
            }
            if (grid[i][j] == 'B') {
                roomB = {i, j};
            }
        }
    }
    memset(visited, false, sizeof(visited));

    if (bfs(roomA, roomB)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
