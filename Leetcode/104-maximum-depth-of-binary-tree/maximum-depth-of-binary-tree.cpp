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
    int maxi = 0;
    void findepth(TreeNode* node,int cnt){
        if(node == NULL){
            maxi = max(maxi,cnt);
            return;
        }
        findepth(node->left,cnt+1);
        findepth(node->right,cnt+1);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        if(root)
        findepth(root,0);
        return maxi;
    }
};