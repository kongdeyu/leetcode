class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for(std::string::const_iterator cit = s.begin(); cit != s.end(); cit++)
        {
            int digit = *cit - 'A' + 1;
            res = res * 26 + digit;
        }
        return res;
    }
};