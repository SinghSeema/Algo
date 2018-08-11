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
    void MorrisTraversal(node * root);
    node* findPredecessor(node* root);
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
    while (Node != NULL && Node->right != root && Node->right != NULL) {
        
        Node = Node->right;
    }
    return Node;
}
void node::MorrisTraversal(node * root)
{
    while(root != NULL) {
        
        if (root->left == NULL) {
            cout<<root->data<<" ";
            root = root->right;
        }
        else
        {
            node *preD = findPredecessor(root);
            if (preD->right == NULL) {
                preD->right = root;
                root = root->left;
            }
            else {
                preD->right = NULL;
                cout<<root->data<<" ";
                root = root->right;
            }
                
        }
    }
}
int main() {
	node * Tree = new node(6);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(8);
	Tree->insert(7);
	cout<<"Morris Inorder Traversal"<<endl;
	Tree->MorrisTraversal(Tree);
	return 0;
}
