#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) {
        int n;
        cin >> n;  
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        set<int> s(arr.begin(), arr.end());
        for (auto it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
