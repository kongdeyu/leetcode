class Solution {
public:
    bool wordPattern(string pattern, string str) {
        size_t fast = 0;
        size_t slow = 0;
        
        while(fast < str.size() && str[fast] == ' ')
        {
            fast++;
            slow++;
        }
        
        size_t idx2pattern = 0;
        std::map<char, std::string> pattern2word;
        std::set<std::string> set_word;
        while(slow < str.size())
        {
            if(str[slow] == ' ')
            {
                fast = ++slow;
            }
            
            if(fast == str.size() || str[fast] == ' ')
            {
                std::string cur_word(str.begin() + slow, str.begin() + fast);
                char cur_pattern = pattern[idx2pattern];
                
                std::map<char, std::string>::const_iterator cit2pattern = pattern2word.find(cur_pattern);
                std::set<std::string>::const_iterator cit2word = set_word.find(cur_word);
                if(cit2pattern == pattern2word.end() && cit2word == set_word.end())
                {
                    pattern2word[cur_pattern] = cur_word;
                    set_word.insert(cur_word);
                }
                else if(cit2pattern != pattern2word.end() && cit2word != set_word.end())
                {
                    if(cit2pattern->second != cur_word)
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
                slow = ++fast;
                idx2pattern++;
            }
            else
            {
                fast++;
            }
            
        }
        return idx2pattern == pattern.size();
    }
};