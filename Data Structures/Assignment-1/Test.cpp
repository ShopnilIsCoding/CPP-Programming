#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int mid = N / 2;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == mid && j == mid) {
                cout << 'X';  
            } else if (i < mid && j == i) {
                cout << '\\'; 
            } else if (i < mid && j == N - 1 - i) {
                cout << '/';  
            } else if (i > mid && j == N - 1 - i) {
                cout << '/'; 
            } else if (i > mid && j == i) {
                cout << '\\';  
            } else {
                cout << ' ';  
            }
        }
        cout << endl;
    }

    return 0;
}
