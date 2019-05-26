#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
    public:
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    void insert(int data);
    bool find(int data);
    Node* delete_node(int data);
    void inorder();
    Node* min();
    
};
void Node::insert(int data) {
    if(data < this->data) {
        if ( left != NULL)
            left->insert(data);
        else
            left = new Node(data);
        
    }
    else if (data >= this->data) {
        if(right != NULL)
            right->insert(data);
        else
            right = new Node(data);
        
    }
}
void Node::inorder() {
    if(left != NULL)
        left->inorder();
    cout<<data<<" ";
    if(right != NULL)
        right->inorder();
        
}
Node* Node::min() {
    if (left == NULL) {
        return this;
    }
    return left->min();
}
bool Node::find(int data) {
    if (data == this->data)
        return true;
    else if (data < this->data) {
        if (left == NULL)
            return false;
        else
        left->find(data);
        
    }
    else if (data > this->data) {
        if(right == NULL)
            return false;
        else 
        right->find(data);
        
    }

}

Node* Node::delete_node(int data) {
    if (data < this->data) {
        if (left != NULL) {
            left = left->delete_node(data);
        }
            
    }
    else if (data > this->data) {
        if (right != NULL) {
            right = right->delete_node(data);
        }
    }
    else {
        if (left == NULL && right == NULL) {
            delete this;
            return NULL;
        }
        else if (left != NULL && right == NULL) {
            Node * tmp = this->left;
            delete this;
            return tmp;
        }
        else if (right != NULL && left == NULL) {
            Node* tmp = this->right;
            delete this;
            return tmp;
        }
        else {
            Node* minNode = right->min();
            this->data = minNode->data;
            right = right->delete_node(minNode->data);
        }
        
    }
    return this;

}


int main() {
	cout<<"create Tree!"<<endl;
	Node * Tree = new Node(6);
	Tree->insert(3);
	Tree->insert(1);
	Tree->insert(8);
	Tree->insert(7);
	Tree->insert(9);
	Tree->inorder();
	Tree->delete_node(8);
	cout<<endl<<"Tree Traversal after delete"<<endl;
	Tree->inorder();
	
	return 0;
}
