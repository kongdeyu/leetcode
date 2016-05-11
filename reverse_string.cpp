class Solution {
public:
    string reverseString(string s) {
        if(s.empty())
        {
            return s;
        }
        
        std::string::iterator begin = s.begin();
        std::string::iterator end = s.end() - 1;
        while(begin < end)
        {
            std::swap(*begin, *end);
            begin++;
            end--;
        }
        return s;
    }
    
};