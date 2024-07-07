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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        vector<int>v;
        ListNode* temp = head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int s = v.size()/2;
        int i = 0;
        while(s--){
            swap(v[i], v[i+1]);
            i = i+2;
        }
        ListNode*temp1 = new ListNode(v[0]);
        ListNode* head1 = temp1;
        for(int j = 1; j<v.size(); j++){
            temp1->next = new ListNode(v[j]);
            temp1 = temp1->next;
        }
        return head1;
    }
};