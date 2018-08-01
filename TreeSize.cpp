#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

    public:
    Node() {}
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    int size(Node* node);
    void insert(int data);
    void inorder();
};

void Node::inorder()
{
    if (left != NULL)
        left->inorder();
    cout<<data<<" ";
    if (right != NULL)
        right->inorder();
}
int Node::size(Node * node)
{
    if (node == NULL)
        return 0;
        
    return (node->size(node->left) + 1 + node->size(node->right));
}

//Binary search Tree
void Node::insert(int data)
{
    if (data < this->data)
    {
        if (this->left != NULL) {
            this->left->insert(data);
        }
        else {
            this->left = new Node(data);
        }
    }
    else if (data >= this->data) {
        if (this->right != NULL)
            this->right->insert(data);
        else {
            this->right = new Node(data);
        }
    }

}
int main() {
	cout<<"create Tree!"<<endl;
	Node * Tree = new Node(6);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(8);
	Tree->insert(7);
	Tree->insert(6);
	Tree->inorder();
	cout<<endl<<"Tree size is "<<Tree->size(Tree)<<endl;
	return 0;
}
