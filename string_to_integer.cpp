class Solution {
public:
    int myAtoi(string str) {
        if(str.empty())
        {
            return 0;
        }
        
        // find first digit not 0
        std::string::const_iterator cit = str.begin();
        for(; cit != str.end(); cit++)
        {
            if(*cit != ' ')
            {
                break;
            }
        }
        
        bool is_negative = false;
        if(*cit == '+')
        {
            cit++;
        }
        else if(*cit == '-')
        {
            cit++;
            is_negative = true;
        }
        
        long res = 0;
        for(; cit != str.end(); cit++)
        {
            if(!is_digit(*cit))
            {
                break;
            }
            
            if(is_negative)
            {
                res = res * 10 - (*cit - '0');
            }
            else
            {
                res = res * 10 + (*cit - '0');
            }
            
            if(res < INT_MIN)
            {
                return INT_MIN;
            }
            
            if(res > INT_MAX)
            {
                return INT_MAX;
            }
        }
        
        return res;
    }
    
    bool is_digit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
};
