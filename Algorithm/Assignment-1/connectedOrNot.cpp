#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, E, Q;
    cin >> N >> E;

    vector<vector<bool>> graph(N, vector<bool>(N, false));

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        if (u != v) {
            graph[v][u] = true;
        }
    }

    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        if (graph[A][B]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
