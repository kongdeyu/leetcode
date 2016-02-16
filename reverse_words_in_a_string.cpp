class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
        {
            return;
        }
        
        std::string res;
        int32_t idx2fast = s.size() - 1;
        int32_t idx2slow = s.size() - 1;
        while(idx2slow >= 0)
        {
            if(s[idx2slow] == ' ')
            {
                idx2slow--;
                idx2fast--;
                continue;
            }
            
            if(idx2fast == -1 || s[idx2fast] == ' ')
            {
                if(res.size())
                {
                    res.push_back(' ');
                }
                res.append(std::string(s, idx2fast + 1, idx2slow - idx2fast));
                idx2slow = idx2fast;
            }
            
            idx2fast--;
        }
        s = res;
    }
};