class Solution {
public:
    bool wordPattern(string pattern, string s) {
        if(pattern.size()==1 and s.size()==1) return true;
        if(pattern==s) return false;
        unordered_map<string,char> mp;  
        unordered_map<char,int> m;    
        int k=0;
        string word="";
        for(int i=0;i<s.length();i++){
            while(s[i]!=' ' and i<s.length()){
                word+=s[i];
                i++;
            }
            if(s[i]==' '){
                if(mp.find(word)==mp.end()){
                    if(m.find(pattern[k])!=m.end()) return false;
                    mp[word]=pattern[k];
                    m[pattern[k]]++;
                }
                if(mp.find(word)==mp.end() or mp[word]!=pattern[k]) return false;
                k++;
                word="";
            }
        }
        if(mp.find(word)==mp.end()){
            if(m.find(pattern[k])!=m.end()) return false;
            mp[word]=pattern[k];
        }
        if(mp.find(word)==mp.end() or mp[word]!=pattern[k]) return false;
        k++;
        if(k!=pattern.size()) return false;
      

        return true;
        
    }
};