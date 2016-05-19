class Solution {
public:
    int integerBreak(int n) {
        assert(n > 1);
        
        int res = 0;
        for(int i = 2; i <= n; i++)
        {
            int quotient = n / i;
            int remainder = n % i;
            int cur_product = pow(quotient, i - remainder) * pow(quotient + 1, remainder);
            if(cur_product > res)
            {
                res = cur_product;
            }
        }
        return res;
    }
};