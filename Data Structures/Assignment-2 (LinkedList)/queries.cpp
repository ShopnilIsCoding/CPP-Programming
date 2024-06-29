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

void insert_head(Node *&head, int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_tail(Node *&head, int val) {
    Node *newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
    } else {
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void delete_at_index(Node *&head, int index) {
    if (head == NULL)
        return;
    
    if (index == 0) {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    Node *current = head;
    int count = 0;
    while (current != NULL && count < index - 1) {
        current = current->next;
        count++;
    }
    
    if (current == NULL || current->next == NULL)
        return;
    
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
}

void print_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    Node *head = NULL;

    for (int i = 0; i < Q; ++i) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insert_head(head, V);
        } else if (X == 1) {
            insert_tail(head, V);
        } else if (X == 2) {
            delete_at_index(head, V);
        }

        print_list(head);
    }

    return 0;
}
