class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum  = 0;
        for(int i = 1; i < n; i++)
        {
            sum += (prices[i] - prices[i - 1]) > 0 ? (prices[i] - prices[i - 1]) : 0;
        }
        return sum;
    }
};