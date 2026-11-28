
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int cheapest = INT_MAX;

        for (auto &item : items) {
            freq[item[0]]++;
            cheapest = min(cheapest, item[1]);
        }

        vector<int> cnt(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }
           cnt[i]--;
        }

        vector<pair<int, int>> offers;

        for (auto &item : items) {
            int factor = item[0];
            int price = item[1];

            if (cnt[factor] > 0 &&
                price < 2LL * cheapest) {

                offers.push_back({price, cnt[factor]});
            }
        }

        sort(offers.begin(), offers.end());

        long long ans = 0;
        long long remaining = budget;

        for (auto &[price, count] : offers) {

            long long buy = min(
                (long long)count,
                remaining / price
            );

            ans += buy * 2;
            remaining -= buy * price;
        }

        ans += remaining / cheapest;

        return (int)ans;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna