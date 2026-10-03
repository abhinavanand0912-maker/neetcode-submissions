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
    struct compare{
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL) pq.push(lists[i]);
        }
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(!pq.empty()){
            ListNode* k=pq.top();
            pq.pop();
            curr->next=k;
            curr=curr->next;
            if(k->next !=NULL){
                pq.push(k->next);
            }
        }
        return dummy->next;
    }
};
