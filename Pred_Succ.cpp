#include <iostream>
using namespace std;

class node {
    int data;
    public:
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    void insert(int data);
    node* findPredecessor(node* root);
    node* findSuccessor(node* root);
    void Pred_Succ(int key, int & pred, int& succ);
};
//Binary search Tree
void node::insert(int data)
{
    if (data < this->data)
    {
        if (this->left != NULL) {
            this->left->insert(data);
        }
        else {
            this->left = new node(data);
        }
    }
    else if (data > this->data) {
        if (this->right != NULL)
            this->right->insert(data);
        else
            this->right = new node(data);
    }
}

node* node::findPredecessor(node* root)
{
    node* Node = root->left;
    while (Node != NULL && Node->right != NULL) {
        
        Node = Node->right;
    }
    return Node;
}
node* node::findSuccessor(node* root)
{
    node* Node = root->right;
    while (Node != NULL && Node->left != NULL) {
        
        Node = Node->left;
    }
    return Node;
}

void node::Pred_Succ(int key, int & pred, int &succ)
{
    if(this == NULL)
        return ;
    if (key == data) {
        if (left != NULL)
            pred = findPredecessor(this)->data;
        if (right != NULL)
            succ = findSuccessor(this)->data;
        return;
    }
    if (key < data) {
        succ = this->data;
        if (left != NULL)
            left->Pred_Succ(key, pred, succ);
    }
    else if (key > data) {
        pred = this->data;
        if (right != NULL)
            right->Pred_Succ(key, pred, succ);
    }
    
}
int main() {
  int pred = -1;
  int succ = -1;
  int key = 9;
	node * Tree = new node(6);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(8);
	Tree->insert(7);
	Tree->insert(13);
	cout<<"Pred & Succ"<<endl;
	Tree->Pred_Succ(key, pred, succ);
	cout<<pred<<" "<<succ<<endl;
	return 0;
}
