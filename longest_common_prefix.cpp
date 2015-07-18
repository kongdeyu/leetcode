class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string res;
        if(strs.empty())
        {
            return res;
        }
        
        for(std::vector<std::string>::size_type index = 0; index < strs.front().size(); index++)
        {
            char cur = strs.front()[index];
            for(std::vector<std::string>::const_iterator cit2str = strs.begin() + 1; cit2str != strs.end(); cit2str++)
            {
                if(index == cit2str->size() || cur != (*cit2str)[index])
                {
                    return res;
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};