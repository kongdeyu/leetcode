class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
        {
            return 0;
        }
        
        int b = std::max(-prices[0], -prices[1]);
        int s1 = 0;
        int s2 = std::max(0, prices[1] - prices[0]);
        for(size_t i = 2; i < prices.size(); i++)
        {
            int b_new = std::max(b, s1 - prices[i]);
            int s2_new = std::max(s2, b + prices[i]);
            b = b_new;
            s1 = s2;
            s2 = s2_new;
        }
        return s2;
    }
    
};