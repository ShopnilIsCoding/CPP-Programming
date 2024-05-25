#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        line.erase(line.find_last_not_of(" ") + 1);

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
