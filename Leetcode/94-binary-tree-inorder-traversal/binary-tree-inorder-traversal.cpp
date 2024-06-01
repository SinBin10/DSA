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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
        return {};
        stack<TreeNode*> st;
        vector<int> v;
        while(!st.empty()|| v.size() == 0){
            while(root!=NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top()->right;
            v.push_back(st.top()->val);
            st.pop();
            if(root!=NULL){
                st.push(root);
                root = root->left;
            }
        }
        return v;
    }
};