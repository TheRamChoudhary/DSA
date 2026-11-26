class Solution {
public:
    bool canAliceWin(int n) {
        bool win=false;
        for(int i=10;i>=0;i--){
            if(n-i<0) {
                break;
            }
            n=n-i;
            win=!win;  
        }
        return win;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna