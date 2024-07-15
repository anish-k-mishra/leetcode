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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        set<int>s;
        unordered_map<int, TreeNode*>m;
        for(auto i:descriptions){
            if(m[i[0]] == 0){
                m[i[0]] = new TreeNode(i[0]);
            }
            if(m[i[1]] == 0){
                m[i[1]] = new TreeNode(i[1]);
            }
            if(i[2] == 1){
                m[i[0]]->left = m[i[1]];
            }
            else{
                m[i[0]]->right = m[i[1]];
            }
            s.insert(i[1]);
        }
        for(auto i:descriptions){
            if(s.find(i[0]) == s.end()){
                return m[i[0]]; 
            }
        }
        return NULL;
    }
};