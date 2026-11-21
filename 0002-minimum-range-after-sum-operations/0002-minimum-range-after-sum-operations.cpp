class Solution {
public:
    int minRange(int a, int b, int c) {
        vector<int>temp={a,b,c};
        sort(temp.begin(),temp.end());
        int x=temp[0],y=temp[1],z=temp[2];
        int ans=z-x;
        ans=min(ans,max(z,x+y)-y);
        ans=min(ans,z);
        ans=min(ans,(x+z)-x);
        ans=min(ans,(x+y)-x);
        return min({z-x,y});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna