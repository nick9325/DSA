class Solution {
public:
    int longestContinuousSubstring(string s) {
        string acss="abcdefghijklmnopqrstuvwxyz";
        
        unordered_map<char,int> m;
        for(int i=0;i<acss.size();i++){
            m[acss[i]]=i;
        }
        
        int i=0,j=1,p=0;
        int ans=INT_MIN;
        while(j<s.length()){
            
            if((s[j-1]==char(acss[m[s[j]]])-1)){
                j++;
            }
            else{
                ans=max(ans,j-i);
                i=j;
                j++;
            }
        }
        
        return max(ans,j-i);
        
    }
};