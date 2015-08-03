class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
        {
            return false;
        }
        
        std::vector<int32_t> dict(26, 0);
        for(std::string::const_iterator cit = s.begin(); cit != s.end(); cit++)
        {
            dict[*cit - 'a']++;
        }
        
        for(std::string::const_iterator cit = t.begin(); cit != t.end(); cit++)
        {
            if(dict[*cit - 'a']-- == 0)
            {
                return false;
            }
        }
        return true;
    }
};