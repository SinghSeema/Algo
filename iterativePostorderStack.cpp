#include <iostream>
#include <stack>
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
    void iterativePostorder(node *root);

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
void node::iterativePostorder(node *root){
    
    stack<node*>st1 , st2;
    if (root == NULL) return;
    st1.push(root);
    while(!st1.empty())
    {
        st2.push(st1.top());
        root = st2.top();
        st1.pop();
        if (root->left)
            st1.push(root->left);
        if(root->right)
            st1.push(root->right);
        
    }
    while(!st2.empty()) {
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
    
}
int main() {
	node * Tree = new node(6);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(8);
	Tree->insert(7);
	Tree->insert(5);
	cout<<"Iterative Postorder Traversal"<<endl;
	Tree->iterativePostorder(Tree);
	return 0;
}
