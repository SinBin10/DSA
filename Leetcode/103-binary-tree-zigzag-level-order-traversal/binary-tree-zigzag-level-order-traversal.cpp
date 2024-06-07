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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<vector<int>> ans;
        if(root == NULL)
        return ans;
        st1.push(root);
        ans.push_back({root->val});
        while(!st1.empty() || !st2.empty()){
            while(!st1.empty()){
                if(st1.top()->left != NULL)
                st2.push(st1.top()->left);
                if(st1.top()->right != NULL)
                st2.push(st1.top()->right);
                st1.pop();
            }
            vector<int> v;
            while(!st2.empty()){
                st1.push(st2.top());
                v.push_back(st2.top()->val);
                st2.pop();
            }
            if(v.size()!=0){
                if(ans.size() % 2 == 0)
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
    }
};