/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */

void solve(Node* root,vector<int> &leafs,vector<int> &in){
    if(!root) return;
    if(!root->left and !root->right){
        leafs.push_back(root->data);
    }
    solve(root->left,leafs,in);
    in.push_back(root->data);
    solve(root->right,leafs,in);
    
}

bool isDeadEnd(Node *root)
{
    vector<int> leafs;
    vector<int> in;
    
    solve(root,leafs,in);
    
    for(auto x:leafs){
        if(x==1){
            if(binary_search(in.begin(),in.end(),x+1)){
                return true;
            }
        }
        if(binary_search(in.begin(),in.end(),x+1) and binary_search(in.begin(),in.end(),x-1)){
            return true;
        }
        
    }
    
    return false;
}