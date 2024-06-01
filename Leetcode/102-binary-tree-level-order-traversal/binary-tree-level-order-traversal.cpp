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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == NULL)
        return v;
        stack<TreeNode*> st1,st2;
        st1.push(root);
        v.push_back({root->val});
        while(!st1.empty()){
            vector<int> ans;
            while(!st1.empty()){
                if(st1.top()->left != NULL){
                    st2.push(st1.top()->left);
                    ans.push_back(st2.top()->val);
                }
                if(st1.top()->right != NULL){
                    st2.push(st1.top()->right);
                    ans.push_back(st2.top()->val);
                }
                st1.pop();
            }
            if(ans.size()!=0)
            v.push_back(ans);
            while(!st2.empty()){
                st1.push(st2.top());
                st2.pop();
            }
        }
        return v;
    }
};