#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node *left, *right;
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

void printLeftPath(Node* root) {
    if (!root) return;
    
    if (root->left) {
        printLeftPath(root->left);
    } else if (root->right) {
        printLeftPath(root->right);
    }
    
    cout << root->val << " ";
}

void printRightPath(Node* root) {
    if (!root) return;
    
    cout << root->val << " ";
    
    if (root->right) {
        printRightPath(root->right);
    } else if (root->left) {
        printRightPath(root->left);
    }
}

void printOuterNodes(Node* root) {
    if (!root) return;
    
    printLeftPath(root->left);
    cout << root->val << " ";
    printRightPath(root->right);
}

int main() {
    Node* root = input_tree();
    
    printOuterNodes(root);
    
    return 0;
}
