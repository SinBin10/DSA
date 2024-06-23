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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
        return {};
        int row = 1;
        vector<int> ans;
        map<int,int> mp;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        mp[0] = root->val;
        while(!st1.empty()){
            while(!st1.empty()){
                TreeNode* node = st1.top();
                if(node->left!=NULL){
                    st2.push(node->left);
                    mp[row] = node->left->val;
                }
                if(node->right!=NULL){
                    st2.push(node->right);
                    mp[row] = node->right->val;
                }
                st1.pop();
            }
            while (!st2.empty()) {
                TreeNode* node = st2.top();
                if(node!=NULL)
                st1.push(st2.top());
                st2.pop();
            }
            ++row;
        }
        for(auto it:mp)
        ans.push_back(it.second);
        return ans;
    }
};