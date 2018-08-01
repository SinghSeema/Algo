#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;
    int height;

    public:
    Node() {}
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
        height = 1;
    }
    
    Node* insert(Node * root, int data);
    void inorder(Node * root);
    int max(int a, int b);
    int heightNode(Node* node);
    int getBalancer(Node *node);
    Node* leftRotate();
    Node* rightRotate();
    
};

void Node::inorder(Node* root) {

    if (root != NULL) {
        inorder(root->left);
        cout<<root->data<<"->"<<root->height<<" ";
        inorder(root->right);
    }
        
}

int Node::heightNode(Node* node) {
   if (node == NULL ) {
        return 0;
   }
    return node->height;
}

int Node::getBalancer(Node* node) {
    if (node == NULL)
        return 0;
    return ( heightNode(node->left)- heightNode(node->right));
}
int Node::max(int a, int b) {
    return a>b?a:b;
}

Node* Node::leftRotate() {
    Node* newRoot = right;
    right = newRoot->left;
    newRoot->left = this;
    height = 1+max(heightNode(left), heightNode(right));
    newRoot->height = 1+max(heightNode(newRoot->left), heightNode(newRoot->right));
    return newRoot;
    
}

Node* Node::rightRotate()
{
    Node* newRoot = left;
    left = newRoot->right;
    newRoot->right = this;
    height = 1+max(heightNode(left), heightNode(right));
    newRoot->height = 1+max(heightNode(newRoot->left), heightNode(newRoot->right));

    return newRoot;
}

Node* Node::insert(Node* root ,int data)
{
    if (root == NULL) 
        return (new Node(data));
    else if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
   else 
        return root;
    root->height = 1 + max(heightNode(root->left), heightNode(root->right));
    int balance = getBalancer(root);
    // left-left case
    if (balance > 1 && data < root->left->data) {
        cout<<"right rotate"<<endl;
        return root->rightRotate();
    }//right-right case
    else if (balance < -1 && data > root->right->data) {
        cout<<"left rotate"<<endl;
        return root->leftRotate();
    } // left-right case
    else if (balance > 1 && data > root->left->data) {
        root->left = root->left->leftRotate();
        return root->rightRotate();
    }
    // right -left case
    else if (balance < -1 && data < root->right->data) {
        root->right = root->right->rightRotate();
        return root->leftRotate();
    }
    return root;
   
}

int main() {
	cout<<"create Tree!"<<endl;
	Node Tree;
	Node *root = NULL;
	root = Tree.insert(root, 6);
	root = Tree.insert(root, 8);
	root = Tree.insert(root, 7);
	root = Tree.insert(root, 9);
	cout<<"AVL tree traversal"<<endl;
	Tree.inorder(root);
	return 0;
}
