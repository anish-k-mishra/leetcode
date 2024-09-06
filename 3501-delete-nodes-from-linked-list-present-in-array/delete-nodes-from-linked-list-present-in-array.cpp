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
    bool check(int val, vector<int>& v){
        if(v[val] == 1){
            return true;
        }
        return false;
    }
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int>v(100001, 0);
        for(int i = 0; i<nums.size(); i++){
            v[nums[i]] = 1;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            if(check(curr->val, v)){
                if(curr == head){
                    prev = curr;
                    curr = curr->next;
                    prev->next = NULL;
                    head = curr;
                }
                else if(curr->next == NULL){
                    prev->next = NULL;
                    curr = curr->next;
                }
                else{
                    prev->next = curr->next;
                    curr->next = NULL;
                    curr = prev->next;
                }
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};