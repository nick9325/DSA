class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* evenstart=head->next,*odd=head,*even=head->next,*temp=head;
        
        while(odd->next!=NULL){

            odd->next=even->next;
            if(odd->next!=NULL)
                odd=odd->next;
            
            if(even->next!=NULL){
                even->next=odd->next;
                even=even->next;
            }

        }

        odd->next=evenstart;
        return head;
    }
};