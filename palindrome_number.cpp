class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        
        int module = 1;
        while(x / module >= 10)
        {
            module *= 10;
        }
        
        while(x > 0)
        {
            int digit_low = x % 10;
            int digit_high = x / module;
            if(digit_low != digit_high)
            {
                return false;
            }
            x = x % module / 10;
            module /= 100;
        }
        return true;
    }
};