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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp = head;
        int cnt = 1;
        while(temp->next != NULL){
            temp = temp->next;
            cnt++;
        }
        if(cnt == 2){
            return {-1, -1};
        }
        temp = head->next;
        ListNode* prev = head;
        int a = cnt-2;
        vector<int>pos;
        while(a>=1){
            if((temp->val < prev->val && temp->val < temp->next->val) || (temp->val > prev->val && temp->val > temp->next->val)){
                pos.push_back(cnt-a);
            }
            prev = temp;
            temp = temp->next;
            a--;
        }
        if(pos.size() <= 1){
            return {-1, -1};
        }
        if(pos.size() == 2){
            return {pos[1]-pos[0] , pos[1]-pos[0]};
        }
        // vector<int>ans;
        // sort(pos.begin(), pos.end());
        int n = pos.size();
        int mini = INT_MAX;
        int maxi = pos[n-1] - pos[0];
        for(int i = 0; i<pos.size()-1; i++){
            mini = min(mini, pos[i+1]-pos[i]);
        }
        return {mini, maxi};

    }

};