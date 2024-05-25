#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(const vector<int>& arr, int N, int S) {
    for (int i = 0; i < N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j) {
            for (int k = j + 1; k < N; ++k) {
                if (arr[i] + arr[j] + arr[k] == S) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, S;
        cin >> N >> S;

        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i];
        }

        if (isPossible(arr, N, S)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
