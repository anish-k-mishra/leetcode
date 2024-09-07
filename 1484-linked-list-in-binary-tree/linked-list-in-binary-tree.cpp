/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool dfs(ListNode* node, TreeNode* root){
        if(node == NULL){
            return true;
        }
        if(root == NULL){
            return false;
        }
        if(node->val != root->val){
            return false;
        }
        return dfs(node->next, root->left) || dfs(node->next, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL){
            return false;
        }
        if(head->val == root->val){
            if(dfs(head, root)){
                return true;
            }
        }
        return isSubPath(head, root->left) || isSubPath(head, root->right);

    }
};