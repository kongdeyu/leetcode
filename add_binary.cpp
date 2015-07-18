class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty() || b.empty())
        {
            return "0";
        }
        
        std::string res(std::max(a.size(), b.size()) + 1, '0');
        std::string::reverse_iterator rit2a = a.rbegin();
        std::string::reverse_iterator rit2b = b.rbegin();
        char carry = 0;
        std::string::size_type idx = res.size() - 1;
        while(rit2a != a.rend() && rit2b != b.rend())
        {
            char temp = (*rit2a - '0') + (*rit2b - '0') + carry;
            res[idx--] = temp % 2 + '0';
            carry = temp / 2;
            rit2a++;
            rit2b++;
        }
        
        while(rit2a != a.rend())
        {
            char temp = (*rit2a - '0') + carry;
            res[idx--] = temp % 2 + '0';
            carry = temp / 2;
            rit2a++;
        }
        
        while(rit2b != b.rend())
        {
            char temp = (*rit2b - '0') + carry;
            res[idx--] = temp % 2 + '0';
            carry = temp / 2;
            rit2b++;
        }
        
        if(carry == 1)
        {
            res[idx] = carry + '0';
        }
        
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
};