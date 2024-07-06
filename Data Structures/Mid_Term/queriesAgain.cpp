#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print_left_to_right(Node *head) {
    cout << "L -> ";
    Node *tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_right_to_left(Node *tail) {
    cout << "R -> ";
    Node *tmp = tail;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void insert_head(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insert_tail(Node *&head, Node *&tail, int val) {
    Node *newNode = new Node(val);
    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insert_at_position(Node *&head, Node *&tail, int pos, int val) {
    if (pos == 0) {
        insert_head(head, tail, val);
        return;
    }

    Node *newNode = new Node(val);
    Node *tmp = head;
    int i;
    for (i = 0; i < pos - 1 && tmp != NULL; i++) {
        tmp = tmp->next;
    }

    if (tmp == NULL) {
        cout << "Invalid" << endl;
        delete newNode;
        return;
    }

    newNode->next = tmp->next;
    newNode->prev = tmp;

    if (tmp->next != NULL) {
        tmp->next->prev = newNode;
    } else {
        tail = newNode;
    }

    tmp->next = newNode;
}

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    int Q;
    cin >> Q;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        int current_size = 0;
        Node *tmp = head;
        while (tmp != NULL) {
            current_size++;
            tmp = tmp->next;
        }

        if (X < 0 || X > current_size) {
            cout << "Invalid" << endl;
        } else {
            insert_at_position(head, tail, X, V);
            print_left_to_right(head);
            print_right_to_left(tail);
        }
    }

    return 0;
}
