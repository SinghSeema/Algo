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
   // bool find(int data);
    void inorder();
    int max();
    int min();
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
void node::inorder()
{
    if (left != NULL)
        left->inorder();
    cout<<data<<endl;
    if (right != NULL)
        right->inorder();
}
int node::max()
{
    if (right != NULL)
        return right->max();
    return data;
}
int node::min()
{
    if (left != NULL)
        return left->min();
    return data;
}

int main() {
	cout<<"create Tree!";
	node * Tree = new node(6);
	Tree->insert(3);
	Tree->insert(2);
	Tree->insert(8);
	Tree->insert(7);
	Tree->insert(1);
	Tree->insert(0);
	Tree->inorder();
	cout<<"Tree Max"<<endl;
	cout<<Tree->max()<<endl;
	cout<<"Tree Min"<<endl<<Tree->min()<<endl;
	
	return 0;
}
