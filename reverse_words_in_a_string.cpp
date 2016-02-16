class Solution {
public:
    void reverseWords(string &s) {
        if(s.empty())
        {
            return;
        }
        
        std::string::iterator it = s.begin();
        while(it != s.end() && *it == ' ')
        {
            it++;
        }
        if(it == s.end())
        {
            s.clear();
            return;
        }
        s.erase(s.begin(), it);
        
        std::string::iterator it2fast = s.begin();
        std::string::iterator it2slow = s.begin();
        while(it2fast != s.end())
        {
            if(*it2fast != ' ')
            {
                *it2slow = *it2fast;
                it2slow++;
                it2fast++;
                continue;
            }
            *it2slow++ = ' ';
            
            while(it2fast != s.end() && *it2fast == ' ')
            {
                it2fast++;
            }
        }
        if(*(it2slow - 1) == ' ')
        {
            s.erase(it2slow - 1, s.end());
        }
        else
        {
            s.erase(it2slow, s.end());
        }
        
        it2fast = s.begin();
        it2slow = s.begin();
        while(it2slow != s.end())
        {
            if(*it2slow == ' ')
            {
                it2slow++;
                continue;
            }
            
            if(it2fast == s.end() || *it2fast == ' ')
            {
                std::reverse(it2slow, it2fast);
                it2slow = it2fast++;
            }
            else
            {
                it2fast++;
            }
        }
        std::reverse(s.begin(), s.end());
    }
};