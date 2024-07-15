/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return NULL;
        }
        Node* temp = head;
        while(temp != NULL){//making copies and inserting them in between the original and next node
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL){//handling the random pointers
            if(temp->random == NULL){
                temp->next->random = NULL;
            }
            else{
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        Node* headC = new Node(-1);
        Node* res = headC;
        temp = head;
        while(temp!=NULL){//handling the next pointers
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp = temp->next;
        }
        return headC->next;
    }
};