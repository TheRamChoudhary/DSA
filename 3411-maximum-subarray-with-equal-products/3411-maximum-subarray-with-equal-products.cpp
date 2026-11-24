class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            long long prod = 1;
            int g = 0;
            long long l = 1;

            for (int j = i; j < n; ++j) {
                long long x = nums[j];
                g = std::gcd(g, static_cast<int>(x));
                l = std::lcm(l, x);

                if (prod > LLONG_MAX / x) {
                    break;
                }
                prod *= x;

                if (prod == l * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna