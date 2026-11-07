class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!st.count(nums[i] - 1)) {
                int num = nums[i];
                int cnt = 1;
                while (st.count(num + 1)) {
                    num++;
                    cnt++;
                }
                ans = max(cnt, ans);
            }
        }

        return ans;
    }
};
