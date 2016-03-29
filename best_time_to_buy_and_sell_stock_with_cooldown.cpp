class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
        {
            return 0;
        }
        
        int b = -prices[0];
        int no_op = -prices[0];
        int s = 0;
        int cooldown = 0;
        for(size_t idx = 1; idx < prices.size(); idx++)
        {
            no_op = std::max(no_op, b);
            b = cooldown - prices[idx];
            cooldown = std::max(cooldown, s);
            s = no_op + prices[idx];
        }
        return std::max(s, cooldown);
    }
    
};