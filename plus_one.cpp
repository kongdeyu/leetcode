class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.empty())
        {
            return digits;
        }
        
        int carry = 1;
        for(std::vector<int>::reverse_iterator rit = digits.rbegin(); rit != digits.rend(); rit++)
        {
            int digit = *rit + carry;
            if(digit == 10)
            {
                carry = 1;
                *rit = 0;
            }
            else
            {
                carry = 0;
                *rit = digit;
            }
        }
        if(carry == 1)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};