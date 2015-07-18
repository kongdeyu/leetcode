class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int pre_digit = 0;
        for(std::string::const_iterator cit = s.begin(); cit != s.end(); cit++)
        {
            int cur_digit = get_num(*cit);
            if(cur_digit > pre_digit)
            {
                res -= (pre_digit * 2 - cur_digit);
            }
            else
            {
                res += cur_digit;
            }
            pre_digit = cur_digit;
        }
        return res;
    }
    
    int get_num(char ch)
    {
        switch(ch)
        {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};