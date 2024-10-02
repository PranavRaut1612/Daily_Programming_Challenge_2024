#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr) {
            return root;
        }

        return left != nullptr ? left : right;
    }
};

int main() {
    Solution solution;

    // Constructing the tree based on input root = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes p = 5 and q = 1
    TreeNode* p = root->left;   // Node with value 5
    TreeNode* q = root->right;  // Node with value 1

    // Find LCA
    TreeNode* lca = solution.lowestCommonAncestor(root, p, q);
    if (lca) {
        cout << "Lowest Common Ancestor: " << lca->val << endl;
    } else {
        cout << "No common ancestor found." << endl;
    }

    return 0;
}
