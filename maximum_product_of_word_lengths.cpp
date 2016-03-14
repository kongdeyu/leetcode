class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())
        {
            return 0;
        }
        
        int res = 0;
        for(size_t idx2fst = 0; idx2fst < words.size() - 1; idx2fst++)
        {
            std::string cur_word = words[idx2fst];
            std::vector<bool> vec_bits(128, false);
            for(std::string::const_iterator cit = cur_word.begin(); cit != cur_word.end(); cit++)
            {
                vec_bits[*cit] = true;
            }
            
            for(size_t idx2snd = idx2fst + 1; idx2snd < words.size(); idx2snd++)
            {
                std::string sub_word = words[idx2snd];
                if(res >= cur_word.size() * sub_word.size())
                {
                    continue;
                }
                
                bool is_conflict = false;
                for(std::string::const_iterator cit = sub_word.begin(); cit != sub_word.end(); cit++)
                {
                    char ch = *cit;
                    if(vec_bits[ch])
                    {
                        is_conflict = true;
                        break;
                    }
                }
                
                if(!is_conflict)
                {
                    res = cur_word.size() * sub_word.size();
                }
            }
        }
        
        return res;
    }
    
};