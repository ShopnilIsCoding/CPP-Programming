#include<bits/stdc++.h>
using namespace std;

int main() {
    int MAX_SIZE = 100005; 
    char line[MAX_SIZE];

    while (cin.getline(line, MAX_SIZE)) {
        int len = strlen(line);
        sort(line, line + len);
        for (int i = 0; i < len; ++i) {
            if (line[i] != ' ') {
                cout << line[i];
            }
        }
        
        cout << endl;  
    }

    return 0;
}
