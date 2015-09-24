class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        
        int max_profit = 0;
        int i = 1;
        int j = 1;
        while(true)
        {
            int cur_profit = 0;
            while(i < prices.size())
            {
                if(prices[i] > prices[i - 1])
                {
                    j = i;
                    break;
                }
                
                i++;
            }
            
            if(i == prices.size())
            {
                return max_profit;
            }
            
            while(j < prices.size())
            {
                if(prices[j] < prices[j - 1])
                {
                    i = j;
                    break;
                }
                
                cur_profit = prices[j] - prices[i - 1];
                j++;
            }
            
            max_profit += cur_profit;
            
            if(j == prices.size())
            {
                return max_profit;
            }
        }
    }
    
};