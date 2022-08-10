class Solution
{
public:
    void populateNext(Node *root,Node* &p)
    {
        if(!root) return;
        
        populateNext(root->left,p);
        if(p!=NULL)
            p->next=root;
        p=root;
        populateNext(root->right,p);
        
    }
    void populateNext(Node *root)
    {   
        Node* p=NULL;
        populateNext(root,p);
        
    }
};