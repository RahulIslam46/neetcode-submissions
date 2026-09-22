class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mn = 1e9;
        for(int i = 0; i < strs.size(); i++){
            mn = min(mn,(int)strs[i].size());
        }
        string ans ="";
        for(int idex = 0; idex < mn; idex++){
            char temp = strs[0][idex];
            for(int j = 1; j < strs.size(); j++){
                
                if(temp != strs[j][idex]){
                    return ans;
                }
            }
            ans+=temp;
        }
        return ans;
        
    }
};