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
private:
    ListNode *temp;
public:
    Solution(ListNode* head) {
        temp=head;
    }
    
    int getRandom() {
       int index=0,ans;
       ListNode *curr=temp;
       while(curr!=NULL)
       {
           index++;
           if(rand()%index==0)
           {
               ans=curr->val;
           }
           curr=curr->next;
       }
       return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */