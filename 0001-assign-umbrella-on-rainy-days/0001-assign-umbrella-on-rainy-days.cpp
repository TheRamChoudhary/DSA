class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n=rain.size(),a=0,b=0;
        vector<string>ans(n,"None");
        for(int i=0;i<n;i++){
            if(!rain[i]) continue;
            bool alice=(i+1<n && rain[i+1]);
            ans[i]=(alice && a<=b) ? (++a,"Alice") : (++b,"Bob");
        }
        return ans;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna