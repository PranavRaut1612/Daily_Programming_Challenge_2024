#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(NULL), right(NULL) {}
};

bool isBSTUtil(Node* node, int min, int max) {
    if (node == NULL)
        return true;
    
    if (node->data <= min || node->data >= max)
        return false;
    
    return isBSTUtil(node->left, min, node->data) &&
           isBSTUtil(node->right, node->data, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

Node* createSampleTree() {
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    return root;
}

int main() {
    Node* root = createSampleTree();
    
    if (isBST(root))
        cout << "The tree is a Binary Search Tree (BST)" << endl;
    else
        cout << "The tree is NOT a Binary Search Tree (BST)" << endl;
    
    return 0;
}
