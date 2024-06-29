#include <bits/stdc++.h>
using namespace std;
int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    string word;
    bool foundJessica = false;
    while (ss >> word) {
        if (word == "Jessica") {
                foundJessica = true;
                break;
        }
    }
    if (foundJessica) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
