#include<bits/stdc++.h>
using namespace std;

int main() {
    list<int> linkedList;
    int value;
    while (cin >> value && value != -1) {
        linkedList.push_back(value);
    }
    linkedList.sort();
    linkedList.unique(); 
    linkedList.sort();
    
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
        if (it != linkedList.begin()) {
            cout << " ";
        }
        cout << *it;
    }
    
    return 0;
}
