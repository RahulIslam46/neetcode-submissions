class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum = 0;
        int ans  = 0;
        mp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum +=nums[i];
            int need = sum - k;
            if(mp.find(need)!= mp.end()){
                ans += mp[need];
            }
            mp[sum]++;
        }
        return ans;
    }
};