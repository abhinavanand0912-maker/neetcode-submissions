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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr=head;
        while(curr != NULL){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        while(fast != NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* first=head;
        ListNode* temp=slow->next;
        slow->next=NULL;
        ListNode* second=reverse(temp);
        while(second!=NULL){
            ListNode* nxt1=first->next;
            ListNode* nxt2=second->next;
            first->next=second;
            second->next=nxt1;
            second=nxt2;
            first=nxt1;
        }
    }
};