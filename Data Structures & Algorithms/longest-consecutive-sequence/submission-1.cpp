class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>st;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            int need = nums[i] - 1;
            st[nums[i]] = st[need] + 1;
            ans = max(ans,st[nums[i]]);
            
        }
        return ans;
    }
};
