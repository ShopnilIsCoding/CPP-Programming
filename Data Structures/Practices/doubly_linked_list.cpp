#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(Node * head)
{
    Node *temp = head;
    while (temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_reverse(Node * tail)
{
    Node *temp = tail;  
    while (temp!= NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void insert(Node * head,int pos,int data)
{
    Node *new_node = new Node(data);
    Node *tmp=head;
    for(int i=1;i<=pos-1;i++)
    {
        tmp=tmp->next;
    }
    new_node->next=tmp->next;
    tmp->next=new_node;
    new_node->next->prev=new_node;
    new_node->prev=tmp;
}
int size(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp!= NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int main()
{
    Node* head=new Node(10);
    Node* a=new Node(20);
    Node* b=new Node(30);
    Node *c=new Node(40);
    Node *tail=c;

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = c;
    c->prev = b;
    cout<<"Enter inserting Position & Value: ";
    int pos, data;
    cin>>pos>>data;
    if(pos>=size(head))
    {
        cout << "Invalid position" << endl;
    }
    else{
        insert(head, pos, data);
    }
    
    print(head);
    print_reverse(tail);

    return 0;
}