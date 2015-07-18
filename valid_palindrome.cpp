class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
        {
            return true;
        }
        
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        std::string::size_type begin = 0;
        std::string::size_type end = s.size() - 1;
        while(begin < end)
        {
            if(!is_alphanumeric(s[begin]))
            {
                begin++;
                continue;
            }
            if(!is_alphanumeric(s[end]))
            {
                end--;
                continue;
            }
            if(s[begin] != s[end])
            {
                return false;
            }
            begin++;
            end--;
        }
        return true;
    }
    
    bool is_alphanumeric(char ch)
    {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
    }
};