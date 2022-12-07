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
    
    ListNode* reverse(ListNode* &head){
        ListNode* p=NULL;
        ListNode* c=head;
        ListNode* n;
        
        while(c!=NULL){
            n=c->next;
            c->next=p;
            p=c;
            c=n;
        }
        return p;        
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        
        if(head==NULL ||(left==1 and right==1)) return head;
        int cnt=0;
        
        ListNode* newhead=NULL;
        ListNode* newtail=NULL;
        ListNode* l=NULL;
        ListNode* r=NULL;
        ListNode* cur=head;
        ListNode* p=NULL;
        while(cur!=NULL){
            cnt++;
            if(cnt==left){
                l=p;
                newhead=cur;
            }
            if(cnt==right){
                r=cur->next;
                cur->next=NULL;
            }
            p=cur;
            cur=cur->next;
        }
        
       ListNode* rev=reverse(newhead);
         if(l!=NULL)
            l->next=rev;
        else
            head=rev;
        if(r!=NULL)
            newhead->next=r;
            
        
        return head;
        
        
    }
};