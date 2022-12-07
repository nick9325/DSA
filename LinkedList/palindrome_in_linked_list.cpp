class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* c=head, *p=NULL,*n=NULL;
         
        while(c){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;
    }
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL) return true;
        ListNode* s=head;
        ListNode* f=head;
        ListNode* p=NULL;
        while(f and f->next){
            p=s;
            s=s->next;
            f=f->next->next;
        }
        
        p->next=NULL;
        
        s=reverse(s);
        
        f=head;
        while(s and f){
            if(s->val!=f->val) return false;
            s=s->next;
            f=f->next;
        }
        
        return true;
    }
};