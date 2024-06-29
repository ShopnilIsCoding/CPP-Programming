#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}


int findMaxMinDifference(Node *head) {
    if (head == NULL) {
        return 0;
    }

    int min_val = head->val;
    int max_val = head->val;

    Node *current = head->next;
    while (current != NULL) {
        if (current->val < min_val) {
            min_val = current->val;
        }
        if (current->val > max_val) {
            max_val = current->val;
        }
        current = current->next;
    }

    return max_val - min_val;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    while (true) {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }

    int difference = findMaxMinDifference(head);
    cout << difference << endl;

    Node *current = head;
    while (current != NULL) {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
