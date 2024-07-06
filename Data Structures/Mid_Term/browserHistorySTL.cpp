#include <bits/stdc++.h>
using namespace std;

int main() {
    list<string> webAddresses;
    string val;
    
    while (true) {
        cin >> val;
        if (val == "end") break;
        webAddresses.push_back(val);
    }
    
    int Q;
    cin >> Q;
    cin.ignore(); 

    auto current = webAddresses.begin();
    string command;
    
    while (Q--) {
        getline(cin, command);
        if (command.substr(0, 6) == "visit ") {
            string address = command.substr(6);
            auto it = find(webAddresses.begin(), webAddresses.end(), address);
            if (it != webAddresses.end()) {
                current = it;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "next") {
            if (next(current) != webAddresses.end()) {
                ++current;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "prev") {
            if (current != webAddresses.begin()) {
                --current;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }
    
    return 0;
}
