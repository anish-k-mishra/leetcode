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
    TreeNode* postorder(TreeNode* root, set<int>&s, vector<TreeNode*>&ans){
        if(root == NULL){
            return root;
        }
        root->left = postorder(root->left, s, ans);
        root->right = postorder(root->right, s, ans);
        //processing of root
        if(s.find(root->val) != s.end()){
            if(root->left != NULL){
                ans.push_back(root->left);
            }
            if(root->right != NULL){
                ans.push_back(root->right);
            }
            root->left = NULL;
            root->right = NULL;
            return NULL;
        }
        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>s;
        for(int i = 0; i<to_delete.size(); i++){

            s.insert(to_delete[i]);
        }
        vector<TreeNode*>ans;
        TreeNode* head = postorder(root, s, ans);
        if(head != NULL){
            ans.push_back(head);
        }
        return ans;
    }
};