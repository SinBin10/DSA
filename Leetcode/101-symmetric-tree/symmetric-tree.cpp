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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        return true;
        stack<TreeNode*> st;
        st.push(root->right);
        st.push(root->left);
        while(!st.empty()){
            TreeNode* node1 = st.top();
            st.pop();
            TreeNode* node2 = st.top();
            st.pop();
            if(node1 == NULL && node2 == NULL)
            continue;
            if(node1 == NULL || node2 == NULL)
            return false;
            if(node1->val != node2->val)
            return false;
            st.push(node1->left);
            st.push(node2->right);
            st.push(node1->right);
            st.push(node2->left);
        }
        return true;
    }
};