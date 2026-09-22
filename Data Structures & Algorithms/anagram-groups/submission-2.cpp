class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,int>mp;
       vector<vector<string>>ans;
       int id = 0;
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            vector<int>count(26,0);
            for(int j = 0; j < s.size(); j++){
                count[s[j]-'a']++;
            }
            string key = "";
            for(int x : count){
                key += to_string(x) + "#";
            }
            // cout<<key<<endl;
            if(mp.find(key) == mp.end()){
                mp[key]  = id++;
                ans.push_back({ s });
            }else{
                int idx = mp[key];
                ans[idx].push_back(s);
            }
        }
        return ans;
    }
};
