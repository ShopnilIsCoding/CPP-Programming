#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node *next;
    Node *prev;
    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, string val) {
    Node *newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

Node* find_address(Node* head, const string& address) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == address) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    string val;
    
    // Read input until "end"
    while (true) {
        cin >> val;
        if (val == "end") break;
        insert_tail(head, tail, val);
    }
    
    int Q;
    cin >> Q;
    cin.ignore(); 

    Node* current = head;
    string command;
    
    while (Q--) {
        getline(cin, command);
        if (command.substr(0, 6) == "visit ") {
            string address = command.substr(6);
            Node* node = find_address(head, address);
            if (node) {
                current = node;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "next") {
            if (current->next) {
                current = current->next;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "prev") {
            if (current->prev) {
                current = current->prev;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }
    
    return 0;
}
