#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<long long> prefixSums(N);
    prefixSums[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefixSums[i] = prefixSums[i - 1] + A[i];
    }
    for (int i = N - 1; i >= 0; --i) {
        cout << prefixSums[i];
        if (i > 0) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
