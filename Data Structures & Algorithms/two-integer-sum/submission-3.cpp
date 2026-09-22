class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        mp[nums[0]] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp[need] != 0) {
                return {mp[need]-1 , i};
            }
           
                mp[nums[i]] = i+1;
            
        }
        return {};
    }
};
