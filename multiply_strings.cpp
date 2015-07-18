class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())
        {
            return "0";
        }
        
        num1 = filter(num1);
        num2 = filter(num2);
        
        bool is_negative = false;
        if(num1.front() == '-')
        {
            is_negative = true;
            num1.erase(num1.begin());
        }
        
        if(is_negative && num2.front() == '-')
        {
            is_negative = false;
            num2.erase(num2.begin());
        }
        else if(!is_negative && num2.front() == '-')
        {
            is_negative = true;
            num2.erase(num2.begin());
        }
        
        std::reverse(num1.begin(), num1.end());
        std::reverse(num2.begin(), num2.end());
        std::string res(num1.size() + num2.size() + 1, '0');
        for(std::string::size_type i = 0; i < num1.size(); i++)
        {
            int32_t digit1 = num1[i] - '0';
            int32_t carry = 0;
            std::string::size_type j = 0;
            for(; j < num2.size(); j++)
            {
                int32_t digit2 = num2[j] - '0';
                int32_t exit = res[i + j] - '0';
                int32_t temp = digit1 * digit2 + exit + carry;
                carry = temp / 10;
                res[i + j] = '0' + (temp % 10);
            }
            
            if(carry > 0)
            {
                res[i + j] = '0' + carry;
            }
        }
        
        std::reverse(res.begin(), res.end());
        std::string::const_iterator cit = res.begin();
        for(; cit != res.end(); cit++)
        {
            if(*cit != '0')
            {
                break;
            }
        }
        
        if(cit == res.end())
        {
            return "0";
        }
        
        return res.substr(cit - res.begin(), res.end() - cit);
    }
    
    std::string filter(const std::string &num)
    {
        std::string::const_iterator begin = num.begin();
        for(; begin != num.end(); begin++)
        {
            if(*begin == '-' || *begin == '+' || (*begin >= '0' && *begin <= '9'))
            {
                break;
            }
        }
        
        if(begin == num.end())
        {
            return "0";
        }
        
        if(*begin == '+')
        {
            begin++;
        }
        
        std::string::const_iterator end = begin;
        if(*end == '-')
        {
            end++;
        }
        for(; end != num.end(); end++)
        {
            if(*end < '0' || *end > '9')
            {
                break;
            }
        }
        
        if(end == begin || (end - begin == 1 && *begin == '-'))
        {
            return "0";
        }
        
        return std::string(begin, end);
    }
};