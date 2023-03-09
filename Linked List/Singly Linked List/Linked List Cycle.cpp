/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slowP=head,*fastP=head;
        
        while(fastP!=NULL && fastP->next!=NULL)
        {
            slowP=slowP->next;
            fastP=fastP->next->next;
            if(slowP==fastP) return true;
        }
        return false;
    }
};