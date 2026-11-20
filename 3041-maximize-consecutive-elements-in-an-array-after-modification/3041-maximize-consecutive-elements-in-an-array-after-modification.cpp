class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.back() + 2,0); 
        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;  
            dp[x] = dp[x - 1] + 1;  
        }
        return *max_element(dp.begin(),dp.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna