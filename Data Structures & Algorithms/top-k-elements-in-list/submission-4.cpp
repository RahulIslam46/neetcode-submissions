class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        int n = nums.size();
        vector<vector<int>> backet(n + 1);
        for (auto [a, b] : mp) {
            backet[b].push_back(a);
        }

        vector<int> ans;
        for (int i = n; i >= 0; i--) {
            for (auto a : backet[i]) {
                ans.push_back(a);
                k--;

                if (k == 0) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
