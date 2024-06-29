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
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

bool areListsEqual(Node *head1, Node *head2) {
    Node *current1 = head1;
    Node *current2 = head2;

    while (current1 != NULL && current2 != NULL) {
        if (current1->val != current2->val) {
            return false;
        }
        current1 = current1->next;
        current2 = current2->next;
    }

    if (current1 == NULL && current2 == NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val;

    while (true) {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head1, tail1, val);
    }

    while (true) {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head2, tail2, val);
    }

    if (areListsEqual(head1, head2)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
