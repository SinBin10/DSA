/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int check(TreeNode* root, bool &c){
        if(root == NULL)
        return 0;
        int left = check(root->left,c);
        int right = check(root->right,c);
        if(abs(left-right)>1)
        c = false;
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
        return true;
        bool c = true;
        int ch = check(root,c);
        return c;
    }
};