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

int find_index(Node *head, int X) {
    int index = 0;
    Node *current = head;
    while (current != NULL) {
        if (current->val == X) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        Node *head = NULL;
        Node *tail = NULL;
        int val;

        while (true) {
            cin >> val;
            if (val == -1)
                break;
            insert_tail(head, tail, val);
        }

        int X;
        cin >> X;

        int result = find_index(head, X);
        cout << result << endl;

        Node *current = head;
        while (current != NULL) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    return 0;
}
