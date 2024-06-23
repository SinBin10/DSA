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
        vector<int> ans;
        map<int,int> mp;
        stack<pair<int,TreeNode*>> st1;
        stack<pair<int,TreeNode*>> st2;
        st1.push({0,root});
        mp[0] = root->val;
        while(!st1.empty()){
            while(!st1.empty()){
                TreeNode* node = st1.top().second;
                int col = st1.top().first;
                if(node->left!=NULL){
                    st2.push({col+1,node->left});
                    mp[col+1] = node->left->val;
                }
                if(node->right!=NULL){
                    st2.push({col+1,node->right});
                    mp[col+1] = node->right->val;
                }
                st1.pop();
            }
            while (!st2.empty()) {
                TreeNode* node = st2.top().second;
                if(node!=NULL)
                st1.push(st2.top());
                st2.pop();
            }
        }
        for(auto it:mp)
        ans.push_back(it.second);
        return ans;
    }
};