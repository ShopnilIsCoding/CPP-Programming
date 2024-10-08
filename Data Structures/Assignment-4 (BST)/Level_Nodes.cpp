#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node* root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node*> q;
    if (root)
        q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        Node* myLeft;
        Node* myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);

        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

void print_level(Node* root, int level) {
    if (root == NULL) {
        cout << "Invalid" << endl;
        return;
    }

    queue<pair<Node*, int>> q;
    q.push({root, 0});
    bool found = false;

    while (!q.empty()) {
        pair<Node*, int> pr = q.front();
        Node* node = pr.first;
        int current_level = pr.second;
        q.pop();

        if (current_level == level) {
            cout << node->val << " ";
            found = true;
        }

        if (node->left)
            q.push({node->left, current_level + 1});
        if (node->right)
            q.push({node->right, current_level + 1});
    }

    if (!found) {
        cout << "Invalid" << endl;
    } else {
        cout << endl;
    }
}

int main() {
    Node* root = input_tree();
    int level;
    cin >> level;
    
    print_level(root, level);
    
    return 0;
}
