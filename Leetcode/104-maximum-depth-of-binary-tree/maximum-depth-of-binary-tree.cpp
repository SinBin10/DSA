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
    int findepth(TreeNode* node,int cnt){
        if(node == NULL){
            maxi = max(maxi,cnt);
            return maxi;
        }
        return max(findepth(node->left,cnt+1),findepth(node->right,cnt+1));
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        return findepth(root,0);
    }
};