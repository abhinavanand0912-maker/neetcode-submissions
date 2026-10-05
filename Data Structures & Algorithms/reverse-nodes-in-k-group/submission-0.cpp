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
    ListNode* reverse(ListNode* temp){
        ListNode* prev=NULL;
        ListNode* curr=temp;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;
        while(temp!=NULL){
            ListNode* last=temp;
            int cnt=1;
            while(last!=NULL && cnt<k){
                last=last->next;
                cnt++;
            }
            if(last==NULL) break;
            ListNode* right=last->next;
            last->next=NULL;
            ListNode* newhead=reverse(temp);
            if(temp==head){
                head=newhead;
            } else {
                prevlast->next=newhead;
            }
            prevlast=temp;
            temp->next=right;
            temp=right;
        }
        return head;
    }
};
