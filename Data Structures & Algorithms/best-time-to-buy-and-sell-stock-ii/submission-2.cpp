class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n+1][3];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1e9;
            }
        }
        auto f = [&](auto&& self, int i, int have) -> int {
            if (i == n) return 0;
            if (dp[i][have] != -1e9) return dp[i][have];
            int ans = 0;

            if (have) {
                ans = max(ans, prices[i] + self(self, i + 1, 0));
            }

            ans = max(ans, self(self, i + 1, have));

            if (!have) {
                ans = max(ans, -prices[i] + self(self, i + 1, 1));
            }
            dp[i][have] = ans;
            return ans;
        };

        return f(f, 0, 0);
    }
};