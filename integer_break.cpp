class Solution {
public:
    int integerBreak(int n) {
        assert(n > 1);
        
        int quotient = n / 3;
        if(quotient <= 1)
        {
            return n / 2 * (n / 2 + n % 2);
        }
        
        int remainder = n % 3;
        if(remainder == 0)
        {
            return pow(3, quotient);
        }
        
        if(remainder == 1)
        {
            return pow(3, quotient - 1) * 4;
        }
        
        // remainder == 2
        return pow(3, quotient) * 2;
    }
};