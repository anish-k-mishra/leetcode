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
    ListNode* mergeNodes(ListNode* head) {
        int sum = 0;
        vector<int>v;
        ListNode* temp = head->next;
        while(temp != NULL){
            if(temp->val == 0){
                v.push_back(sum);
                sum = 0;
            }
            else{
                sum+= temp->val;
            }
            temp = temp->next;
        }

        ListNode* head1 = new ListNode(v[0]);
        ListNode* temp2 = head1;
        for(int i = 1; i<v.size(); i++){
            temp2->next = new ListNode(v[i]);
            temp2 = temp2->next;
        }
        return head1;
    }
};