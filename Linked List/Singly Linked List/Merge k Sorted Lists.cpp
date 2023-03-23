class Solution {
public:
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head=NULL;
        ListNode* tail=NULL;
        while(head1&&head2){
            if(head1->val<=head2->val){
                if(!head){
                    head=head1;
                    tail=head;
                }
                else{
                    tail->next=head1;
                    tail=tail->next;
                }
                head1=head1->next;
            }
            else{
                if(!head){
                    head=head2;
                    tail=head;
                }
                else{
                    tail->next=head2;
                    tail=tail->next;
                }
                head2=head2->next;
            }
        }
        while(head1){
            if(!head){
                head=head1;
                tail=head;
            }
            else{
                tail->next=head1;
                tail=tail->next;
            }
            head1=head1->next;
        }
        while(head2){
            if(!head){
                head=head2;
                tail=head;
            }
            else{
                tail->next=head2;
                tail=tail->next;
            }
            head2=head2->next;            
        }
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(lists.empty()) return NULL;
        ListNode* head=lists[0];
        for(int i=1;i<n;i++){
            head=merge(head,lists[i]);
        }
        return head;
    }
};