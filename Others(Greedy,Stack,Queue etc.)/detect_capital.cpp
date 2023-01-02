class Solution {
public:
    bool detectCapitalUse(string word) {

        if(word.size()==1) return true;
        
        if(word[0]>='A' and word[0]<='Z' and word[1]>='A' and word[1]<='Z'){
            for(int i=2;i<word.size();i++){
                if(word[i]>'Z') return false;
            }
        }
        else if((word[0]>='A' and word[0]<='Z') or (word[0]>='a' and word[0]<='z')){
             for(int i=1;i<word.size();i++){
                if(word[i]<='Z') return false;
            }
        }

        return true;

    }
};