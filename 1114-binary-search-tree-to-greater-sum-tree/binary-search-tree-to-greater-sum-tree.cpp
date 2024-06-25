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
    void solve(TreeNode* &root, int &i){
        if(root == NULL){
            return;
        }
        if(root->left== NULL && root->right == NULL ){
            root->val += i;
            i = root->val;
            return ;
        }
        solve(root->right, i);
        root->val += i;
        
        i = root->val;
        solve(root->left,i);
        
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        int i = 0;
        solve(root, i);
        return root;
    }
};