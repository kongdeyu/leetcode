class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty())
        {
            return s;
        }
        
        std::string::iterator begin = s.begin();
        std::string::iterator end = s.end() - 1;
        while(begin < end)
        {
            while(!is_vowel(*begin) && begin < end)
            {
                begin++;
            }
            
            while(!is_vowel(*end) && begin < end)
            {
                end--;
            }
            
            std::swap(*begin, *end);
            begin++;
            end--;
        }
        return s;
    }
    
private:
    bool is_vowel(char ch)
    {
        if(ch == 'a' ||
           ch == 'e' ||
           ch == 'i' ||
           ch == 'o' ||
           ch == 'u' ||
           ch == 'A' ||
           ch == 'E' ||
           ch == 'I' ||
           ch == 'O' ||
           ch == 'U')
        {
            return true;
        }
        
        return false;
    }
    
};