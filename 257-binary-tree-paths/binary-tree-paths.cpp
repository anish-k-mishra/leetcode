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
    void solve(TreeNode* root, vector<string>& ans, string st){
        if(root == NULL){
            return;
        }
        st= st + to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            // st.pop_back();
            // st.pop_back();
            ans.push_back(st);
        }
        else{
            st+="->";
            solve(root->left, ans, st);
            solve(root->right, ans, st);
        }

        // st.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string st = "";
        vector<string>ans;
        solve(root, ans, st);
        return ans;
    }
};