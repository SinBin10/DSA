/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void firstances(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>&v, bool &c){
        if(root == NULL || c == true)
        return;
        v.push_back(root);
        if(root == p || root == q){
            c = true;
            return;
        }
        firstances(root->left,p,q,v,c);
        firstances(root->right,p,q,v,c);
    }
    void checkifdesc(TreeNode* p, TreeNode* q, bool &check){
        if(p == NULL || check == true)
        return;
        if(p == q){
            check = true;
            return;
        }
        checkifdesc(p->left,q,check);
        checkifdesc(p->right,q,check);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v;
        bool check = false;
        bool c = false;
        firstances(root, p, q, v, c);
        for(int i = 0;i<v.size();i++){
            cout<<v[i]->val<<",";
        }
        bool somecheck = false;
        while(v.size()>0){
            if(v.back() == q || somecheck == true){
                somecheck = true;
                checkifdesc(v.back(),p,check);
            }
            else 
            checkifdesc(v.back(),q,check);
            if(check == true)
            break;
            v.pop_back();
        }
        return v.back(); 
    }
};