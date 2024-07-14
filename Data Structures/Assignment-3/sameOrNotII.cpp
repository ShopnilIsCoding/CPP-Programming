#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack {
public:
    Node* head;
    Node* tail;
    int sz;
    myStack() {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    void pop() {
        if (sz == 0) return;
        sz--;
        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL) {
            head = NULL;
        } else {
            tail->next = NULL;
        }
        delete deleteNode;
    }
    int top() {
        if (tail == NULL) return -1; 
        return tail->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};

class myQueue {
public:
    Node* front;
    Node* rear;
    int sz;
    myQueue() {
        front = NULL;
        rear = NULL;
        sz = 0;
    }
    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void pop() {
        if (sz == 0) return;
        sz--;
        Node* deleteNode = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete deleteNode;
    }
    int getFront() {
        if (front == NULL) return -1; 
        return front->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return sz == 0;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    myStack st;
    myQueue q;

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        st.push(val);
    }

    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        q.push(val);
    }

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    bool same = true;
    while (!st.empty() && !q.empty()) {
        if (st.top() != q.getFront()) {
            same = false;
            break;
        }
        st.pop();
        q.pop();
    }

    if (same && st.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
