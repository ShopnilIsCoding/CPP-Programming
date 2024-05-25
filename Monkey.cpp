#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        string result = "";
        for (char ch : line) {
            if (ch != ' ') {
                result += ch;
            }
        }
        sort(result.begin(), result.end());
        cout << result << endl;
    }
    return 0;
}
