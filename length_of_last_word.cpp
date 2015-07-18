class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
        {
            return 0;
        }
        
        int res = 0;
        std::string::size_type start = 0;
        std::string::size_type stop = 0;
        while(start < s.size())
        {
            if(s[start] == ' ')
            {
                start++;
                stop++;
                continue;
            }
            
            if(s[stop] == ' ' || stop == s.size())
            {
                res = stop - start;
                start = ++stop;
            }
            else
            {
                stop++;
            }
        }
        return res;
    }
};