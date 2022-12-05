class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum=0;
        
        if(skill.size()==2) return skill[0]*skill[1];
        
        for(int i=0;i<skill.size();i++){
            sum+=skill[i];
        }
        
        
        int nbt=skill.size()/2;
        
        sort(skill.begin(),skill.end());
        
        int k=sum/nbt;
        
        int i=0,j=skill.size()-1;
        long long chem=0;
        
        while(i<j){
            
            
            if(skill[i]+skill[j]!=k) return -1;
            chem+=skill[i]*skill[j];
            i++;
            j--;
            
        }
        
        return chem;
        
        
        
    
    }
};