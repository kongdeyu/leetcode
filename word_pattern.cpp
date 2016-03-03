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
        std::map<std::string, char> word2pattern;
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
                std::map<std::string, char>::const_iterator cit2word = word2pattern.find(cur_word);
                if(cit2pattern == pattern2word.end() && cit2word == word2pattern.end())
                {
                    pattern2word[cur_pattern] = cur_word;
                    word2pattern[cur_word] = cur_pattern;
                }
                else if(cit2pattern != pattern2word.end() && cit2word != word2pattern.end())
                {
                    if(cit2pattern->second != cur_word || cit2word->second != cur_pattern)
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