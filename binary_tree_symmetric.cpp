#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;
        if (!t1 || !t2) return false;
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

    Solution solution;
    bool result = solution.isSymmetric(root);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
