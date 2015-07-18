class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
        {
            return 0;
        }
        
        if(haystack.size() < needle.size())
        {
            return -1;
        }
        
        for(std::string::const_iterator cit = haystack.begin(); cit != haystack.end() - needle.size() + 1; cit++)
        {
            std::string::size_type idx = 0;
            for(; idx < needle.size(); idx++)
            {
                if(cit + idx == haystack.end() || *(cit + idx) != needle[idx])
                {
                    break;
                }
            }
            
            if(idx == needle.size())
            {
                return cit - haystack.begin();
            }
        }
        return -1;
    }
};