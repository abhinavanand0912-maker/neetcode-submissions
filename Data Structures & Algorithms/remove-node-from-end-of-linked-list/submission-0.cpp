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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        if (n == count) return head->next;
        int k=count-n;
        temp=head;
        while(k>1){
            temp=temp->next;
            k--;
        }
        ListNode* nxt=temp->next->next;
        temp->next=nxt;
        return head;
    }
};
