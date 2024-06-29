#include<bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string S, X;
        getline(cin, S, ' '); 
        getline(cin, X); 

        int pos = 0;
        while ((pos = S.find(X, pos)) != -1) {
            S.replace(pos, X.length(), "#");
            pos += 1; 
        }

        cout << S << endl;
    }

    return 0;
}
