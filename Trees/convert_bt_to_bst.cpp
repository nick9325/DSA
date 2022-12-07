/* The Node structure is
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
*/

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void store(Node* root,vector<int> &res){
        if(!root) return;
        
        store(root->left,res);
        res.push_back(root->data);
        store(root->right,res);
    }
    void solve(Node* root,vector<int> res,int &i){
        if(!root) return;
        
        solve(root->left,res,i);
        root->data=res[i];
        i++;
        solve(root->right,res,i);
    }
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> res;
        store(root,res);
        sort(res.begin(),res.end());
        int i=0;
        solve(root,res,i);
        
        return root;
        
    }
};