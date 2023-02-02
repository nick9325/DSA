class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int> m;

        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
    
        for(int i=0;i<words.size()-1;i++){
            string cur=words[i];
            string nxt=words[i+1];

            int len=min(cur.length(),nxt.length());

            if(len==nxt.length() and cur.length()>nxt.length() and cur.substr(0,nxt.length())==nxt) return false;

            for(int i=0;i<len;i++){
                if(m[nxt[i]]<m[cur[i]]) return false;
                if(m[nxt[i]]>m[cur[i]]) break;
            }
        }

        return true;
    }
};