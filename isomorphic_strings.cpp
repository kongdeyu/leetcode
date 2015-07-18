class Solution {
public:
    bool isIsomorphic(string s, string t) {
        assert(s.size() == t.size());
        std::vector<char> dic_s2t(128, -1);
        std::vector<char> dic_t2s(128, -1);
        for(std::string::size_type idx = 0; idx < s.size(); idx++)
        {
            char digit_in_s = s[idx];
            char digit_in_t = t[idx];
            if(dic_s2t[digit_in_s] == -1 && dic_t2s[digit_in_t] == -1)
            {
                dic_s2t[digit_in_s] = digit_in_t;
                dic_t2s[digit_in_t] = digit_in_s;
            }
            if(dic_s2t[digit_in_s] != digit_in_t || dic_t2s[digit_in_t] != digit_in_s)
            {
                return false;
            }
        }
        return true;
    }
};