class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + nums[i];

        const long long INF = 1e18;

        vector<vector<long long>> dp(n + 1,
                                     vector<long long>(m + 1, INF));

        dp[0][0] = 0;

        for (int k = 1; k <= m; k++) {
            for (int i = 1; i <= n; i++) {

                for (int j = 0; j < i; j++) {
                    if (dp[j][k - 1] == INF) continue;

                    long long lastSum = prefix[i] - prefix[j];

                    dp[i][k] = min(dp[i][k],
                                   max(dp[j][k - 1], lastSum));
                }
            }
        }

        return dp[n][m];
    }
};