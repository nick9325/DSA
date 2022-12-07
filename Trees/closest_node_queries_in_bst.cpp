class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &v){
        if(!root) return;

        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        vector<int> v;
        inorder(root,v);
        TreeNode* n=root;
        int min=0,max=0;
        for(int i=0;i<queries.size();i++){
            int ans=lower_bound(v.begin(),v.end(),queries[i])-v.begin();

            if(ans>=0 and ans<v.size()){
                if(v[ans]==queries[i]){
                    res.push_back({v[ans],v[ans]});
                }
                else if(ans==0){
                    res.push_back({-1,v[ans]});
                }
                else if(ans>0){
                    res.push_back({v[ans-1],v[ans]});
                }
            }
            else{
                res.push_back({v[v.size()-1],-1});
            }

        }
        
        return res;
    }
};