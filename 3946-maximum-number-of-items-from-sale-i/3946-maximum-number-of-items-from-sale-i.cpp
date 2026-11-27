class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        vector<int> dp(budget + 1, 0);
        int minPrice = INT_MAX;

        for (const auto& item : items) {
            int factor = item[0];
            int price = item[1];
            minPrice = min(minPrice, price);

            int gain = 0;
            for (const auto& other : items) {
                if (other[0] % factor == 0) {
                    ++gain;
                }
            }

            // 0/1 knapsack: apply first-purchase bonus at most once per item type
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        int ans = 0;
        for (int spent = 0; spent <= budget; ++spent) {
            int extraCopies = (budget - spent) / minPrice;
            ans = max(ans, dp[spent] + extraCopies);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna