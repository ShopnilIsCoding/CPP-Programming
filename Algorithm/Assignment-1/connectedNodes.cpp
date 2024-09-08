#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
    int N, E;
    cin >> N >> E;
    
    vector<vector<int>> adj(N);
    
    
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }
    
    int Q;
    cin >> Q;
    
    
    for (int i = 0; i < Q; ++i) {
        int node;
        cin >> node;
        
        if (adj[node].empty()) {
            cout << "-1" << endl;
        } else {
           
            sort(adj[node].begin(), adj[node].end(), greater<int>());
            
           
            for (int neighbor : adj[node]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
