/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (node == NULL){
            return;
        }
        ListNode* temp = node;
        ListNode* n = temp->next;
        while(temp->next->next != NULL){

            temp->val = n->val;
            temp = temp->next;
            n = n->next;
        }
        temp->val = n->val;
        temp->next = NULL;

    }
};