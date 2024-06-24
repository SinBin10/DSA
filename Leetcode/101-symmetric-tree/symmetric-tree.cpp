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
    bool check(TreeNode* goingleft, TreeNode* goingright){
        if(goingleft==NULL && goingright == NULL)
        return true;
        if(goingleft == NULL || goingright == NULL)
        return false;
        if(goingleft->val!=goingright->val)
        return false;
        if(check(goingleft->left,goingright->right) == false || check(goingleft->right,goingright->left) == false)
        return false;
        else
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        TreeNode* goingleft = root;
        TreeNode* goingright = root;
        return check(goingleft,goingright);
        
    }
};