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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m, vector<int>(n, -1));\
        ListNode* temp = head;
        int tr = 0, tc = 0, br = m-1, bc = n-1;
        while(temp!=NULL){
            for(int col = tc; col<= bc; col++){
                if(temp == NULL){
                    break;
                }
                v[tr][col] = temp->val;
                temp = temp->next;
            }
            tr++;
            for(int row = tr; row<= br; row++){
                if(temp == NULL){
                    break;
                }
                v[row][bc] = temp->val;
                temp = temp->next;
            }
            bc--;
            for(int col = bc; col>= tc; col--){
                if(temp == NULL){
                    break;
                }
                v[br][col] = temp->val;
                temp = temp->next;
            }
            br--;
            for(int row = br; row>=tr; row--){
                if(temp == NULL){
                    break;
                }
                v[row][tc] = temp->val;
                temp = temp->next;
            }
            tc++;
        }
        return v;
    }
};