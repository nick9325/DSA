class Solution {
    
private:
     bool match(vector<int> ch,vector<int> mW){
         for(int i=0;i<ch.size();i++){
             if(ch[i]<mW[i]) return false;
         }
         
         return true;
     }
public:
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> mW(26);
        
        for(auto c:words2){
            vector<int> f(26);
            for(int i=0;i<c.length();i++){
                f[c[i]-'a']++;
            }
            for(int i=0;i<26;i++){
                mW[i]=max(mW[i],f[i]);
            }
        }
        
        vector<string> ans;
        
        for(auto x:words1){
            vector<int> ch(26);
            for(int i=0;i<x.length();i++){
                ch[x[i]-'a']++;
            }
            if(match(ch,mW)){
                ans.push_back(x);
            }
        }
        return ans;
    }
    
};