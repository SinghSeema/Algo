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
    
    stack<node*>st;
    while(root != NULL || !st.empty())
    {
        if(root != NULL) {
            st.push(root);
            root = root->left;
        }
        else {
            node *tmp = st.top();
            if (st.top()->right == NULL) {
                cout<<tmp->data<<" ";
                st.pop();
                while(!st.empty() && tmp == st.top()->right){
                    tmp = st.top();
                    cout<<tmp->data<<" ";
                    st.pop();
                    
                }
            } else {
                root = tmp->right;
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
	Tree->insert(5);
	cout<<"Iterative Postorder Traversal"<<endl;
	Tree->iterativePostorder(Tree);
	return 0;
}
