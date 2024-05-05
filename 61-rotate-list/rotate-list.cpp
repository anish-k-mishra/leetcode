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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head -> next == NULL){
            return head;
        }
        int cnt = 1;

        ListNode* tail = head;
        while (tail->next !=NULL){
            tail = tail->next;
            cnt++;
        }

        ListNode* curr = tail;
        ListNode* prev = head;
        while (prev->next != curr){
            prev = prev->next;
        }
        int s = k%cnt;
        while(s--){
            curr->next = head;
            prev->next = NULL;
            tail = prev;
            head = curr;
            curr= tail;
            prev = head;
            while(prev ->next != curr){
                prev = prev->next;
            }
            // k--;

        }
        return head;
        
    }
};